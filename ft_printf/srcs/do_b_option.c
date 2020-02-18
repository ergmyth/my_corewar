/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_b_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:08:26 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/02 12:34:43 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				do_b_option(t_options node, void *data)
{
	unsigned long long	mask;
	long long			test;
	int					i;

	node.type = 'b';
	test = (long long)data;
	mask = 1LL << 63;
	i = 0;
	while (mask)
	{
		if (mask & test)
			ft_putchar('1');
		else
			ft_putchar('0');
		if (!(++i % 8) && i != 64)
			ft_putchar(' ');
		mask >>= 1;
	}
	return (1);
}
