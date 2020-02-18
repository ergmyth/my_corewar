/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:56:42 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/18 20:05:54 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_for_errors(t_s *s, int res)
{
	if (!s->has_name || !s->has_comment)
		case_of_error(ERR_NAME_OR_COMMENT, s->line_index + 1);
	else if (res == 0 && !s->op[s->op_i]->l[0])
		case_of_error(ERR_NO_CODE, 0);
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
	check_for_errors(s, res);
	if (!(str = pf_hex(res)))
		case_of_error(ERR_MALLOC, s->line_index + 1);
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
			commands_to_code(av, s);
		}
		else
			ft_putendl_fd(USAGE, 1);
		close(s->fd);
		free_struct(s);
	}
	else
		print_func(USAGE, av[1]);
	return (0);
}
