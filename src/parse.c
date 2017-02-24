/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 14:19:17 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/03 16:12:07 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

int		ft_cntline(char *map)
{
	int			fd;
	int			cnt;
	char		buf;

	cnt = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
	{
		ft_putstr("No map, empty window.");
		return (0);
	}
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			cnt++;
	}
	close(fd);
	return (cnt);
}

int		ft_getpoints(char *line, int nbline, t_points ***tmp_pt, t_env e)
{
	int			i;
	char		**str;
	t_points	*point;

	str = ft_strsplit(line, ' ');
	i = 0;
	while (str[i] != 0)
		i++;
	if (!((*tmp_pt) = (t_points **)malloc(sizeof(t_points) * i)))
		exit_error(1);
	i = 0;
	while (str[i] != 0)
	{
		point = (t_points *)malloc(sizeof(t_points));
		point->x = i;
		point->y = nbline;
		point->z = ft_atoi(str[i]);
		point->rx = (0.707 * ((point->x * e.s) - (point->y * e.s)) + e.x);
		point->ry = (0.816 * (point->z * e.height) + 0.408 *
					((point->x * e.s) + (point->y * e.s)) + e.y);
		(*tmp_pt)[i] = point;
		i++;
	}
	return (i);
}

t_map	*ft_parse(char **parse, t_env e, int fd)
{
	int			i;
	t_map		*map;
	t_line		*line_map;
	char		*line;
	t_points	**tmp_pt;

	i = -1;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit_error(1);
	if (!(map->line = (t_line **)malloc(sizeof(t_line) *
										(map->len = ft_cntline(parse[1])))))
		exit_error(1);
	if ((fd = open(parse[1], O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			if (!(line_map = (t_line *)malloc(sizeof(t_line))))
				exit_error(1);
			line_map->len = ft_getpoints(line, ++i, &tmp_pt, e);
			line_map->point = tmp_pt;
			map->line[i] = line_map;
		}
		map->len = i + 1;
	}
	return (map);
}
