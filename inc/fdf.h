/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 12:26:31 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/08 10:10:26 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx_macos/mlx.h"
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"
# include "struct.h"

# define SCALE 50
# define WIDTH 1000
# define HEIGHT 1000
# define H_SIZE 50
# define W_SIZE 50
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 69
# define MINUS 78
# define PSCALE 88
# define MSCALE 92
# define ZERO 82
# define ESC 53
# define MAJ 257

void	ft_recalc(t_env *e);
void	pixel_put_to_image(unsigned long img_color, t_env *e, int x, int y);
int		draw_choice(t_env *e, t_points p1, t_points p2);
int		draw_horiz(t_env *e, t_points p1, t_points p2);
int		draw_verti(t_env *e, t_points p1, t_points p2);
int		ft_cntline(char *map);
int		ft_getpoints(char *line, int nbline, t_points ***tmp_pt, t_env e);
void	draw_map(t_map *map, t_env *e);
t_map	*ft_parse(char **parse, t_env e, int fd);
int		get_expose(t_env *e);
void	exit_error(int i);
void	keys();

#endif
