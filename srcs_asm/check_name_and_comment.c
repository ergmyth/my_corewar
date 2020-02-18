/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_and_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:03:02 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/18 20:19:38 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*get_before_space(char *temp)
{
	char	*str;
	int		index_space;
	int		index_tab;
	int		res;

	index_space = index_of(temp, ' ');
	index_tab = index_of(temp, '\t');
	if (index_space == index_tab)
		return (temp);
	else if (index_space == -1)
		res = index_tab;
	else if (index_tab == -1)
		res = index_space;
	else if (index_space < index_tab)
		res = index_space;
	else
		res = index_tab;
	if (!(str = ft_strsub(temp, 0, res)))
		case_of_error(ERR_MALLOC, 0);
	ft_strdel(&temp);
	return (str);
}

void		check_name_and_comment(t_s *s, char *str)
{
	char	*temp;
	int		index_quote;

	index_quote = index_of(str, '"');
	if (index_quote == -1)
		case_of_error(ERR_NAME_OR_COMMENT, s->line_index + 1);
	if (!(temp = ft_strsub(str, 0, index_quote)))
		case_of_error(ERR_MALLOC, 0);
	temp = get_before_space(temp);
	if (!s->has_name && !ft_strcmp(NAME_CMD_STRING, temp))
		getter(s, str, 'n');
	else if (!s->has_comment && !ft_strcmp(COMMENT_CMD_STRING, temp))
		getter(s, str, 'c');
	else
		case_of_error(ERR_NAME_OR_COMMENT, s->line_index + 1);
	ft_strdel(&temp);
}
