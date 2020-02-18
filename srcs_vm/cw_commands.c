/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:28:31 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/13 17:07:19 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			get_commands(t_cwoptions *opts)
{
	int i;

	i = 0;
	while (i < 17)
	{
		opts->op_tab[i] = g_op_tab[i];
		i++;
	}
}

void			delete_old_carriage(t_cwoptions *opts)
{
	t_carriage		*curr;
	t_carriage		*prev;
	t_carriage		*next;

	curr = *(opts->list);
	prev = 0;
	while (curr)
	{
		next = curr->next;
		if (opts->cycles_to_die <= 0 ||
			opts->q_cycles - curr->last_cycle_alive >= opts->cycles_to_die)
		{
			if (prev == 0)
				*(opts->list) = next;
			else
				prev->next = next;
			free(curr);
			curr = 0;
		}
		if (curr)
			prev = curr;
		curr = next;
	}
}
