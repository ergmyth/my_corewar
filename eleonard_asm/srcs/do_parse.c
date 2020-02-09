/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:32:24 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:02:42 by eleonard         ###   ########.fr       */
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

void		do_parse(t_s *s)
{
	char	*line;
	int		gnl_ret;

	line = NULL;
	while ((gnl_ret = get_next_line(s->fd, &line)))
	{
		if (gnl_ret == -1)
			case_of_error(ERR_GNL);
		else if (line && not_a_comment(line) && not_empty_line(line))
			encrypt_line(line, s);
		s->line_index++;
		ft_strdel(&line);
	}
	ft_strdel(&s->name);
	ft_strdel(&s->comment);
}
