/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:53:40 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/13 16:23:46 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

static void	introduction(t_player **player, t_cwoptions *opts)
{
	int		i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < opts->q_players)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				(*player)[i].id, (*player)[i].size_exec_code, (*player)[i].name,
														(*player)[i].comment);
		i++;
	}
}

static void	inner_cycle(t_cwoptions *opts)
{
	t_carriage		*curr;

	curr = *(opts->list);
	while (curr)
	{
		if (curr->cycles_countdown == -1)
			state_opcode(curr, opts);
		if (curr->cycles_countdown > 0 && opts->q_cycles > 0)
			curr->cycles_countdown--;
		if (curr->cycles_countdown == 0 && opts->q_cycles > 0)
		{
			exec_op(curr, opts);
			curr->cycles_countdown = -1;
		}
		curr = curr->next;
	}
}

static void	cw_check(t_cwoptions *opts)
{
	delete_old_carriage(opts);
	opts->q_checks_performed++;
	if (opts->q_live_operations >= NBR_LIVE ||
		opts->q_checks_performed == MAX_CHECKS)
	{
		opts->cycles_to_die -= CYCLE_DELTA;
		opts->q_checks_performed = 0;
	}
	opts->q_live_operations = 0;
}

static void	game_begins(t_player **players, t_cwoptions *opts)
{
	int			count;

	count = 0;
	while (*(opts->list))
	{
		inner_cycle(opts);
		if (opts->q_cycles == opts->dump)
		{
			display_arena(opts);
			exit(0);
		}
		if (count == opts->cycles_to_die || opts->cycles_to_die <= 0)
		{
			cw_check(opts);
			count = 0;
		}
		opts->q_cycles++;
		count++;
	}
	count = opts->last_alive_player;
	ft_printf("Contestant %d, \"%s\", has won !\n",
					(*players)[count - 1].id, (*players)[count - 1].name);
	exit(0);
}

void		game(t_player **players, t_cwoptions *opts)
{
	create_arena(opts, players);
	create_list(players, opts);
	introduction(players, opts);
	opts->players = players;
	opts->q_live_operations = 0;
	opts->q_checks_performed = 0;
	game_begins(players, opts);
}
