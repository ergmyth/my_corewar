/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_bitwise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:43:14 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/13 15:58:17 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

unsigned char		*get_args(char arg_code, unsigned char arr[4])
{
	unsigned char	first;
	unsigned char	second;
	unsigned char	third;
	unsigned char	fourth;

	first = (arg_code & 0b10000000) >> 6;
	first |= (arg_code & 0b01000000) >> 6;
	second = (arg_code & 0b00100000) >> 4;
	second |= (arg_code & 0b00010000) >> 4;
	third = (arg_code & 0b00001000) >> 2;
	third |= (arg_code & 0b00000100) >> 2;
	fourth = arg_code & 0b00000010;
	fourth |= arg_code & 0b00000001;
	arr[0] = first;
	arr[1] = second;
	arr[2] = third;
	arr[3] = fourth;
	return (arr);
}

static int			get_int_standard(char **ptr, t_cwoptions *opts)
{
	int		num;
	int		i;

	num = 0;
	i = 0;
	while (i < 4)
	{
		num |= (unsigned char)(**ptr) << (8 * (3 - i));
		(*ptr)++;
		check_arena(ptr, opts);
		i++;
	}
	return (num);
}

int					get_int(char **ptr, t_carriage *curr,
							t_cwoptions *opts, int size)
{
	int		num;
	short	s_num;
	int		i;

	num = 0;
	s_num = 0;
	i = 0;
	if (((opts->op_tab)[curr->op_code - 1].dir_size == 0 && size != 2) ||
		size == 4)
		num = get_int_standard(ptr, opts);
	else if ((opts->op_tab)[curr->op_code - 1].dir_size == 1 ||
			size == 2)
	{
		while (i < 2)
		{
			s_num |= (unsigned char)(**ptr) << (8 * (1 - i));
			(*ptr)++;
			check_arena(ptr, opts);
			i++;
		}
		num = s_num;
	}
	check_arena(ptr, opts);
	return (num);
}

void				set_int(char *ptr, int num, t_cwoptions *opts)
{
	char		temp;

	temp = (num & 0xff000000) >> 24;
	*ptr = temp;
	ptr++;
	check_arena(&ptr, opts);
	temp = (num & 0x00ff0000) >> 16;
	*ptr = temp;
	ptr++;
	check_arena(&ptr, opts);
	temp = (num & 0x0000ff00) >> 8;
	*ptr = temp;
	ptr++;
	check_arena(&ptr, opts);
	temp = (num & 0x000000ff);
	*ptr = temp;
}

void				check_arena(char **curr, t_cwoptions *opts)
{
	int		delta;

	if (*curr - opts->arena >= MEM_SIZE)
	{
		delta = *curr - opts->arena - MEM_SIZE;
		delta %= MEM_SIZE;
		*curr = opts->arena + delta;
	}
	else if (*curr < opts->arena)
	{
		delta = opts->arena - *curr;
		delta %= MEM_SIZE;
		*curr = opts->arena + MEM_SIZE - delta;
	}
}
