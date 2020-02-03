/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:01:46 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:01:47 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_label(t_s *s, t_op_elem *cur_op)
{
	char	*cur_op_label;
	char	*cur_arr_label;
	int		k;
	int		i;

	k = 0;
	while (cur_op->labels[k])
	{
		cur_op_label = cur_op->labels[k];
		i = 0;
		while (i < s->labels->label_index)
		{
			cur_arr_label = s->labels->labels[i];
			if (ft_strequ(cur_arr_label, cur_op_label))
				return (1);
			i++;
		}
		k++;
	}
	if (k == 0)
		return (1);
	else
		return (0);
}

int			check_labels(t_s *s)
{
	int			i;
	t_op_elem	*cur_op;

	i = 0;
	while (i < s->oper_index)
	{
		cur_op = s->operations[i];
		if (!check_label(s, cur_op))
			return (0);
		i++;
	}
	return (1);
}
