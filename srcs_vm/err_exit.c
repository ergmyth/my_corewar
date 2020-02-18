/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 07:41:18 by clianne           #+#    #+#             */
/*   Updated: 2020/02/14 08:08:19 by clianne          ###   ########.fr       */
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
