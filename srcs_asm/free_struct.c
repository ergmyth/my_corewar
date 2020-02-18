/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:40:16 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/10 20:40:17 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_op_struct(t_s *s)
{
	int i;
	int k;

	i = 0;
	while (i < s->size)
	{
		ft_strdel(&s->op[i]->name);
		k = 0;
		while (s->op[i]->l[k])
			ft_strdel(&s->op[i]->l[k++]);
		ft_memdel((void**)&s->op[i]->l);
		k = 0;
		while (s->op[i]->value[k])
		{
			ft_strdel(&s->op[i]->value[k]);
			k++;
		}
		ft_strdel((char**)&s->op[i]->value);
		ft_memdel((void**)&s->op[i]);
		i++;
	}
}

void		free_struct(t_s *s)
{
	ft_strdel(&s->byte_code);
	free_op_struct(s);
	ft_memdel((void**)&s->op);
	ft_memdel((void**)&s);
}
