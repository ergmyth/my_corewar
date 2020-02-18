/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:02:33 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/18 20:02:34 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	getter(t_s *s, char *line, char c)
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
