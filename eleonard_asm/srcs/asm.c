/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:56:42 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/31 18:05:03 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_struct(t_s *s)
{
	int i;
	int k;

	ft_strdel(&s->byte_code);
	i = 0;
	while (i < s->oper_index)
	{
		ft_strdel(&s->operations[i].name);
		k = 0;
		while (s->operations[i].labels[k])
			ft_strdel(&s->operations[i].labels[k++]);
		ft_strdel(s->operations[i].labels);
		k = 0;
		while (s->operations[i].args[k])
			ft_strdel(&s->operations[i].value[k++]);
		ft_strdel(s->operations[i++].value);
	}
	ft_memdel((void**)&s->operations);
	i = -1;
	k = 0;
	while (++i < s->labels->label_index)
		while (s->labels[i].labels[k])
			ft_strdel(&s->labels[i].labels[k++]);
	ft_memdel((void**)&s->labels->line);
	ft_memdel((void**)&s->labels->labels);
	ft_memdel((void**)&s->labels);
	ft_memdel((void**)&s);
}

static void	commands_to_code(char **av, t_s *s)
{
	int		res;
	char	*str;
	int		len;
	int		i;

	s->commands_start_ind = (int)ft_strlen(s->byte_code);
	convert_labels_to_numbers(s);
	convert_operations_to_byte_code(s);
	res = ((int)ft_strlen(s->byte_code) - s->commands_start_ind) / 2;
	if (res > CHAMP_MAX_SIZE)
		case_of_error(ERR_TOO_BIG_CHAMP_SIZE);
	if (!(str = pf_hex(res)))
		case_of_error(ERR_MALLOC);
	len = (int)ft_strlen(str);
	i = 0;
	while (len--)
	{
		s->byte_code[s->cec_ind - i] = str[len];
		i++;
	}
	ft_strdel(&str);
	create_file(av, s->byte_code);
}

int			main(int ac, char **av)
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
				commands_to_code(av, s);
		}
		else
			print_func(USAGE, av[1]);
		close(s->fd);
		free_struct(s);
	}
	else
		print_func(USAGE, av[1]);
	return (0);
}
