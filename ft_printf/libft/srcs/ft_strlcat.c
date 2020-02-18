/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:20:51 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/10 17:59:21 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((const char*)dest);
	if (size == 0)
		return (ft_strlen(src));
	if (size < len)
		return (size + ft_strlen(src));
	while (len + i < size - 1 && src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	if (len + i < size)
		dest[len + i] = '\0';
	return (len + ft_strlen(src));
}
