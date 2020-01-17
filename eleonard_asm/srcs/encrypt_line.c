/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encrypt_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:59:41 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/13 19:03:32 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int 	have_one_quote(char *line)
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
		case_of_error();//NO STRING
	return (1);
}

static char *read_(t_s *s, char *line)
{
	char	*str;
	int		gnl_ret;
	char	*temp;

	while ((gnl_ret = get_next_line(s->fd, &str)))
	{
		if (gnl_ret == -1)
			case_of_error();
		else if (str)
		{
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
		case_of_error();//нет закрывающей кавычки
	return (line);
}

static char *put_after_quote(char *str)
{
	int 	i;
	char	*res;
	int 	end_quote_ind;
	int 	start_quote_ind;

	i = 0;
	while (str[i] != '"')
		i++;
	start_quote_ind = i + 1;
	end_quote_ind = get_symbol_index(str + start_quote_ind, '"') + start_quote_ind;
	res = ft_strsub(str, start_quote_ind, end_quote_ind - start_quote_ind);
	if (wrong_end_of_line(str + end_quote_ind + 1))
		case_of_error();
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
			case_of_error();//TOO LONG NAME
		add_str_to_byte_code(s, s->name, PROG_NAME_LENGTH * 2);
	}
	else
	{
		s->has_comment = 1;
		s->comment = put_after_quote(line);
		if (ft_strlen(s->comment) > COMMENT_LENGTH)
			case_of_error();//TOO LONG COMMENT

	}
}

void	encrypt_line(char *line, t_s *s)
{
	char *str;

	if (s->has_comment && s->has_name)
	{
		if (!s->comment_written)
			add_till_CEC(s);
		read_line(line, s);
		ft_strdel(&line);
	}
	else
	{
		if (!ft_strncmp(".name", line, 5))
			getter(s, line, 'n');
		else if (!ft_strncmp(".comment", line, 5))
			getter(s, line, 'c');
	}
}
