/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:33:44 by clianne           #+#    #+#             */
/*   Updated: 2020/02/19 21:23:38 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

int			main(int gc, char **gv)
{
	t_cwoptions	cwoptions;
	t_player	*players;

	if (gc < 2)
		ret_usage();
	cwoptions.q_players = players_get_q(gc, gv);
	cwoptions.list = (t_carriage**)malloc(sizeof(t_carriage*));
	cwoptions.q_cycles = 0;
	cwoptions.dump = -1;
	cwoptions.flag_a = 0;
	cwoptions.flag_l = 0;
	cwoptions.flag_d = -1;
	cwoptions.gc = gc;
	if (cwoptions.q_players < 1 || cwoptions.q_players > MAX_PLAYERS)
		ret_file_error("Error: failed quantity of players",
			" (less than 1 or more than MAX_PLAYERS)", "\n", -1);
	cwoptions.cycles_to_die = CYCLE_TO_DIE;
	players = main_wrap(gc, gv, &cwoptions);
	get_commands(&cwoptions);
	game(&players, &cwoptions);
	return (0);
}
