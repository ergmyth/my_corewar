/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:16:09 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/20 18:40:36 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	k;
	char	*str;

	i = 0;
	k = ft_strlen(src);
	str = (char*)malloc(k + 1);
	if (str == NULL)
		return (NULL);
	str[k] = '\0';
	while (i < k)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
