/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:38:33 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/09 17:00:27 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			ch[i] = f(i, *s);
			i++;
			s++;
		}
		return (ch);
	}
	return (NULL);
}
