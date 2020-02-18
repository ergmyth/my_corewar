/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:32:24 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/18 21:06:54 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	not_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

static int	not_a_comment(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
		return (0);
	return (1);
}

static void	check_end_of_file(int fd)
{
	char	b;

	while (1)
	{
		lseek(fd, -1, SEEK_CUR);
		read(fd, &b, 1);
		lseek(fd, -1, SEEK_CUR);
		if (b == '\n')
			return ;
		else if (b != ' ' && b != '\t')
			case_of_error(ERR_END_OF_FILE, 0);
	}
}

void		do_parse(t_s *s)
{
	char	*line;
	int		gnl_ret;
	int		line_has_op;

	line_has_op = 0;
	line = NULL;
	while ((gnl_ret = get_next_line(s->fd, &line)))
	{
		if (gnl_ret == -1)
			case_of_error(ERR_FD, 0);
		if (line && not_a_comment(line) && not_empty_line(line))
		{
			encrypt_line(line, s);
			line_has_op = 1;
		}
		else
			line_has_op = 0;
		s->line_index++;
		free(line);
	}
	if (line_has_op)
		check_end_of_file(s->fd);
	ft_strdel(&s->name);
	ft_strdel(&s->comment);
}
