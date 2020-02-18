/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:47:16 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/20 18:46:53 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;
	size_t	t;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		str = (char*)malloc(size + 1);
		if (!str)
			return (NULL);
		str[size] = '\0';
		t = 0;
		while (s1[t])
		{
			str[t] = s1[t];
			t++;
		}
		size = t;
		t = 0;
		while (s2[t] && (str[size + t] = s2[t]))
			t++;
		return (str);
	}
	return (NULL);
}
