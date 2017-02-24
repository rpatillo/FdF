/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:40:33 by rpatillo          #+#    #+#             */
/*   Updated: 2014/11/09 15:02:38 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*f;

	i = 0;
	f = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			f = (char *)(s + i);
		i++;
	}
	if (s[i] == c)
		f = (char *)(s + i);
	return (f);
}
