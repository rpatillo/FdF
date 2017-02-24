/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 17:34:37 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/04 16:55:46 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	exit_error(int i)
{
	if (i == 1)
		ft_putendl("Malloc error.");
	exit(0);
}

void	keys(void)
{
	ft_putendl("\nUse this keys to interact :\nPAV NUM :\n");
	ft_putendl("6/9 to zoom in/out.");
	ft_putendl("0 to reverse.");
	ft_putendl("+/- to increase the scale.\n\nUse arrows to move.");
}
