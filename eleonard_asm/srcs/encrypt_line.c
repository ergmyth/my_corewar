/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encrypt_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:59:41 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:02:47 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	have_one_quote(char *line)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '"')
		{
			k++;
			if (k == 2)
				return (0);
		}
		i++;
	}
	if (k == 0)
		case_of_error(ERR_NAME_OR_COMMENT);
	return (1);
}

static char	*read_(t_s *s, char *line)
{
	char	*str;
	int		gnl_ret;
	char	*temp;

	while ((gnl_ret = get_next_line(s->fd, &str)))
	{
		if (gnl_ret == -1)
			case_of_error(ERR_GNL);
		else if (str)
		{
			s->line_index++;
			temp = ft_strjoin(line, "\n");
			ft_strdel(&line);
			line = ft_strjoin(temp, str);
			ft_strdel(&temp);
			ft_strdel(&str);
		}
		if (!have_one_quote(line))
			break ;
	}
	if (gnl_ret == 0)
		case_of_error(ERR_HAVENT_END_QUOTE);
	return (line);
}

static char	*put_after_quote(char *str)
{
	int		i;
	char	*res;
	int		end_quote_ind;
	int		start_ind;

	i = 0;
	while (str[i] != '"')
		i++;
	start_ind = i + 1;
	end_quote_ind = get_symbol_index(str + start_ind, '"') + start_ind;
	res = ft_strsub(str, start_ind, end_quote_ind - start_ind);
	if (wrong_end_of_line(str + end_quote_ind + 1))
		case_of_error(ERR_LEXICAL);
	return (res);
}

static void	getter(t_s *s, char *line, char c)
{
	if (have_one_quote(line))
		line = read_(s, line);
	if (c == 'n')
	{
		s->has_name = 1;
		s->name = put_after_quote(line);
		if (ft_strlen(s->name) > PROG_NAME_LENGTH)
			case_of_error(ERR_TOO_LONG_NAME);
		add_str_to_byte_code(s, s->name, PROG_NAME_LENGTH * 2);
	}
	else
	{
		s->has_comment = 1;
		s->comment = put_after_quote(line);
		if (ft_strlen(s->comment) > COMMENT_LENGTH)
			case_of_error(ERR_TOO_LONG_COMMENT);
	}
}

void		encrypt_line(char *line, t_s *s)
{
	if (s->has_comment && s->has_name)
	{
		if (!s->comment_written)
			add_till_cec(s);
		read_line(line, s);
	}
	else
	{
		if (!ft_strncmp(NAME_CMD_STRING, line, 5))
			getter(s, line, 'n');
		else if (!ft_strncmp(COMMENT_CMD_STRING, line, 5))
			getter(s, line, 'c');
	}
}
