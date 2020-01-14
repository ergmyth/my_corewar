/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 09:57:59 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/09 17:08:50 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	start = 0;
	str = NULL;
	end = 0;
	len = 0;
	if (s)
	{
		len = ft_strlen(s);
		end = len;
		while (s[start] == '\t' || s[start] == '\n' || s[start] == ' ')
			start++;
		if (start == end)
			return (ft_strnew(0));
		while (end--)
			if ((s[end] != '\t' && s[end] != '\n' && s[end] != ' ') && end++)
				break ;
		if (start == 0 && end == len && (str = ft_strnew(len)))
			return (ft_strcpy(str, s));
		return (ft_strsub(s, (unsigned int)start, end - start));
	}
	return (NULL);
}
