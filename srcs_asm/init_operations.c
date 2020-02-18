/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:39:52 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/10 20:39:54 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_operations(t_s *s, int i)
{
	int	k;

	while (i < s->size)
	{
		if (!(s->op[i] = (t_op_elem*)malloc(sizeof(t_op_elem))))
			case_of_error(ERR_MALLOC, 0);
		s->op[i]->bytes_before = -1;
		s->op[i]->l_size = 10;
		k = 0;
		if (!(s->op[i]->l = (char**)malloc(sizeof(char*) * s->op[i]->l_size)))
			case_of_error(ERR_MALLOC, 0);
		while (k < s->op[i]->l_size)
			s->op[i]->l[k++] = 0;
		k = 0;
		if (!(s->op[i]->value = (char**)malloc(sizeof(char*) * 4)))
			case_of_error(ERR_MALLOC, 0);
		while (k < 4)
			s->op[i]->value[k++] = 0;
		s->op[i++]->name = 0;
	}
	s->op[0]->bytes_before = 0;
}
