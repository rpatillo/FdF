/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:47:05 by rpatillo          #+#    #+#             */
/*   Updated: 2014/12/11 14:49:21 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_mallocat(char *s1, char *s2)
{
	unsigned int		len1;
	unsigned int		len2;
	char				*tmp;

	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tmp = NULL;
	tmp = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!tmp)
		return (NULL);
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	free(s1 - len1);
	return (tmp - len1 - len2);
}
