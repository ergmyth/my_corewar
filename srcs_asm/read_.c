/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:05:23 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/18 20:05:24 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*read_(t_s *s, char *line)
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
