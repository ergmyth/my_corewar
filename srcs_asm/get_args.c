/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:03:19 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:03:20 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	init_cur_args(t_s *s, int size)
{
	int i;

	if (!(s->args = (char**)malloc(sizeof(char*) * (size + 1))))
		case_of_error(ERR_MALLOC, s->line_index + 1);
	i = 0;
	while (i <= size)
		s->args[i++] = 0;
}

static char	*edit_str(char *str)
{
	int		i;
	int		k;
	char	*new_str;
	int		size;

	i = 0;
	k = 0;
	while (str[i])
		if (is_space(str[i++]))
			k++;
	size = (int)ft_strlen(str) - k;
	if (!(new_str = ft_strnew(size)))
		case_of_error(ERR_MALLOC, 0);
	i = 0;
	k = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
			new_str[k++] = str[i];
		i++;
	}
	return (new_str);
}

static void	put_args(t_s *s, char *str, int op_index)
{
	int k;
	int index;
	int len;

	k = 0;
	index = 0;
	while (k < g_op_tab[op_index].arg_count)
	{
		if (k + 1 == g_op_tab[op_index].arg_count)
		{
			if (!(s->args[k] = (!k) ? ft_strdup(str) : ft_strdup(str + index)))
				case_of_error(ERR_MALLOC, 0);
		}
		else
		{
			len = index_of(str + index, SEPARATOR_CHAR);
			if (len == -1)
				case_of_error(ERR_LEXICAL, s->line_index + 1);
			if (!(s->args[k] = ft_strsub(str, index, len)))
				case_of_error(ERR_MALLOC, 0);
			index += (int)ft_strlen(s->args[k]) + 1;
		}
		k++;
	}
}

static void	del_matrix(char **matrix, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_strdel(&matrix[i++]);
}

void		get_args(int op_index, t_s *s, char *str)
{
	char	*edited_str;

	init_cur_args(s, g_op_tab[op_index].arg_count);
	edited_str = edit_str(str);
	put_args(s, edited_str, op_index);
	if (check_args(op_index, s))
	{
		s->op_i++;
		if (s->op_i == s->size - 1)
		{
			s->size *= 2;
			if (!(s->op = (t_op_elem**)realloc(s->op,
					sizeof(t_op_elem*) * s->size)))
				case_of_error(ERR_MALLOC, 0);
			init_operations(s, s->op_i + 1);
		}
	}
	else
		case_of_error(ERR_COMMAND_ARG, s->line_index + 1);
	del_matrix(s->args, g_op_tab[op_index].arg_count);
	ft_memdel((void**)&s->args);
	ft_strdel(&edited_str);
}
