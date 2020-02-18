/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:09:45 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/20 18:44:21 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	index;

	index = 0;
	if (s)
	{
		substr = (char*)malloc(len + 1);
		if (!substr)
			return (NULL);
		substr[len] = '\0';
		while (index < len)
		{
			substr[index] = s[start + index];
			index++;
		}
		return (substr);
	}
	return (NULL);
}
