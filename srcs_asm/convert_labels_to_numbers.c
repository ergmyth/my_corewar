/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_labels_to_numbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:02:20 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:02:21 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	convert_func(t_op_elem *cur_op, t_op_elem *dir_op, int index)
{
	int	res;

	res = (cur_op->bytes_before - dir_op->bytes_before) * -1;
	ft_strdel(&cur_op->value[index]);
	if (!(cur_op->value[index] = ft_itoa(res)))
		case_of_error(ERR_MALLOC, 0);
}

static void	convert_label(t_op_elem *cur_op, t_s *s, int index)
{
	int			i;
	t_op_elem	*dir_op;
	char		*dir_label;
	int			k;

	i = 0;
	while (i <= s->op_i)
	{
		dir_op = s->op[i++];
		k = 0;
		while (k < dir_op->l_size)
		{
			if (!(dir_label = dir_op->l[k++]))
				break ;
			if (ft_strequ(dir_label, cur_op->value[index] + 1))
			{
				convert_func(cur_op, dir_op, index);
				return ;
			}
		}
	}
	ft_putstr_fd(cur_op->value[index], 2);
	case_of_error(ERR_NO_SUCH_LABEL, 0);
}

void		convert_labels_to_numbers(t_s *s)
{
	int			i;
	t_op_elem	*cur_op;
	int			k;

	i = 0;
	while (i <= s->op_i)
	{
		cur_op = s->op[i];
		k = 0;
		while (cur_op->value[k])
		{
			if (!only_numbers(cur_op->value[k]))
				convert_label(cur_op, s, k);
			k++;
		}
		i++;
	}
}
