/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:00:30 by rpatillo          #+#    #+#             */
/*   Updated: 2014/11/16 14:33:02 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cpy1;
	unsigned char	*cpy2;

	if (n == 0)
		return (0);
	i = 0;
	cpy1 = (unsigned char *)s1;
	cpy2 = (unsigned char *)s2;
	while (cpy1[i] != '\0' && cpy2[i] != '\0' && cpy1[i] == cpy2[i] && --n > 0)
		i++;
	return (cpy1[i] - cpy2[i]);
}
