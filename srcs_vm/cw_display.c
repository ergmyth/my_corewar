/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:46:40 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/15 09:10:37 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

void	display_memory(char *arena)
{
	int		counter;
	int		i;

	counter = 0;
	while (counter < MEM_SIZE)
	{
		ft_printf("0x%04x : ", counter);
		i = 0;
		while (i < 32)
		{
			ft_printf("%02x ", (unsigned char)*arena);
			arena++;
			i++;
		}
		ft_printf("\n");
		counter += 32;
	}
}

void	test_display(char *arena)
{
	int		counter;
	int		i;

	counter = 0;
	while (counter < MEM_SIZE)
	{
		ft_printf("0x%04x : ", counter);
		i = 0;
		while (i < 64)
		{
			ft_printf("%02x ", (unsigned char)*arena);
			arena++;
			i++;
		}
		ft_printf("\n");
		counter += 64;
	}
}

void	display_arena(t_cwoptions *opts)
{
	if (opts->flag_d == 1)
		display_memory(opts->arena);
	if (opts->flag_d == -1)
		test_display(opts->arena);
}
