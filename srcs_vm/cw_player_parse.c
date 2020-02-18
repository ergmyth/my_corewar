/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_player_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:39:14 by clianne           #+#    #+#             */
/*   Updated: 2020/02/15 09:11:07 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>
#include <fcntl.h>

static int		get_int_code(unsigned int *buf_int1)
{
	return ((buf_int1[0] << 24) +
			(buf_int1[1] << 16) +
			(buf_int1[2] << 8) +
			(buf_int1[3]));
}

void			player_parse_part_25l(size_t idx, unsigned int *buf_int1,
	unsigned char buf[2], t_player *player)
{
	if (idx < sizeof(int))
	{
		buf_int1[idx] = (unsigned int)buf[0];
		if (idx == sizeof(int) - 1)
			player->magic_code = get_int_code(buf_int1);
	}
	else if (idx < sizeof(int) + PROG_NAME_LENGTH)
		player->name[idx - sizeof(int)] = (unsigned char)buf[0];
	else if (idx >= 2 * sizeof(int) + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH)
	{
		if (idx == 2 * sizeof(int) + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH)
		{
			player->exec_code = (char *)malloc(sizeof(char) *
				player->size_exec_code);
			ft_bzero(player->exec_code, player->size_exec_code);
		}
		if ((int)(idx - player->ch_size) > player->size_exec_code - 1)
			ret_file_error("Error: File ", player->filename,
			" has a code size that differ from what its header says\n", -1);
		player->exec_code[idx - player->ch_size] = (unsigned char)buf[0];
	}
	else if (idx >= 2 * sizeof(int) + PROG_NAME_LENGTH + 4 &&
		idx < 2 * sizeof(int) + PROG_NAME_LENGTH + 4 + COMMENT_LENGTH)
		player->comment[idx - (2 * sizeof(int) + PROG_NAME_LENGTH + 4)] =
			(int)buf[0];
}

/*
** to check structure of player file
*/

void			player_file_check_read_parse(int fd, t_player *player)
{
	size_t			idx;
	unsigned int	buf_int1[4];
	unsigned int	buf_int2[4];
	unsigned char	buf[2];

	idx = 0;
	while (read(fd, buf, 1) > 0)
	{
		if (idx >= sizeof(int) + PROG_NAME_LENGTH + 4 &&
				idx < 2 * sizeof(int) + PROG_NAME_LENGTH + 4)
		{
			buf_int2[idx - (sizeof(int) + PROG_NAME_LENGTH + 4)] =
				(unsigned int)buf[0];
			if (idx == 2 * sizeof(int) + PROG_NAME_LENGTH + 3)
				player->size_exec_code = get_int_code(buf_int2);
		}
		else
			player_parse_part_25l(idx, buf_int1, buf, player);
		idx++;
	}
	if (player->size_exec_code != 0 &&
		(int)(idx - player->ch_size) != player->size_exec_code)
		ret_diff_size_error(player->filename);
	if (player->size_exec_code == 0 && idx < (player->ch_size))
		ret_small_champ_error(player->filename);
}

void			players_check_and_fill(t_player *players,
	t_cwoptions *cwoptions)
{
	int		idx;
	int		fd;

	idx = 0;
	while (idx < cwoptions->q_players)
	{
		if ((fd = open(players[idx].filename, O_RDONLY)) == -1)
			ret_file_error("Error: unable to open file ", players[idx].filename,
				"\n", -1);
		player_file_check_read_parse(fd, &players[idx]);
		close(fd);
		if (players[idx].magic_code != COREWAR_EXEC_MAGIC ||
			players[idx].size_exec_code >= CHAMP_MAX_SIZE)
			ret_file_error("Error: failed exec_code data in the file ",
				players[idx].filename, "\n", -1);
		idx++;
	}
}
