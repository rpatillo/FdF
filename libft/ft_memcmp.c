/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:17:09 by rpatillo          #+#    #+#             */
/*   Updated: 2014/11/19 11:04:51 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*t1;
	unsigned char		*t2;

	if (n == 0)
		return (0);
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (*t1 == *t2 && --n > 0)
	{
		t1++;
		t2++;
	}
	return (*t1 - *t2);
}
