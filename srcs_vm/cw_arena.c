/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:11:49 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/13 15:54:08 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

static void		place_players_on_arena(t_cwoptions *opts, t_player **players,
									char *arena)
{
	int				i;
	int				j;
	char			*current_carriage;
	char			*current_exc_code;

	i = 0;
	j = 0;
	while (i < opts->q_players)
	{
		current_carriage = arena + (*players)[i].start_offset;
		current_exc_code = (*players)[i].exec_code;
		while (j++ < (*players)[i].size_exec_code)
		{
			*current_carriage = *current_exc_code;
			current_carriage++;
			current_exc_code++;
		}
		j = 0;
		i++;
	}
}

void			create_arena(t_cwoptions *opts, t_player **players)
{
	char			*arena;
	int				i;
	int				offset;

	arena = (char*)malloc(sizeof(char) * MEM_SIZE);
	ft_memset(arena, 0, MEM_SIZE);
	i = 0;
	offset = MEM_SIZE / opts->q_players;
	while (i < opts->q_players)
	{
		(*players)[i].start_offset = i * offset;
		i++;
	}
	place_players_on_arena(opts, players, arena);
	opts->arena = arena;
}
