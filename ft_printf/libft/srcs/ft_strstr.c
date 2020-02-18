/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 20:44:00 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/13 13:47:29 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!*to_find)
		return ((char*)str);
	while (str[i])
	{
		k = 0;
		while (str[k + i] == to_find[k])
			if (++k && !to_find[k])
				return ((char*)str + i);
		i++;
	}
	return (0);
}
