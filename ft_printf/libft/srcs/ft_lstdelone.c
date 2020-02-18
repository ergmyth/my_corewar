/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:41:32 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/11 15:37:50 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;

	list = NULL;
	if (*alst && del)
	{
		list = *alst;
		del(list->content, list->content_size);
		free(*alst);
		*alst = NULL;
	}
}
