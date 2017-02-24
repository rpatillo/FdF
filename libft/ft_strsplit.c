/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 12:11:18 by rpatillo          #+#    #+#             */
/*   Updated: 2015/05/18 12:48:29 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_wrd(char *s, char c)
{
	int		wrd;
	int		j;

	wrd = 0;
	j = 1;
	while (*s != '\0')
	{
		if (*s == c)
			j = 1;
		if (*s != c && j == 1)
		{
			wrd++;
			j = 0;
		}
		s++;
	}
	return (wrd);
}

static char	*alloc(const char *s, char c)
{
	size_t	len;
	size_t	i;
	char	*tab;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	tab = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		tab[i] = s[i];
		i++;
	}
	tab[len] = '\0';
	return (tab);
}

static char	**split(const char *s, char c, char **tab, int wrd_nbr)
{
	size_t	i;
	int		j;

	i = 0;
	j = 1;
	while (*s != '\0' && (wrd_nbr - i) > 0)
	{
		if (*s == c)
			j = 1;
		if (*s != c && j == 1)
		{
			tab[i] = alloc(s, c);
			j = 0;
			i++;
		}
		s++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		wrd_nbr;
	char	**tab;

	if (s == NULL)
		return (NULL);
	wrd_nbr = cnt_wrd((char*)s, c);
	tab = (char **)malloc(sizeof(char *) * (wrd_nbr + 1));
	if (tab == NULL)
		return (NULL);
	tab = split(s, c, tab, wrd_nbr);
	tab[wrd_nbr] = NULL;
	return (tab);
}
