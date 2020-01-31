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
		case_of_error(ERR_MALLOC);
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
	size = ft_strlen(str) - k;
	if (!(new_str = ft_strnew(size)))
		case_of_error(ERR_MALLOC);
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
	int size;

	size = s->op_tab[op_index].arg_count + 1;
	k = 0;
	index = 0;
	if (!(s->args = (char**)malloc(sizeof(char*) * size)))
		case_of_error(ERR_MALLOC);
	while (k < s->op_tab[op_index].arg_count)
	{
		if (k + 1 == s->op_tab[op_index].arg_count)
			s->args[k] = (!k) ? ft_strdup(str) : ft_strdup(str + index);
		else
		{
			size = get_symbol_index(str + index, SEPARATOR_CHAR);
			s->args[k] = ft_strsub(str, index, size);
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
	ft_strdel(matrix);
}

void		get_args(int op_index, t_s *s, char *str)
{
	char	*edited_str;

	init_cur_args(s, s->op_tab[op_index].arg_count);
	edited_str = edit_str(str);
	put_args(s, edited_str, op_index);
	if (check_args(op_index, s))
		s->oper_index++;
	del_matrix(s->args, s->op_tab[op_index].arg_count);
	ft_strdel(&edited_str);
}
