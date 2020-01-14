/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtoend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:01:05 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/15 11:22:11 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_list_clear(t_list **new_list)
{
	t_list *list;
	t_list *list2;

	list = *new_list;
	while (list)
	{
		list2 = list->next;
		free(list->content);
		free(list);
		list = list2;
	}
	free(*new_list);
	*new_list = NULL;
}

static	void	ft_adding_loop(t_list *lst, t_list *(*f)(t_list *elem),
		t_list **new_list)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = f(lst);
		tmp = ft_lstnew(tmp->content, tmp->content_size);
		if (!tmp)
		{
			ft_list_clear(new_list);
			return ;
		}
		ft_lstaddtoend(new_list, tmp);
		lst = lst->next;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*tmp;

	new_list = NULL;
	tmp = NULL;
	if (lst && f)
	{
		tmp = f(lst);
		new_list = ft_lstnew(tmp->content, tmp->content_size);
		if (!new_list)
			return (NULL);
		lst = lst->next;
		if (lst)
			ft_adding_loop(lst, f, &new_list);
		return (new_list);
	}
	return (NULL);
}
