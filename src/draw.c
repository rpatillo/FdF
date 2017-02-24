/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 14:39:38 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/04 16:52:44 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iso projection
** x' = 0.707 * (x - y)
** y' = 0.816 * z - 0.408 * (x + y)
*/

#include "../inc/FdF.h"

void	pixel_put_to_image(unsigned long img_color, t_env *e, int x, int y)
{
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		color1 = (img_color & 0xFF0000) >> 16;
		color2 = (img_color & 0xFF00) >> 8;
		color3 = (img_color & 0xFF);
		e->data[y * e->sline + x * e->bpp / 8] = color3;
		e->data[y * e->sline + x * e->bpp / 8 + 1] = color2;
		e->data[y * e->sline + x * e->bpp / 8 + 2] = color1;
	}
}

int		draw_choice(t_env *e, t_points p1, t_points p2)
{
	if (fabs(p1.rx - p2.rx) >= fabs(p1.ry - p2.ry))
	{
		if (p1.z > 0)
			e->color = 0xFF0000;
		else if (p1.z < 0)
			e->color = 0x00FF00;
		else if (p1.z == 0)
			e->color = 0x0000FF;
		draw_horiz(e, p1, p2);
	}
	else
	{
		if (p1.z > 0)
			e->color = 0xFF0000;
		else if (p1.z < 0)
			e->color = 0x00FF00;
		else if (p1.z == 0)
			e->color = 0x0000FF;
		draw_verti(e, p1, p2);
	}
	return (0);
}

int		draw_horiz(t_env *e, t_points p1, t_points p2)
{
	int		x;

	x = 0;
	if ((p1.rx - p2.rx) <= 0)
	{
		x = p1.rx - 1;
		while (++x < p2.rx)
		{
			pixel_put_to_image(e->color, e, x, p1.ry + \
				((p2.ry - p1.ry) * (x - p1.rx))	\
				/ (p2.rx - p1.rx));
		}
	}
	else
	{
		x = p2.rx - 1;
		while (++x < p1.rx)
		{
			pixel_put_to_image(e->color, e, x, p2.ry + \
				((p1.ry - p2.ry) * (x - p2.rx)) \
				/ (p1.rx - p2.rx));
		}
	}
	return (0);
}

int		draw_verti(t_env *e, t_points p1, t_points p2)
{
	int		y;

	y = 0;
	if ((p1.ry - p2.ry) <= 0)
	{
		y = p1.ry - 1;
		while (++y < p2.ry)
		{
			pixel_put_to_image(e->color, e, p1.rx + \
				((p2.rx - p1.rx) * (y - p1.ry)) \
				/ (p2.ry - p1.ry), y);
		}
	}
	else
	{
		y = p2.ry - 1;
		while (++y < p1.ry)
		{
			pixel_put_to_image(e->color, e, p1.rx + \
				((p2.rx - p1.rx) * (y - p1.ry)) \
				/ (p2.ry - p1.ry), y);
		}
	}
	return (0);
}

void	draw_map(t_map *map, t_env *e)
{
	int		i;
	int		j;
	int		size;

	i = -1;
	while (++i < map->len)
	{
		j = -1;
		while ((++j + 1) < map->line[i]->len)
			draw_choice(e, map->line[i]->point[j][0], \
						map->line[i]->point[j + 1][0]);
	}
	i = -1;
	j = -1;
	while ((++i + 1) < map->len)
	{
		if (map->line[i]->len > map->line[i + 1]->len)
			size = map->line[i + 1]->len;
		else
			size = map->line[i]->len;
		j = -1;
		while (++j < size)
			draw_choice(e, map->line[i]->point[j][0], \
						map->line[i + 1]->point[j][0]);
	}
}
