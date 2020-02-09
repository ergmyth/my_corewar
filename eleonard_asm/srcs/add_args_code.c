/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:00:23 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/31 18:11:04 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	additional_code(char *str)
{
	int	len;
	int	i;

	len = (int)ft_strlen(str);
	i = 0;
	while (str && str[i])
		if (str[i++] == '0')
			break ;
	if (i == len)
		return ;
	while (--len > -1)
	{
		if (str[len] == '1')
			str[len] -= 1;
		else
		{
			str[len] += 1;
			break ;
		}
	}
}

static char	*get_str(char *temp, int size)
{
	int		i;
	char	*str;
	int		len;

	if (!(str = ft_strnew(size)))
		case_of_error(ERR_MALLOC);
	i = 0;
	len = (int)ft_strlen(temp);
	while (i < size - len)
		str[i++] = '0';
	ft_strcat(str, temp);
	ft_strdel(&temp);
	return (str);
}

static char	*get_arg(char *value, int size)
{
	int		int_val;
	char	*temp;
	char	*str;

	int_val = ft_atoi(value);
	str = get_str(ft_itob(int_val), size * 8);
	if (int_val < 0)
	{
		ft_rev_binary(str);
		additional_code(str);
	}
	temp = btoh(str);
	ft_strdel(&str);
	str = get_str(temp, size * 2);
	return (str);
}

static void	add_arg(int *len, char *command_code, t_s *s)
{
	int i;

	i = 0;
	while (command_code && command_code[i])
	{
		if (*len >= s->byte_code_size)
		{
			s->byte_code_size += 1000;
			s->byte_code = (char*)realloc(s->byte_code, s->byte_code_size);
			s->byte_code[s->byte_code_size - 1] = 0;
		}
		s->byte_code[*len] = command_code[i];
		(*len)++;
		i++;
	}
	ft_strdel(&command_code);
}

void		add_args_code(int *len, t_op_elem *cur_op, t_s *s)
{
	int		i;
	char	*res;

	i = 0;
	while (i < s->op_tab[cur_op->index].arg_count)
	{
		if (cur_op->args[i] == 1)
			res = get_arg(cur_op->value[i], 1);
		else if (cur_op->args[i] == 2)
		{
			if (s->op_tab[cur_op->index].dir_size == 1)
				res = get_arg(cur_op->value[i], 2);
			else
				res = get_arg(cur_op->value[i], 4);
		}
		else if (cur_op->args[i] == 4)
			res = get_arg(cur_op->value[i], 2);
		add_arg(len, res, s);
		i++;
	}
}
