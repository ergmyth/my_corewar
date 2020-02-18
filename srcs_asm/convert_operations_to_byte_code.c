/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_operations_to_byte_code.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:02:26 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/31 17:57:14 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	add_command_index(int *len, t_op_elem *cur_op, t_s *s)
{
	int		n;
	char	*temp;

	if (!(temp = ft_strnew(3)))
		case_of_error(ERR_MALLOC, 0);
	n = g_op_tab[cur_op->index].index;
	if (n % 16)
	{
		temp[0] = '0';
		temp[1] = (n % 16 < 10) ? (n % 16) + 48 : (n % 16) + 87;
	}
	else
	{
		temp[0] = '1';
		temp[1] = '0';
	}
	add_arg(len, temp, s);
	return (n);
}

static void	add_code_types(t_s *s, int *len, t_op_elem *cur_op)
{
	char	*binary;
	int		i;
	char	*hex;

	if (!(binary = ft_strnew(9)))
		case_of_error(ERR_MALLOC, 0);
	i = 0;
	while (i < 3 && cur_op->args[i] > 0)
	{
		if (cur_op->args[i] == 1)
			ft_strcat(binary, "01");
		else if (cur_op->args[i] == 2)
			ft_strcat(binary, "10");
		else if (cur_op->args[i] == 4)
			ft_strcat(binary, "11");
		i++;
	}
	while (i++ <= 3)
		ft_strcat(binary, "00");
	if (!(hex = btoh(binary)))
		case_of_error(ERR_MALLOC, 0);
	add_arg(len, hex, s);
	ft_strdel(&binary);
}

void		convert_operations_to_byte_code(t_s *s)
{
	int			i;
	t_op_elem	*cur_op;
	int			len;
	int			res;

	i = 0;
	len = (int)ft_strlen(s->byte_code);
	while (i < s->op_i)
	{
		cur_op = s->op[i];
		res = add_command_index(&len, cur_op, s);
		if (res != 1 && res != 9 && res != 12 && res != 15)
			add_code_types(s, &len, cur_op);
		add_args_code(&len, cur_op, s);
		i++;
	}
}
