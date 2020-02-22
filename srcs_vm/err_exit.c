/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 07:41:18 by clianne           #+#    #+#             */
/*   Updated: 2020/02/22 14:09:43 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ret_error(char *msg, int code)
{
	ft_putstr_fd(msg, 2);
	exit(code);
}

int			ret_file_error(char *msg_1, char *msg_2, char *filename, int code)
{
	ft_putstr_fd(msg_1, 2);
	ft_putstr_fd(msg_2, 2);
	ft_putstr_fd(filename, 2);
	exit(code);
}

int			ret_diff_size_error(char *filename)
{
	ret_file_error("Error: File ", filename,
		" has a code size that differ from what its header says\n", -1);
	exit(-1);
}

int			ret_small_champ_error(char *filename)
{
	ret_file_error("Error: File ", filename,
		" is too small to be a champion\n", -1);
	exit(-1);
}

int			ret_usage(void)
{
	ft_putstr_fd("Usage:\n  corewar [-n <number> <num_player_file>] ", 2);
	ft_putstr_fd("[-dump <nbr_cycles>] [-d <nbr_cycles>] [-a] ", 2);
	ft_putstr_fd("<player_file> ... <player_file>\n", 2);
	ft_putstr_fd("  [-n <number> <num_player_file>] : ", 2);
	ft_putstr_fd("to set number for player <num_player_file>\n", 2);
	ft_putstr_fd("  [-dump <nbr_cycles>] : to print the memory ", 2);
	ft_putstr_fd("(64 octets per line) and quit the game at the end ", 2);
	ft_putstr_fd("of nbr_cycles of executions\n", 2);
	ft_putstr_fd("  [-d <nbr_cycles>] : to print the memory (32 ", 2);
	ft_putstr_fd("octets per line) as well as live operations and quit", 2);
	ft_putstr_fd(" the game at the end of nbr_cycles of executions\n", 2);
	ft_putstr_fd("  [-a] : to switch on display of <aff> ", 2);
	ft_putstr_fd("operation output\n", 2);
	ft_putstr_fd("  <player_file> : file name of champion\n", 2);
	exit(-1);
}
