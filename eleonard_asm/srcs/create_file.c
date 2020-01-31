/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:32:44 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:02:36 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	wr_to_file(int fd, char *str)
{
	int i;
	int k;
	int l;

	i = 0;
	while (str[i])
	{
		if (i && i % 32 == 0)
			write(fd, "\n", 1);
		else if (i && i % 4 == 0)
			write(fd, " ", 1);
		write(fd, &str[i], 1);
		i++;
	}
}

void	create_file(char **av, char *str)
{
	int		fd;
	char	*name;
	char	*temp;
	int		len;

	len = (int)ft_strlen(av[1]);
	temp = av[1];
	temp[len - 1] = 0;
	name = ft_strjoin(av[1], "cor");
	fd = open(name, O_CREAT | O_WRONLY, 384);
	if (fd == -1)
		case_of_error(ERR_FD);
	wr_to_file(fd, str);
	print_func(PARSE_COMPLETE_MSG, name);
	close(fd);
	ft_strdel(&name);
}
