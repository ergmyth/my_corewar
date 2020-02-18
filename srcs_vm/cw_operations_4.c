/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_operations_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:17:15 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/15 09:11:41 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

void		lld(t_carriage *curr, t_cwoptions *opts)
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
	num = get_one_arg_no_md(&temp, args[0], curr, opts);
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

void		lldi(t_carriage *curr, t_cwoptions *opts)
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
	temp = curr->current_position + (num[0] + num[1]);
	check_arena(&temp, opts);
	res = get_int(&temp, curr, opts, 4);
	curr->reg[reg - 1] = res;
	curr->carry = res == 0 ? 1 : 0;
}

void		lfork(t_carriage *curr, t_cwoptions *opts)
{
	int		num;
	char	*temp;

	temp = curr->current_position;
	temp++;
	check_arena(&temp, opts);
	num = get_int(&temp, curr, opts, 2);
	temp = curr->current_position + num;
	check_arena(&temp, opts);
	insert_in_carriage_list(opts->list, -(curr->reg[0]), temp);
	carriage_copy(curr, *(opts->list));
}

void		aff(t_carriage *curr, t_cwoptions *opts)
{
	char			*temp;

	if (!opts->flag_a)
		return ;
	temp = curr->current_position;
	temp += 2;
	check_arena(&temp, opts);
	ft_printf("Aff: %c\n", (char)curr->reg[*temp - 1]);
}
