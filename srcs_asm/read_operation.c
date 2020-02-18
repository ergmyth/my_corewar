/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:05:21 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:05:22 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*edit_str(char *str)
{
	char	*new_str;
	int		i;
	int		start_index;
	int		new_str_len;

	i = 0;
	while (is_space(str[i]))
		i++;
	start_index = i;
	while (str[i])
		if (str[i] == ALT_COMMENT_CHAR || str[i] == COMMENT_CHAR)
			break ;
		else
			i++;
	new_str_len = i - start_index;
	if (!(new_str = ft_strsub(str, start_index, new_str_len)))
		case_of_error(ERR_MALLOC, 0);
	return (new_str);
}

static char	*get_op_name(char *str, int *arg_index)
{
	char	*name;
	int		i;

	i = 0;
	if (!(name = ft_strnew(6)))
		case_of_error(ERR_MALLOC, 0);
	while (i < 5)
	{
		if (is_space(str[i]) || str[i] == '%' || str[i] == '-')
			break ;
		name[i] = str[i];
		i++;
	}
	*arg_index = ft_strlen(name);
	return (name);
}

static int	check_op_name(char *name, int *op_index)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(name, g_op_tab[i].name))
		{
			*op_index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

void		read_operation(char *line, t_s *s)
{
	char	*edited_str;
	char	*op_name;
	int		op_index;
	int		arg_index;

	op_index = -1;
	edited_str = edit_str(line);
	op_name = get_op_name(edited_str, &arg_index);
	if (check_op_name(op_name, &op_index))
	{
		s->op[s->op_i]->name = op_name;
		get_args(op_index, s, edited_str + arg_index);
	}
	else
		case_of_error(ERR_WRONG_OP_NAME, s->line_index);
	ft_strdel(&edited_str);
}
