/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:55:03 by clianne           #+#    #+#             */
/*   Updated: 2019/09/11 18:21:16 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	t_fd_list	*ft_locate_fd(t_fd_list **files, int fd)
{
	t_fd_list *tmp;
	t_fd_list *new;

	tmp = *files;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(new = (t_fd_list *)malloc(sizeof(t_fd_list))))
		return (0);
	if (!(new->str = (char *)malloc(sizeof(char))))
		return (0);
	(new->str)[0] = '\0';
	new->fd = fd;
	new->next = *files;
	*files = new;
	return (new);
}

static	int			ft_is_eol(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static	int			ft_allocate_line(char *str, char **line)
{
	int		index;

	if (ft_strlen(str) == 0)
		return (0);
	index = ft_is_eol(str);
	if (index == -1)
	{
		if (!(*line = ft_strnew(ft_strlen(str))))
			return (-1);
		ft_strncpy(*line, str, ft_strlen(str));
		return (2);
	}
	if (index >= 0)
	{
		if (!(*line = ft_strnew(index)))
			return (-1);
		ft_strncpy(*line, str, index);
		return (1);
	}
	return (-1);
}

static	void		ft_swap_free(char **tmp, char *buf, char **str)
{
	*tmp = ft_strjoin(*str, buf);
	free(*str);
	*str = *tmp;
}

int					get_next_line(const int fd, char **line)
{
	static t_fd_list	*files;
	t_fd_list			*l;
	char				buf[BUFF_SIZE + 1];
	int					ret;
	char				*tmp;

	if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	l = ft_locate_fd(&files, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_swap_free(&tmp, buf, &(l->str));
		if (ft_is_eol(l->str) >= 0)
			break ;
	}
	ret = ft_allocate_line(l->str, line);
	if (ret == -1)
		return (-1);
	tmp = ((ret == 1) ? (ft_strsub(l->str, ft_is_eol(l->str) + 1, \
		ft_strlen(l->str) - ft_is_eol(l->str))) : ft_strsub(l->str, 0, 0));
	free(l->str);
	l->str = tmp;
	return ((ret == 0) ? 0 : 1);
}
