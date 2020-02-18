/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:02:54 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 11:04:44 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
** long arithmetic: division la on int to new la
*/

int		*do_la_div_int_tonew(int *la_int, int a)
{
	int	idx;
	int	*la_res;
	int	c;
	int	sign;

	if (a == 0 || !(la_res = do_iarray_create(LA_MAXLEN + 1)))
		return (NULL);
	idx = la_int[LA_MAXLEN + 1] - 1;
	c = 0;
	sign = (a >= 0) ? 0 : 1;
	sign = sign ^ la_int[LA_MAXLEN];
	a = ft_abs(a);
	while (idx >= 0)
	{
		c = c * LA_BASE + la_int[idx];
		la_res[idx] = c / a;
		c = c % a;
		idx--;
	}
	la_res[LA_MAXLEN] = sign;
	return (la_res);
}

/*
** long arithmetic: division la on int to la
*/

void	do_la_div_int(int *la_int, int a)
{
	int	idx;
	int	c;
	int	sign;

	idx = la_int[LA_MAXLEN + 1] - 1;
	c = 0;
	sign = (a >= 0) ? 0 : 1;
	sign = sign ^ la_int[LA_MAXLEN];
	a = ft_abs(a);
	while (idx >= 0)
	{
		c = c * LA_BASE + la_int[idx];
		la_int[idx] = c / a;
		c = c % a;
		if (la_int[idx] == 0 && la_int[LA_MAXLEN + 1] - 1 == idx)
			la_int[LA_MAXLEN + 1]--;
		idx--;
	}
	la_int[LA_MAXLEN] = sign;
}

/*
** long arithmetic: division rla on int to rla
*/

void	do_rla_div_int(int *la_int, int a)
{
	int	idx;
	int	c;
	int	sign;

	idx = 0;
	c = 0;
	sign = (a >= 0) ? 0 : 1;
	sign = sign ^ la_int[LA_MAXLEN];
	a = ft_abs(a);
	while (idx < la_int[LA_MAXLEN + 1] || c != 0)
	{
		c = c * LA_BASE + la_int[idx];
		la_int[idx] = c / a;
		c = c % a;
		idx++;
	}
	la_int[LA_MAXLEN + 1] = idx;
	la_int[LA_MAXLEN] = sign;
}
