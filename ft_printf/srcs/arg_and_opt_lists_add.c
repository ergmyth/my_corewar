/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_and_opt_lists_add.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:11:06 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/29 15:50:02 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int		insert(t_options options, t_va_arg *first, int flag)
{
	t_va_arg		*temp;

	temp = first->next;
	first->next = create_node(options.argnum - 1, flag);
	if (!(first->next))
		return (0);
	first->next->next = temp;
	return (1);
}

int				create_argnum(t_options options, t_va_arg **head, int flag,
						size_t *idx)
{
	t_va_arg		*first;

	first = (*head);
	if (first->idx > options.argnum - 1)
	{
		(*head) = create_node(options.argnum - 1, flag);
		if (!(*head))
			return (0);
		(*head)->next = first;
	}
	while (first->next && first->next->idx < options.argnum - 1)
		first = first->next;
	if (first->idx == options.argnum - 1 && first->flag != flag)
		return (0);
	if (first->idx == options.argnum - 1 && first->flag == flag)
		return (1);
	if (first->next && first->next->idx > options.argnum - 1 &&
		!insert(options, first, flag))
		return (0);
	if (!(first->next) &&
		!(first->next = create_node(options.argnum - 1, flag)))
		return (0);
	*idx = options.argnum;
	return (1);
}

void			free_list(t_va_arg **list)
{
	t_va_arg		*temp;

	temp = 0;
	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		(*list) = temp;
	}
	*list = 0;
}
