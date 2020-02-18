/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:20:20 by clianne           #+#    #+#             */
/*   Updated: 2020/02/15 09:12:03 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** to free memory of players
*/

void		player_free(t_player *players, int q_players)
{
	int		idx;

	idx = 0;
	while (idx < q_players)
	{
		ft_strdel(&players[idx].filename);
		ft_strdel(&players[idx].name);
		ft_strdel(&players[idx].comment);
		free(players[idx].exec_code);
		idx++;
	}
}

/*
** to intit array of players
*/

void		player_init(t_player *players, int q_players)
{
	int		idx;

	idx = 0;
	while (idx < q_players)
	{
		players[idx].id = 0;
		players[idx].name = (char *)malloc(sizeof(char) * PROG_NAME_LENGTH
			+ 1);
		players[idx].name[PROG_NAME_LENGTH] = '\0';
		players[idx].magic_code = 0;
		players[idx].comment = (char *)malloc(sizeof(char) * COMMENT_LENGTH
			+ 1);
		players[idx].size_exec_code = 0;
		players[idx].exec_code = 0;
		players[idx].start_offset = 0;
		players[idx].name[sizeof(int)] = '\0';
		players[idx].comment[COMMENT_LENGTH] = '\0';
		players[idx].ch_size = 2 * sizeof(int) + PROG_NAME_LENGTH + 8 +
			COMMENT_LENGTH;
		idx++;
	}
}

/*
** to return quantity of players counting on input params
*/

int			players_get_q(int gc, char **gv)
{
	int		idx;
	int		q_players;

	q_players = 0;
	idx = 1;
	while (idx < gc)
	{
		if (!ft_strcmp(gv[idx], "-n") || !ft_strcmp(gv[idx], "-dump")
			|| !ft_strcmp(gv[idx], "-d")
			|| !ft_strcmp(gv[idx], "-a") || !ft_strcmp(gv[idx], "-l"))
		{
			if (!ft_strcmp(gv[idx], "-n") || !ft_strcmp(gv[idx], "-dump")
			|| !ft_strcmp(gv[idx], "-d"))
				idx++;
		}
		else
			q_players++;
		idx++;
	}
	return (q_players);
}

/*
** to get number of player:  first item of array with id = 0
*/

int			player_get_number(t_player *players, int q_players)
{
	int		idx;

	idx = 0;
	while (idx < q_players)
	{
		if (players[idx].id == 0)
			return (idx);
		idx++;
	}
	return (-1);
}

/*
** to save player with id & filename
*/

int			player_save(t_player *players, int player_n, char *fname)
{
	if (player_n < 1 || player_n > MAX_PLAYERS)
		return (0);
	players[player_n - 1].id = player_n;
	players[player_n - 1].filename = ft_strdup(fname);
	return (1);
}
