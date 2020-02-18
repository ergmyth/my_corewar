/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_check_code_inner_cycle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:19:07 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/15 12:44:15 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

static int		size_of_step(unsigned char *args, int size, int tdir_size)
{
	int		i;
	int		step;

	i = 0;
	if (size == 0)
		size = 3;
	step = 2;
	while (i < size)
	{
		if (args[i] == 0x1)
			step += 1;
		else if (args[i] == 0x2 && tdir_size)
			step += 2;
		else if (args[i] == 0x2 && !tdir_size)
			step += 4;
		else if (args[i] == 0x3)
			step += 2;
		i++;
	}
	return (step);
}

static int		check_reg(unsigned char *args, t_carriage *curr,
							t_cwoptions *opts)
{
	int				i;
	char			*temp;

	i = 0;
	temp = curr->current_position + 2;
	check_arena(&temp, opts);
	while (i < (opts->op_tab)[curr->op_code - 1].arg_count)
	{
		if (args[i] == 0x2 && (opts->op_tab)[curr->op_code - 1].dir_size)
			temp += 2;
		else if (args[i] == 0x2 &&
				!((opts->op_tab)[curr->op_code - 1].dir_size))
			temp += 4;
		else if (args[i] == 0x3)
			temp += 2;
		else if (args[i] == 0x01)
		{
			if (*temp < 0x01 || *temp > REG_NUMBER_VM)
				return (0);
			temp += 1;
		}
		check_arena(&temp, opts);
		i++;
	}
	return (1);
}

int				check_args(int *step, unsigned char *args, t_carriage *curr,
							t_cwoptions *opts)
{
	int		correct;
	int		i;
	int		*arr;

	i = 0;
	arr = (opts->op_tab)[curr->op_code - 1].arr;
	correct = 1;
	while (i < (opts->op_tab)[curr->op_code - 1].arg_count)
	{
		if ((arr[i] == 7 && args[i] == 0x0) ||
			(arr[i] == 6 && (args[i] != 0x2 && args[i] != 0x3)) ||
			(arr[i] == 5 && (args[i] != 0x1 && args[i] != 0x3)) ||
			(arr[i] == 3 && (args[i] != 0x1 && args[i] != 0x2)) ||
			(arr[i] == 2 && args[i] != 0x2) ||
			(arr[i] == 1 && args[i] != 0x1))
		{
			correct = 0;
			break ;
		}
		i++;
	}
	correct = correct == 0 ? 0 : check_reg(args, curr, opts);
	*step = size_of_step(args, (opts->op_tab)[curr->op_code - 1].arg_count,
						(opts->op_tab)[curr->op_code - 1].dir_size);
	return (correct);
}
