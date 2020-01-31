/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_by_zeroes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:02:54 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/31 17:57:51 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	fill_by_zeroes(char *str, int len)
{
	int	i;
	int	code_len;

	i = 0;
	code_len = (int)ft_strlen(str);
	while (i < len)
	{
		str[code_len + i] = '0';
		i++;
	}
}
