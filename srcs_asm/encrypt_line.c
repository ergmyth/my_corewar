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

void		encrypt_line(char *line, t_s *s)
{
	char	*str;
	int		i;

	i = 0;
	while (is_space(line[i]))
		i++;
	str = line + i;
	if (s->has_comment && s->has_name)
	{
		if (!s->comment_written)
			add_cec(s);
		if (ft_strncmp(".extend", str, 7))
			read_line(str, s);
	}
	else
		check_name_and_comment(s, str);
}
