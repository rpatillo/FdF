/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 09:45:56 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/08 09:54:42 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "fdf.h"

typedef	struct	s_points
{
	double		x;
	double		y;
	double		z;
	double		rx;
	double		ry;
}				t_points;

typedef	struct	s_line
{
	t_points	**point;
	int			len;
}				t_line;

typedef struct	s_map
{
	t_line		**line;
	int			len;
}				t_map;

typedef	struct	s_env
{
	t_map		*map;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sline;
	int			endian;
	int			x;
	int			y;
	int			height;
	int			s;
	int			color;
}				t_env;

#endif
