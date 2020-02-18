/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:04:43 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 16:17:13 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	start_byte_code(char *code)
{
	int		i;
	int		magic_len;
	char	*str;
	int		k;

	i = 0;
	if (!(str = pf_hex(COREWAR_EXEC_MAGIC)))
		case_of_error(ERR_MALLOC, 0);
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
		case_of_error(ERR_MALLOC, 0);
	s->has_name = 0;
	s->byte_code_size = (COMMENT_LENGTH + PROG_NAME_LENGTH +
			16 + CHAMP_MAX_SIZE) * 2;
	s->comment_written = 0;
	s->cec_ind = 0;
	s->commands_start_ind = 0;
	s->line_index = 0;
	s->has_comment = 0;
	s->size = 256;
	s->op_i = 0;
	if (!(s->byte_code = ft_strnew(s->byte_code_size)))
		case_of_error(ERR_MALLOC, 0);
	start_byte_code(s->byte_code);
	if (!(s->op = (t_op_elem**)malloc(sizeof(t_op_elem*) * s->size)))
		case_of_error(ERR_MALLOC, 0);
	init_operations(s, 0);
	s->name = 0;
	s->comment = 0;
	return (s);
}
