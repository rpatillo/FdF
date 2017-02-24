/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 10:36:24 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/08 10:19:54 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

int		key_hook(int keycode, t_env *e)
{
	(keycode == ESC) ? exit(0) : keycode;
	(keycode == UP) ? e->y -= 25 : keycode;
	(keycode == DOWN) ? e->y += 25 : keycode;
	(keycode == LEFT) ? e->x -= 25 : keycode;
	(keycode == RIGHT) ? e->x += 25 : keycode;
	(keycode == PLUS) ? e->height -= 1 : keycode;
	(keycode == MINUS) ? e->height += 1 : keycode;
	(keycode == ZERO) ? e->s = -e->s : keycode;
	(keycode == PSCALE) ? e->s += 1 : keycode;
	if ((keycode == MSCALE) && e->s > 1)
		e->s -= 1;
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	ft_recalc(e);
	draw_map(e->map, e);
	get_expose(e);
	return (0);
}

int		get_expose(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;
	int		cline;
	int		fd;

	if (ac != 2)
	{
		ft_putstr("Please, choose a map in ./maps/\n");
		return (0);
	}
	keys();
	e.x = 400;
	e.y = 400;
	e.height = -4;
	e.s = 50;
	e.map = ft_parse(av, e, fd);
	e.mlx = mlx_init();
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "FdF");
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sline, &e.endian);
	draw_map(e.map, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, &get_expose, &e);
	mlx_loop(e.mlx);
	return (0);
}
