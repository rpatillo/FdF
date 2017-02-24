/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:40:13 by rpatillo          #+#    #+#             */
/*   Updated: 2014/11/19 12:30:44 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s2 == 0)
		return ((char *)s1);
	if (len_s1 < n)
		n = len_s1;
	while ((len_s2 + i) < (n + 1))
	{
		if (s1[i] == s2[0])
		{
			if (ft_strncmp((s1 + i), s2, len_s2) == 0)
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
