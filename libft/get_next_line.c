/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 12:35:33 by rpatillo          #+#    #+#             */
/*   Updated: 2015/01/18 15:23:08 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fd			*ft_createllist(int fd, t_fd *first)
{
	t_fd		*tmp;

	tmp = (t_fd *)malloc(sizeof(t_fd));
	if (tmp == NULL)
		return (NULL);
	tmp->str = NULL;
	tmp->fd = fd;
	if (first == NULL)
		tmp->first = tmp;
	else
		tmp->first = first;
	tmp->next = NULL;
	return (tmp);
}

t_fd			*ft_searchllist(t_fd *list, int fd)
{
	t_fd		*tmp;

	if (list == NULL)
	{
		tmp = ft_createllist(fd, NULL);
		if (tmp == NULL)
			return (NULL);
		return (tmp);
	}
	tmp = list->first;
	while ((tmp->fd != fd) && (tmp->next != NULL))
		tmp = tmp->next;
	if (tmp->fd == fd)
		return (tmp);
	else if (tmp->next == NULL)
	{
		if ((tmp->next = ft_createllist(fd, tmp->first)) == NULL)
			return (NULL);
	}
	return (tmp->next);
}

int				loop(int ret, char **str, char **line, char *pos_n)
{
	char *tmp;

	if (ret < 0)
		return (-1);
	if (ret == 0 && (ft_strlen(*str) > 0))
	{
		*line = *str;
		*str = *str + ft_strlen(*str);
	}
	else if (ret == 0)
	{
		*line = NULL;
		return (0);
	}
	else
	{
		*line = ft_strsub(*str, 0, pos_n - *str);
		tmp = *str;
		*str = ft_strdup(pos_n + 1);
		free(tmp);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_fd		*list = NULL;
	char			*tmp;
	char			*buf;
	int				ret;
	char			*pos_n;

	pos_n = NULL;
	if (fd < 0 || line == NULL)
		return (-1);
	if ((list = ft_searchllist(list, fd)) == NULL)
		return (-1);
	*line = NULL;
	if ((buf = (char *)malloc((BUFF_SIZE + 1) * sizeof(char))) == NULL)
		return (-1);
	while (!(pos_n = ft_strchr(list->str, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 1)
			return (loop(ret, &(list->str), line, pos_n));
		buf[ret] = '\0';
		tmp = list->str;
		list->str = ft_strjoin(list->str, buf);
		free(tmp);
	}
	free(buf);
	return (loop(1, &(list->str), line, pos_n));
}
