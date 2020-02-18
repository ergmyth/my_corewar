/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_carriage_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:47:56 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/15 12:43:51 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_carriage	*create_carriage(int player_number,
										char *cur_pos)
{
	static int		num;
	t_carriage		*carr;
	int				i;

	carr = (t_carriage*)malloc(sizeof(t_carriage));
	if (!carr)
		return (0);
	carr->number = num++;
	carr->carry = 0;
	carr->op_code = 0;
	carr->last_cycle_alive = -1;
	carr->cycles_countdown = -1;
	carr->current_position = cur_pos;
	carr->next = 0;
	i = 0;
	while (i < REG_NUMBER_VM)
	{
		if (i == 0)
			(carr->reg)[i] = -player_number;
		else
			(carr->reg)[i] = 0;
		i++;
	}
	return (carr);
}

void				insert_in_carriage_list(t_carriage **head,
								int player_number, char *cur_pos)
{
	t_carriage		*ex_head;

	if (!head)
		return ;
	if (!(*head))
		*head = create_carriage(player_number, cur_pos);
	else
	{
		ex_head = *head;
		*head = create_carriage(player_number, cur_pos);
		(*head)->next = ex_head;
	}
}

void				delete_carriage(t_carriage **head, int carriage_num)
{
	t_carriage		*temp;
	t_carriage		*to_del;

	temp = *head;
	if ((*head)->number == carriage_num)
	{
		*head = (*head)->next;
		free(temp);
		return ;
	}
	while (temp->next->number != carriage_num)
		temp = temp->next;
	to_del = temp->next;
	temp->next = to_del->next;
	free(to_del);
}

void				create_list(t_player **player, t_cwoptions *opts)
{
	t_carriage		*list;
	int				i;

	i = 0;
	list = 0;
	while (i < opts->q_players)
	{
		insert_in_carriage_list(&list, (*player)[i].id,
								opts->arena + (*player)[i].start_offset);
		i++;
	}
	*(opts->list) = list;
}

void				carriage_copy(t_carriage *from, t_carriage *to)
{
	int			i;

	i = -1;
	while (++i < 16)
		to->reg[i] = from->reg[i];
	to->carry = from->carry;
	to->last_cycle_alive = from->last_cycle_alive;
}
