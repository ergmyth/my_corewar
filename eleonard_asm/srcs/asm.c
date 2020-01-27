/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:56:42 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/13 18:04:32 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_struct(t_s *s)
{
	int i;
	int k;

	ft_strdel(&s->byte_code);
	i = 0;
	while (i < s->operations_index)
	{
		ft_strdel(&s->operations[i].name);
		k = 0;
		while (s->operations[i].labels[k])
			ft_strdel(&s->operations[i].labels[k++]);
		ft_strdel(s->operations[i++].labels);
	}
}

int		main(int ac, char **av)
{
	t_s		*s;

	if (ac == 2)
	{
		s = initialize();
		s->fd = open(av[1], O_RDONLY);
		if (s->fd == -1)
			print_func(INVALID_READ_MSG, av[1]);
		else if (check_name(av[1]))
		{
			do_parse(s);
			if (check_labels(s))
			{
				convert_labels_to_numbers(s);
				convert_operations_to_byte_code(s);
				create_file(av, s->byte_code);
				print_func(PARSE_COMPLETE_MSG, av[1]);
			}
		}
		else
			print_func(USAGE, av[1]);//Не подходит имя, что делать
		free_struct(s);
	}
	else
		print_func(USAGE, av[1]);
	return (0);
}
