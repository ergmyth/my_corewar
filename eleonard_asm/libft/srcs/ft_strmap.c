/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:22:02 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/10 17:33:40 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ch;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	ch = NULL;
	if (s)
	{
		size = ft_strlen(s);
		ch = ft_strnew(size);
		if (!ch)
			return (NULL);
		while (*s)
		{
			ch[i] = f(*s);
			i++;
			s++;
		}
		return (ch);
	}
	return (NULL);
}
