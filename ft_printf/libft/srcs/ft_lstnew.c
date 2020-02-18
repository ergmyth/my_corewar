/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:31:44 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/03 13:42:55 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp)
	{
		if (content)
		{
			tmp->content = malloc(content_size);
			if (!(tmp->content))
			{
				free(tmp);
				return (NULL);
			}
			tmp->content = ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = content_size;
		}
		else
		{
			tmp->content_size = 0;
			tmp->content = NULL;
		}
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}
