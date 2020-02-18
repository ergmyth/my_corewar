/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_after_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:02:10 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/18 20:02:11 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*put_after_quote(char *str, t_s *s)
{
	int		i;
	char	*res;
	int		end_quote_ind;
	int		start_ind;

	i = 0;
	while (str[i] != '"')
		i++;
	start_ind = i + 1;
	end_quote_ind = index_of(str + start_ind, '"') + start_ind;
	res = ft_strsub(str, start_ind, end_quote_ind - start_ind);
	if (wrong_end_of_line(str + end_quote_ind + 1))
		case_of_error(ERR_LEXICAL, s->line_index + 1);
	ft_strdel(&str);
	return (res);
}
