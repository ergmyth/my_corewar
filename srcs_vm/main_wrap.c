/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_wrap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:05:14 by clianne           #+#    #+#             */
/*   Updated: 2020/02/15 12:38:55 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_game.h"

static int		check_option_n(char *s_nplayer, t_cwoptions *cwoptions,
	t_player *players)
{
	int		player_n;

	if (!ft_isint(s_nplayer))
		ret_error("Error: failed value for option -n\n", -1);
	player_n = ft_atoi(s_nplayer);
	if (player_n < 1 || player_n > cwoptions->q_players)
		ret_file_error("Error: failed a number of the player for option -n: ",
		s_nplayer, " is less than 1 or more than max quantity of players\n",
		-1);
	if (players[player_n - 1].id != 0)
		ret_file_error("Error: a number of the player #", s_nplayer,
		" is busy\n", -1);
	return (player_n);
}

static void		check_options_al(char *value, t_cwoptions *cwoptions)
{
	if (!ft_strcmp(value, "-a"))
		cwoptions->flag_a = 1;
	else if (!ft_strcmp(value, "-l"))
		cwoptions->flag_l = 1;
}

static void		check_options_dump(int idx, int gc, char **gv,
	t_cwoptions *cwoptions)
{
	if (!ft_strcmp(gv[idx - 1], "-dump"))
	{
		if (idx >= gc)
			ret_error("Error: undefined value for option -dump\n", -1);
		else if (!ft_isint(gv[idx]))
			ret_error("Error: failed value for option -dump\n", -1);
		else
			cwoptions->dump = ft_atoi(gv[idx]);
	}
	else
	{
		if (idx >= gc)
			ret_error("Error: undefined value for option -d\n", -1);
		else if (!ft_isint(gv[idx]))
			ret_error("Error: failed value for option -d\n", -1);
		else
		{
			cwoptions->dump = ft_atoi(gv[idx]);
			cwoptions->flag_d = 1;
		}
	}
}

static void		get_option_n(int idx, char **gv, t_cwoptions *cwoptions,
	t_player *players)
{
	int			player_n;

	if (idx < cwoptions->gc)
	{
		player_n = check_option_n(gv[idx], cwoptions, players);
		if (++idx < cwoptions->gc)
			player_save(players, player_n, gv[idx]);
	}
	else
		ret_error("Error: undefined value for option [-n]\n", -1);
}

t_player		*main_wrap(int gc, char **gv, t_cwoptions *cwoptions)
{
	t_player	*players;
	int			idx;

	players = (t_player *)malloc(sizeof(t_player) * cwoptions->q_players);
	player_init(players, cwoptions->q_players);
	idx = 1;
	while (idx < gc)
	{
		if (!ft_strcmp(gv[idx], "-n"))
		{
			get_option_n(++idx, gv, cwoptions, players);
			idx++;
		}
		else if (!ft_strcmp(gv[idx], "-dump") || !ft_strcmp(gv[idx], "-d"))
			check_options_dump(++idx, gc, gv, cwoptions);
		else if (!ft_strcmp(gv[idx], "-a") || !ft_strcmp(gv[idx], "-l"))
			check_options_al(gv[idx], cwoptions);
		else
			player_save(players, player_get_number(players,
				cwoptions->q_players) + 1, gv[idx]);
		idx++;
	}
	cwoptions->last_alive_player = players[cwoptions->q_players - 1].id;
	players_check_and_fill(players, cwoptions);
	return (players);
}
