/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:01:09 by clianne           #+#    #+#             */
/*   Updated: 2019/11/04 03:49:03 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*
**	max out of 2 int
*/

int		ft_max2(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

/*
**	max out of 3 int
*/

int		ft_max3(int a, int b, int c)
{
	int		m;

	m = ft_max2(a, b);
	return (ft_max2(m, c));
}

/*
**	min out of 2 int
*/

int		ft_min2(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/*
**	min out of 2 int
*/

int		ft_min3(int a, int b, int c)
{
	int		m;

	m = ft_min2(a, b);
	return (ft_min2(m, c));
}

void	do_power5(int *la, int power)
{
	int	*la_tmp;

	la_tmp = do_iarray_create(LA_MAXLEN + 1);
	la_tmp[0] = 1;
	la_tmp[LA_MAXLEN + 1] = 1;
	fast_power(la_tmp, power, 5);
	if (!(la_tmp = do_la_reverse_qp(la_tmp, do_la_get_qty(la_tmp), power)))
		return ;
	do_rla_add_la(la, la_tmp);
	do_iarray_del(&la_tmp);
}
