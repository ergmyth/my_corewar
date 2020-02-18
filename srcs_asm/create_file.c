/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:32:44 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/31 18:10:46 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	wr_to_file(int fd, char *str)
{
	int				i;
	char			*code;
	unsigned char	b;
	const int		size = (int)ft_strlen(str);

	if (!(code = ft_strnew(2)))
		case_of_error(ERR_MALLOC, 0);
	i = 0;
	while (i < size)
	{
		code[0] = str[i];
		code[1] = str[i + 1];
		b = ft_htod(code);
		write(fd, &b, 1);
		i += 2;
	}
	ft_strdel(&code);
}

void		create_file(char **av, char *str)
{
	int			fd;
	char		*name;
	char		*temp;
	const int	len = (int)ft_strlen(av[1]);

	temp = av[1];
	temp[len - 1] = 0;
	name = ft_strjoin(av[1], "cor");
	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 384);
	if (fd == -1)
		case_of_error(ERR_FD, 0);
	wr_to_file(fd, str);
	print_func(PARSE_COMPLETE_MSG, name);
	close(fd);
	ft_strdel(&name);
}
