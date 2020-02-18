/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:04:50 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/18 20:01:48 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_label(char *label)
{
	int i;

	i = 0;
	while (label[i])
	{
		if (!ft_strchr(LABEL_CHARS, label[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	add_label(char *label, t_s *s)
{
	size_t	size;
	int		k;

	size = 0;
	while (s->op[s->op_i]->l[size])
		size++;
	if ((int)size == s->op[s->op_i]->l_size - 1)
	{
		s->op[s->op_i]->l_size *= 2;
		if (!(s->op[s->op_i]->l = (char**)realloc(s->op[s->op_i]->l,
				sizeof(char*) * s->op[s->op_i]->l_size)))
			case_of_error(ERR_MALLOC, 0);
		k = s->op[s->op_i]->l_size / 2;
		while (k < s->op[s->op_i]->l_size)
			s->op[s->op_i]->l[k++] = 0;
	}
	if (!(s->op[s->op_i]->l[size] = ft_strdup(label)))
		case_of_error(ERR_MALLOC, 0);
}

static void	read_label(char *line, int label_c_index, t_s *s)
{
	int		i;
	char	*end_of_string;
	char	*label;
	int		end;

	i = 0;
	end_of_string = NULL;
	while (is_space(line[i]))
		i++;
	if (!(label = ft_strsub(line, i, label_c_index - i)))
		case_of_error(ERR_MALLOC, 0);
	if (is_label(label))
	{
		add_label(label, s);
		end = (int)ft_strlen(line) - label_c_index - 1;
		if (!(end_of_string = ft_strsub(line, label_c_index + 1, end)))
			case_of_error(ERR_MALLOC, 0);
		if (!only_spaces(end_of_string))
			read_operation(end_of_string, s);
	}
	else
		read_operation(line, s);
	ft_strdel(&label);
	ft_strdel(&end_of_string);
}

void		read_line(char *line, t_s *s)
{
	int	label_c_index;

	label_c_index = index_of(line, LABEL_CHAR);
	if (label_c_index != -1)
		read_label(line, label_c_index, s);
	else
		read_operation(line, s);
}
