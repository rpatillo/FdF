/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:24:29 by rpatillo          #+#    #+#             */
/*   Updated: 2014/11/19 11:07:05 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cpy;

	cpy = (char *)malloc(sizeof(*cpy) * len);
	if (cpy == NULL)
		return (NULL);
	cpy = ft_memcpy(cpy, src, len);
	dst = ft_memcpy(dst, cpy, len);
	free(cpy);
	return (dst);
}
