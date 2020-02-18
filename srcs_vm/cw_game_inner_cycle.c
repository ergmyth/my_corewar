/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_game_inner_cycle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:41:25 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/13 16:05:45 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

void		state_opcode(t_carriage *curr, t_cwoptions *opts)
{
	curr->op_code = *(curr->current_position);
	if (curr->op_code >= 0x01 && curr->op_code <= 0x10)
		curr->cycles_countdown = (opts->op_tab)[curr->op_code - 1].loop;
	else
		curr->cycles_countdown = 1;
}

static void	exec_code(t_carriage *curr, t_cwoptions *opts)
{
	void	(*num_exec[16])(t_carriage *curr, t_cwoptions *opts);

	num_exec[0] = live;
	num_exec[1] = ld;
	num_exec[2] = st;
	num_exec[3] = add;
	num_exec[4] = sub;
	num_exec[5] = and;
	num_exec[6] = or;
	num_exec[7] = xor;
	num_exec[8] = zjmp;
	num_exec[9] = ldi;
	num_exec[10] = sti;
	num_exec[11] = cwfork;
	num_exec[12] = lld;
	num_exec[13] = lldi;
	num_exec[14] = lfork;
	num_exec[15] = aff;
	num_exec[curr->op_code - 1](curr, opts);
}

static int	code_is_valid(int *step, t_carriage *curr, t_cwoptions *opts)
{
	char			*temp_ptr;
	unsigned char	args[4];

	temp_ptr = curr->current_position;
	if ((opts->op_tab)[curr->op_code - 1].arg_type != 0)
	{
		++temp_ptr;
		check_arena(&temp_ptr, opts);
		get_args(*temp_ptr, args);
		if (!check_args(step, args, curr, opts))
			return (0);
	}
	else
	{
		if (curr->op_code == 1)
			*step = 5;
		else
			*step = 3;
	}
	return (1);
}

void		exec_op(t_carriage *curr, t_cwoptions *opts)
{
	int		step;

	if (curr->op_code >= 0x01 && curr->op_code <= 0x10)
	{
		if (code_is_valid(&step, curr, opts))
			exec_code(curr, opts);
		if (curr->op_code != 0x09 ||
			(curr->op_code == 0x09 && curr->carry == 0))
			curr->current_position += step;
	}
	else
		curr->current_position++;
	check_arena(&(curr->current_position), opts);
}
