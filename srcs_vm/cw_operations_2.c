/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:23:35 by clianne           #+#    #+#             */
/*   Updated: 2020/02/13 16:27:45 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

void		sub(t_carriage *curr, t_cwoptions *opts)
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
	curr->reg[*temp - 1] = curr->reg[num[0] - 1] - curr->reg[num[1] - 1];
	curr->carry = curr->reg[*temp - 1] == 0 ? 1 : 0;
}

void		and(t_carriage *curr, t_cwoptions *opts)
{
	char			*temp;
	unsigned char	args[4];
	int				num[2];

	temp = curr->current_position;
	temp++;
	check_arena(&temp, opts);
	get_args(*temp, args);
	temp++;
	check_arena(&temp, opts);
	num[0] = get_one_arg(&temp, args[0], curr, opts);
	num[1] = get_one_arg(&temp, args[1], curr, opts);
	curr->reg[*temp - 1] = num[0] & num[1];
	curr->carry = curr->reg[*temp - 1] == 0 ? 1 : 0;
}

void		or(t_carriage *curr, t_cwoptions *opts)
{
	char			*temp;
	unsigned char	args[4];
	int				num[2];

	temp = curr->current_position;
	temp++;
	check_arena(&temp, opts);
	get_args(*temp, args);
	temp++;
	check_arena(&temp, opts);
	do_iarray_fill(num, 2, 0);
	num[0] = get_one_arg(&temp, args[0], curr, opts);
	num[1] = get_one_arg(&temp, args[1], curr, opts);
	curr->reg[*temp - 1] = num[0] | num[1];
	curr->carry = curr->reg[*temp - 1] == 0 ? 1 : 0;
}

void		xor(t_carriage *curr, t_cwoptions *opts)
{
	char			*temp;
	unsigned char	args[4];
	int				num[2];

	temp = curr->current_position;
	temp++;
	check_arena(&temp, opts);
	get_args(*temp, args);
	temp++;
	check_arena(&temp, opts);
	do_iarray_fill(num, 2, 0);
	num[0] = get_one_arg(&temp, args[0], curr, opts);
	num[1] = get_one_arg(&temp, args[1], curr, opts);
	curr->reg[*temp - 1] = num[0] ^ num[1];
	curr->carry = curr->reg[*temp - 1] == 0 ? 1 : 0;
}
