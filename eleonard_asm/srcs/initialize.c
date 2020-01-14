/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:04:43 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/13 18:41:34 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	start_byte_code(char *code)
{
	int		i;
	int		magic_len;
	char	*str;
	int 	k;

	i = 0;
	str = pf_hex(COREWAR_EXEC_MAGIC);
	magic_len = (int)ft_strlen(str);
	while (magic_len + i < 8)
	{
		code[i] = '0';
		i++;
	}
	k = 0;
	while (k < magic_len)
	{
		code[i] = str[k];
		k++;
		i++;
	}
	ft_strdel(&str);
}

t_s			*initialize(void)
{
	t_s	*s;
	
	if (!(s = (t_s*)malloc(sizeof(t_s))))
	    case_of_error();
	s->quote_opened = 0;
	s->has_name = 0;
	s->has_comment = 0;
	if (!(s->byte_code = ft_strnew((COMMENT_LENGTH + PROG_NAME_LENGTH
			+ 16 + CHAMP_MAX_SIZE) * 2 + 1)))
		case_of_error();
	start_byte_code(s->byte_code);
	return (s);
}
