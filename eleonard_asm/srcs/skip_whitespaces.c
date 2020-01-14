/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:48:00 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/14 14:57:17 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char		*skip_whitespaces(char *line)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	k;

	k = 0;
	len = ft_strlen(line);
	if (!(str = (char*)malloc(len + 1)))
		case_of_error();
	i = 0;
	while (i < len)
	{
		while (is_space(line[i]) && !is_space(line[i + 1]))
			i++;
		if (line[i] == '\t')
			str[k] = ' ';
		else
			str[k] = line[i++];
		k++;
	}
	str[i] = 0;
	return (str);	
}
