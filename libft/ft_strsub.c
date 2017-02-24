/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:16:06 by rpatillo          #+#    #+#             */
/*   Updated: 2014/11/20 11:06:52 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Can add this to the first test to pass test :
** || s[start] == '\0' || len == 0 || (ft_strlen(s) - start) < (len - 1))
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	if (s == NULL)
		return (NULL);
	i = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (len > 0)
	{
		new[i++] = s[start++];
		len--;
	}
	new[i] = '\0';
	return (new);
}
