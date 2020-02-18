/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:01:39 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:01:40 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_reg(const char *str, t_s *s, int index)
{
	int	res;

	s->byte_value = 0;
	if (str[0] == 'r' && only_numbers(str + 1))
	{
		res = ft_atoi(str + 1);
		if (res >= 0 && res <= REG_NUMBER)
		{
			if (!(s->op[s->op_i]->value[index] = ft_strdup(str + 1)))
				case_of_error(ERR_MALLOC, 0);
			s->op[s->op_i]->args[index] = 1;
			s->byte_value = 1;
			return (1);
		}
		else
			case_of_error(ERR_TOO_BIG_REG_NUMBER, s->line_index + 1);
	}
	return (0);
}

static int	check_ind(const char *str, t_s *s, int index)
{
	s->byte_value = 0;
	if (str[0] == LABEL_CHAR)
	{
		if (!(s->op[s->op_i]->value[index] = ft_strdup(str)))
			case_of_error(ERR_MALLOC, 0);
		s->op[s->op_i]->args[index] = 4;
		s->byte_value = 2;
		return (1);
	}
	else if (only_numbers(str))
	{
		if (!(s->op[s->op_i]->value[index] = ft_strdup(str)))
			case_of_error(ERR_MALLOC, 0);
		s->byte_value = 2;
		s->op[s->op_i]->args[index] = 4;
		return (1);
	}
	return (0);
}

static int	check_dir(const char *str, t_s *s, int op_index, int index)
{
	s->byte_value = 0;
	if (str[0] == DIRECT_CHAR)
	{
		if (!(check_ind(str + 1, s, index)))
			return (0);
		if (g_op_tab[op_index].dir_size == 0)
			s->byte_value += 2;
		s->op[s->op_i]->args[index] = 2;
		return (1);
	}
	return (0);
}

static void	nullify_empty_args(t_op_elem *cur)
{
	int	i;

	i = g_op_tab[cur->index].arg_count;
	while (i < 3)
		cur->args[i++] = 0;
}

int			check_args(int op_index, t_s *s)
{
	int i;
	int cur;
	int total_size;
	int res;

	total_size = 0;
	i = 0;
	s->op[s->op_i]->index = op_index;
	while (i < g_op_tab[op_index].arg_count)
	{
		cur = g_op_tab[op_index].arr[i];
		if ((cur % 2 == 1 && check_reg(s->args[i], s, i)) ||
			(((cur >= 2 && cur < 4) || cur >= 6) &&
				check_dir(s->args[i], s, op_index, i)) ||
			(cur >= 4 && check_ind(s->args[i], s, i)))
			total_size += s->byte_value;
		else
			return (0);
		i++;
	}
	total_size += (g_op_tab[op_index].arg_type == 1) ? 2 : 1;
	res = total_size + s->op[s->op_i]->bytes_before;
	s->op[s->op_i + 1]->bytes_before = res;
	nullify_empty_args(s->op[s->op_i]);
	return (1);
}
