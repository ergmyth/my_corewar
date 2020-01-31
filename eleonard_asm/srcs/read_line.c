/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:04:50 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:04:52 by eleonard         ###   ########.fr       */
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
	int k;
	int size;

	k = 0;
	while (s->operations[s->oper_index].labels[k])
		k++;
	if (!(s->operations[s->oper_index].labels[k] = ft_strdup(label)))
		case_of_error(ERR_MALLOC);
	if (s->labels->labels_size == s->labels->label_index + 1)
	{
		s->labels->labels_size *= 2;
		size = (int)sizeof(char*) * s->labels->labels_size + 1;
		if (!(s->labels->labels = (char**)realloc(s->labels->labels, size)))
			case_of_error(ERR_MALLOC);
	}
	if (!(s->labels->labels[s->labels->label_index++] = ft_strdup(label)))
		case_of_error(ERR_MALLOC);
	ft_strdel(&label);
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
	if (!(label = ft_strsub(line, i, label_c_index)))
		case_of_error(ERR_MALLOC);
	if (is_label(label))
	{
		add_label(label, s);
		end = (int)ft_strlen(line) - label_c_index - 1;
		if (!(end_of_string = ft_strsub(line, label_c_index + 1, end)))
			case_of_error(ERR_MALLOC);
		if (!only_spaces(end_of_string))
			read_operation(end_of_string, s);
	}
	else
	{
		ft_strdel(&label);
		read_operation(line, s);
	}
	ft_strdel(&end_of_string);
}

void		read_line(char *line, t_s *s)
{
	int	label_c_index;

	label_c_index = get_symbol_index(line, LABEL_CHAR);
	if (label_c_index != -1)
		read_label(line, label_c_index, s);
	else
		read_operation(line, s);
}
