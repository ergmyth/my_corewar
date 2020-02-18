/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:01:22 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:01:24 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	btoi(char *str)
{
	int	res;
	int	len;
	int	i;

	i = 0;
	res = 0;
	len = (int)ft_strlen(str);
	while (--len > -1)
	{
		if (str[len] == '1')
			res += ft_recursive_power(2, i);
		i++;
	}
	return ((unsigned int)res);
}
