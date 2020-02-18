/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:39:33 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/13 15:54:36 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*arr;

	i = 0;
	if (size + 1 < size)
		return (NULL);
	arr = (char*)malloc(sizeof(*arr) * (size + 1));
	if (arr == NULL)
		return (NULL);
	while (i < size + 1)
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}
