/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_file_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:43:52 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/10 14:28:08 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int			do_file_option(t_options options, void *data)
{
	int		fd;
	char	*line;
	int		n;
	int		len;

	n = 0;
	len = 0;
	options.type = 'm';
	if ((fd = open((char *)data, O_RDONLY)) == -1)
		return (-1);
	while ((n = get_next_line(fd, &line)) != 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		len += ft_strlen(line);
		free(line);
	}
	if (n == -1 || close(fd) == -1)
		return (-1);
	return (len);
}
