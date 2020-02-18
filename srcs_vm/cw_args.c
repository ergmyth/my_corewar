/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:20:01 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/07 11:31:29 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

int					get_one_arg(char **temp, unsigned char code,
									t_carriage *curr, t_cwoptions *opts)
{
	int			num;
	char		*mod_temp;

	num = 0;
	if (code == 1)
	{
		num = curr->reg[**temp - 1];
		(*temp)++;
	}
	else if (code == 2)
		num = get_int(temp, curr, opts, 0);
	else if (code == 3)
	{
		mod_temp = curr->current_position +
					get_int(temp, curr, opts, 2) % IDX_MOD;
		check_arena(&mod_temp, opts);
		num = get_int(&mod_temp, curr, opts, 4);
	}
	check_arena(temp, opts);
	return (num);
}

int					get_one_arg_no_md(char **temp, unsigned char code,
									t_carriage *curr, t_cwoptions *opts)
{
	int			num;
	char		*mod_temp;

	num = 0;
	if (code == 1)
	{
		num = curr->reg[**temp - 1];
		(*temp)++;
	}
	else if (code == 2)
		num = get_int(temp, curr, opts, 0);
	else if (code == 3)
	{
		mod_temp = curr->current_position +
					get_int(temp, curr, opts, 2);
		check_arena(&mod_temp, opts);
		if (curr->op_code == 0x0d)
			num = get_int(&mod_temp, curr, opts, 2);
		else
			num = get_int(&mod_temp, curr, opts, 4);
	}
	check_arena(temp, opts);
	return (num);
}
