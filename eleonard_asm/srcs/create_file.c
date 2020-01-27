/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:32:44 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/27 18:09:08 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void 	create_file(char **av, char *str)
{
	int 	fd;
	char	*name;
	char	*temp;
	int 	len;

	len = (int)ft_strlen(av[1]);
	temp = av[1];
	temp[len - 1] = 0;
	name = ft_strjoin(av[1], "cor");
	fd = open(name, O_CREAT | O_WRONLY, 1023);
	write(fd, str, ft_strlen(str));
	close(fd);
	ft_strdel(&name);
}
