/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_operations_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:11:36 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/13 16:28:47 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

void		zjmp(t_carriage *curr, t_cwoptions *opts)
{
	char			*temp;
	int				num;

	if (curr->carry == 0)
		return ;
	temp = curr->current_position;
	temp++;
	check_arena(&temp, opts);
	num = get_int(&temp, curr, opts, 2);
	curr->current_position += (num % IDX_MOD);
}

void		ldi(t_carriage *curr, t_cwoptions *opts)
{
	char			*temp;
	unsigned char	args[4];
	int				num[2];
	char			reg;
	int				res;

	temp = curr->current_position;
	temp++;
	check_arena(&temp, opts);
	get_args(*temp, args);
	temp++;
	check_arena(&temp, opts);
	num[0] = get_one_arg(&temp, args[0], curr, opts);
	num[1] = get_one_arg(&temp, args[1], curr, opts);
	reg = *temp;
	temp = curr->current_position + ((num[0] + num[1]) % IDX_MOD);
	check_arena(&temp, opts);
	res = get_int(&temp, curr, opts, 4);
	curr->reg[reg - 1] = res;
}

void		sti(t_carriage *curr, t_cwoptions *opts)
{
	char			*temp;
	unsigned char	args[4];
	int				num[2];
	int				res;

	temp = curr->current_position;
	temp++;
	check_arena(&temp, opts);
	get_args(*temp, args);
	temp++;
	check_arena(&temp, opts);
	res = curr->reg[*temp - 1];
	temp++;
	check_arena(&temp, opts);
	num[0] = get_one_arg(&temp, args[1], curr, opts);
	num[1] = get_one_arg(&temp, args[2], curr, opts);
	temp = curr->current_position + ((num[0] + num[1]) % IDX_MOD);
	check_arena(&temp, opts);
	set_int(temp, res, opts);
}

void		cwfork(t_carriage *curr, t_cwoptions *opts)
{
	int		num;
	char	*temp;

	temp = curr->current_position;
	temp++;
	check_arena(&temp, opts);
	num = get_int(&temp, curr, opts, 2);
	temp = curr->current_position + (num % IDX_MOD);
	check_arena(&temp, opts);
	insert_in_carriage_list(opts->list, -(curr->reg[0]), temp);
	carriage_copy(curr, *(opts->list));
}
