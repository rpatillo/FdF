/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:13:24 by rpatillo          #+#    #+#             */
/*   Updated: 2014/11/09 14:25:25 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char*)s2);
	if (!*s2)
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == *s2)
		{
			if (ft_strncmp((char *)s1 + i, (char*)s2, len) == 0)
				return ((char*)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
