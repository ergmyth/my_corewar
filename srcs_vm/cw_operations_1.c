/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:58:20 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/13 16:28:21 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

void		live(t_carriage *curr, t_cwoptions *opts)
{
	char	*temp;
	int		num;

	curr->last_cycle_alive = opts->q_cycles;
	num = 0;
	temp = curr->current_position;
	temp++;
	check_arena(&temp, opts);
	num = get_int(&temp, curr, opts, 4);
	if (-num <= opts->q_players && -num >= 1)
	{
		opts->last_alive_player = -num;
		if (opts->flag_d == 1)
			ft_printf("A process shows that player %d (%s) is alive\n",
								-num, (*(opts->players))[-num - 1].name);
	}
	opts->q_live_operations++;
}

void		ld(t_carriage *curr, t_cwoptions *opts)
{
	char			*temp;
	unsigned char	args[4];
	int				num;
	char			reg;

	temp = curr->current_position;
	temp++;
	check_arena(&temp, opts);
	get_args(*temp, args);
	temp++;
	check_arena(&temp, opts);
	num = get_one_arg(&temp, args[0], curr, opts);
	temp = curr->current_position;
	if (args[0] == 2)
		temp += 6;
	else
		temp += 4;
	check_arena(&temp, opts);
	reg = *temp;
	curr->reg[reg - 1] = num;
	curr->carry = num == 0 ? 1 : 0;
}

void		st(t_carriage *curr, t_cwoptions *opts)
{
	int				num;
	char			*temp;
	unsigned char	args[4];

	temp = curr->current_position;
	temp++;
	check_arena(&temp, opts);
	get_args(*temp, args);
	temp++;
	check_arena(&temp, opts);
	num = curr->reg[*temp - 1];
	temp++;
	check_arena(&temp, opts);
	if (args[1] == 1)
		curr->reg[*temp - 1] = num;
	else
	{
		temp = curr->current_position +
					get_int(&temp, curr, opts, 2) % IDX_MOD;
		check_arena(&temp, opts);
		set_int(temp, num, opts);
	}
}

void		add(t_carriage *curr, t_cwoptions *opts)
{
	char			*temp;
	int				num[2];

	temp = curr->current_position;
	temp += 2;
	check_arena(&temp, opts);
	num[0] = *temp;
	temp++;
	check_arena(&temp, opts);
	num[1] = *temp;
	temp++;
	check_arena(&temp, opts);
	curr->reg[*temp - 1] = curr->reg[num[0] - 1] + curr->reg[num[1] - 1];
	curr->carry = curr->reg[*temp - 1] == 0 ? 1 : 0;
}
