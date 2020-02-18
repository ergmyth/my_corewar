/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:37:04 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/09 18:50:28 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!*find)
		return ((char*)src);
	while (src[i] && i < len)
	{
		k = 0;
		while (src[k + i] == find[k] && i + k < len)
			if (++k && !find[k])
				return ((char*)src + i);
		i++;
	}
	return (0);
}
