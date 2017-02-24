/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:26:46 by rpatillo          #+#    #+#             */
/*   Updated: 2014/11/16 12:18:11 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt(int n)
{
	int		cnt;

	cnt = 0;
	if (n == 0)
		cnt += 1;
	if (n < 0)
		cnt += 1;
	while (n != 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*new;

	len = cnt(n);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	*(new + len--) = '\0';
	if (n < 0)
		*new = '-';
	else
		*new = '0';
	while (n != 0)
	{
		if (n > 0)
			*(new + len--) = '0' + n % 10;
		else if (n < 0)
			*(new + len--) = '0' - n % 10;
		n = n / 10;
	}
	return (new);
}
