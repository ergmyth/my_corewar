/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:13:55 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/25 19:10:53 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*elem1;
	t_list	*elem2;

	elem1 = NULL;
	elem2 = NULL;
	if (*alst && del)
	{
		elem1 = *alst;
		while (elem1)
		{
			elem2 = elem1->next;
			del(elem1->content, elem1->content_size);
			elem1 = elem2;
			free(elem2);
		}
		free(*alst);
		*alst = NULL;
	}
}
