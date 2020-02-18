/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_end_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:02:25 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/18 20:11:45 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	have_one_quote(char *line, t_s *s)
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
