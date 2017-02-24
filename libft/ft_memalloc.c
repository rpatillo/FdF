/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:59:11 by rpatillo          #+#    #+#             */
/*   Updated: 2014/11/22 15:10:27 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;
	char	*explo;

	if (size == 0)
		return (NULL);
	i = 0;
	mem = malloc(size);
	if (mem != NULL)
	{
		explo = (char *)mem;
		while (i++ < size)
			*explo++ = 0;
	}
	return (mem);
}
