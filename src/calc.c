/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 16:57:27 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/04 14:25:26 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	ft_recalc(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->map->len)
	{
		j = 0;
		while (j < e->map->line[i]->len)
		{
			e->map->line[i]->point[j][0].rx = 0.707 * \
				((e->map->line[i]->point[j][0].x * e->s) - \
				(e->map->line[i]->point[j][0].y * e->s)) + e->x;
			e->map->line[i]->point[j][0].ry = 0.816 * \
				(e->map->line[i]->point[j][0].z * e->height) + 0.408 * \
				((e->map->line[i]->point[j][0].x * e->s) + \
				(e->map->line[i]->point[j][0].y * e->s)) + e->y;
			j++;
		}
		i++;
	}
}
