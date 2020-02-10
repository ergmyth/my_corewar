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

static void	t_op_add_to_struct(t_s *s, t_op op_tab[17])
{
	int i;

	i = 0;
	while (i < 17)
	{
		s->op_tab[i] = op_tab[i];
		i++;
	}
}

static void	create_op_tab(t_s *s)
{
	static t_op	op_tab[17] =
	{
		{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
		{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
		{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
		{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
		{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
		{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
				"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
		{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
				"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
		{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
				"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
		{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
		{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
				"load index", 1, 1},
		{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
				"store index", 1, 1},
		{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
		{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
		{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
				"long load index", 1, 1},
		{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
		{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
		{0, 0, {0}, 0, 0, 0, 0, 0}
	};
	t_op_add_to_struct(s, op_tab);
}

static void	init_labels_struct(t_s *s)
{
	t_labels	*l;

	if (!(s->labels = (t_labels*)malloc(sizeof(t_labels))))
		case_of_error(ERR_MALLOC, 0);
	l = s->labels;
	l->labels_size = 128;
	if (!(l->labels = (char**)malloc(sizeof(char*) * l->labels_size)))
		case_of_error(ERR_MALLOC, 0);
	l->label_index = 0;
	while (l->label_index < l->labels_size)
		l->labels[l->label_index++] = 0;
	l->labels[l->labels_size - 1] = 0;
	l->label_index = 0;
	if (!(l->line = (int*)malloc(sizeof(int) * l->labels_size)))
		case_of_error(ERR_MALLOC, 0);
}

t_s			*initialize(void)
{
	t_s	*s;

	if (!(s = (t_s*)malloc(sizeof(t_s))))
		case_of_error(ERR_MALLOC, 0);
	s->has_name = 0;
	s->byte_code_size = (COMMENT_LENGTH + PROG_NAME_LENGTH + 16 + CHAMP_MAX_SIZE) * 2;
	s->comment_written = 0;
	s->cec_ind = 0;
	s->commands_start_ind = 0;
	init_labels_struct(s);
	s->line_index = 0;
	s->has_comment = 0;
	s->size = 256;
	s->op_i = 0;
	create_op_tab(s);
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
