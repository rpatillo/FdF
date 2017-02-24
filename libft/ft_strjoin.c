/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:35:46 by rpatillo          #+#    #+#             */
/*   Updated: 2014/12/19 14:21:51 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	if (s1 == NULL || s2 == NULL)
** 		return (NULL);
*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	size_t		i;
	size_t		j;
	char		*new;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (new == NULL)
		return (NULL);
	while (i < len1)
		new[i++] = s1[j++];
	j = 0;
	while (i < len1 + len2)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
