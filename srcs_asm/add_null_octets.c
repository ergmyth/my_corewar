/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_null_octets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:00:33 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/31 18:09:55 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	add_null_octets(t_s *s)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(s->byte_code);
	while (i < 8)
	{
		s->byte_code[len + i] = '0';
		i++;
	}
	return (len + i - 1);
}
