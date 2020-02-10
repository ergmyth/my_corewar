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

static int	have_one_quote(char *line, t_s *s)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '"')
			k++;
		i++;
	}
	if (k == 2)
		return (0);
	else if (k == 0)
		case_of_error(ERR_NAME_OR_COMMENT, s->line_index + 1);
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
			case_of_error(ERR_GNL, 0);
		else if (str)
		{
			s->line_index++;
			temp = line;
			line = ft_strjoin(line, "\n");
			ft_strdel(&temp);
			temp = line;
			line = ft_strjoin(line, str);
			ft_strdel(&str);
			ft_strdel(&temp);
		}
		if (line && !have_one_quote(line, s))
			break ;
	}
	if (gnl_ret == 0)
		case_of_error(ERR_HAVENT_END_QUOTE, s->line_index + 1);
	return (line);
}

static char	*put_after_quote(char *str, t_s *s)
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
		case_of_error(ERR_LEXICAL, s->line_index + 1);
	ft_strdel(&str);
return (res);
}

static void	getter(t_s *s, char *line, char c)
{
	char	*str;

	if (!(str = ft_strdup(line)))
		case_of_error(ERR_MALLOC, 0);
	if (have_one_quote(str, s))
		str = read_(s, str);
	if (c == 'n')
	{
		s->has_name = 1;
		s->name = put_after_quote(str, s);
		if (ft_strlen(s->name) > PROG_NAME_LENGTH)
			case_of_error(ERR_TOO_LONG_NAME, s->line_index + 1);
		add_str_to_byte_code(s, s->name, PROG_NAME_LENGTH * 2);
	}
	else
	{
		s->has_comment = 1;
		s->comment = put_after_quote(str, s);
		if (ft_strlen(s->comment) > COMMENT_LENGTH)
			case_of_error(ERR_TOO_LONG_COMMENT, s->line_index + 1);
	}
}

void		encrypt_line(char *line, t_s *s)
{
	char	*str;
	int		i;

	i = 0;
	while(is_space(line[i]))
		i++;
	str = line + i;
	if (s->has_comment && s->has_name)
	{
		if (!s->comment_written)
			add_till_cec(s);
		if (ft_strncmp(".extend", str, 7))
			read_line(str, s);
	}
	else
	{
		if (!s->has_name && !ft_strncmp(NAME_CMD_STRING, str, 5))
			getter(s, str, 'n');
		else if (!s->has_comment && !ft_strncmp(COMMENT_CMD_STRING, str, 5))
			getter(s, str, 'c');
        else
            case_of_error(ERR_NAME_OR_COMMENT, s->line_index + 1);
	}
}
