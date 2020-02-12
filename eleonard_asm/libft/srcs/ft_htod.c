/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:00:40 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/12 14:06:27 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	char2int(unsigned chr)
{
	if (chr >= '0' && chr <= '9')
		return (chr - '0');
	else if (chr >= 'a' && chr <= 'f')
		return (chr - 'a' + 10);
	return (-1);
}

unsigned char		ft_htod(char *str)
{
	unsigned int	res;
	int				i;
	int				step;

	step = 0;
	i = (int)ft_strlen(str);
	res = 0;
	while (--i > -1)
		res += char2int(str[i]) * ft_recursive_power(16, step++);
	return ((unsigned char)res);
}
