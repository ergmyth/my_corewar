/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_and_opt_lists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:04:35 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/29 15:45:07 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*
** Create node for arguments list
*/

t_va_arg			*create_node(size_t idx, int flag)
{
	t_va_arg	*new;

	new = 0;
	new = (t_va_arg*)malloc(sizeof(t_va_arg));
	if (!new)
		return (0);
	new->idx = idx;
	new->data = 0;
	new->data1 = 0;
	new->next = 0;
	new->flag = flag;
	return (new);
}

/*
** Create list of arguments
*/

static int			create_head(t_options options, t_va_arg **head,
								int flag, size_t *idx)
{
	*idx = 0;
	if (options.argnum)
	{
		(*head) = create_node(options.argnum - 1, flag);
		*idx = options.argnum;
	}
	else
		(*head) = create_node((*idx)++, flag);
	if (!*head)
		return (0);
	return (1);
}

int					push_back(t_options options, t_va_arg **head, int flag)
{
	t_va_arg		*first;
	static size_t	idx;

	first = 0;
	if (!(*head))
		return (create_head(options, head, flag, &idx));
	else if (options.argnum)
		return (create_argnum(options, head, flag, &idx));
	else
	{
		first = (*head);
		while (first->next)
			first = first->next;
		first->next = create_node(idx++, flag);
		if (!(first->next))
			return (0);
	}
	return (1);
}

int					ret_get_list(t_va_arg **list, int a)
{
	free_list(list);
	return (a);
}

int					get_list(t_options options, t_va_arg **list)
{
	if (options.width == -2)
		if (!push_back(options, list, 0))
			return (ret_get_list(list, 0));
	if (options.precision == -2)
		if (!push_back(options, list, 0))
			return (ret_get_list(list, 0));
	if (options.type == '%')
		return (1);
	if (options.size && !ft_strcmp(options.size, "L"))
	{
		if (!push_back(options, list, 2))
			return (ret_get_list(list, 0));
	}
	else if (options.type == T_FLOAT || options.type == T_FFLOAT ||
	options.type == T_EFLOAT || options.type == T_EEFLOAT ||
	options.type == T_GFLOAT || options.type == T_GGFLOAT)
	{
		if (!push_back(options, list, 1))
			return (ret_get_list(list, 0));
	}
	else if (!push_back(options, list, 0))
		return (ret_get_list(list, 0));
	return (1);
}
