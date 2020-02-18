/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_mult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:06:03 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 13:20:49 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
** long arithmetic: mult la on int to la
*/

void		do_la_mult_int(int *la_int, int a)
{
	int	idx;
	int	c;
	int	sign;

	idx = 0;
	sign = (a >= 0) ? 0 : 1;
	sign = sign ^ la_int[LA_MAXLEN];
	a = ft_abs(a);
	c = 0;
	while (idx < la_int[LA_MAXLEN + 1] || c != 0)
	{
		c = c + la_int[idx] * a;
		la_int[idx] = c % LA_BASE;
		c = c / LA_BASE;
		idx++;
	}
	la_int[LA_MAXLEN + 1] = idx;
	la_int[LA_MAXLEN] = sign;
}

/*
** long arithmetic: mult la on la to new la
*/

int			*do_la_mult_int_tonewla(int *la_int, int a)
{
	int		idx;
	int		*la_res;
	int		c;
	int		sign;

	if (!(la_res = do_iarray_create(LA_MAXLEN + 1)))
		return (NULL);
	idx = 0;
	c = 0;
	sign = (a >= 0) ? 0 : 1;
	sign = sign ^ la_int[LA_MAXLEN];
	a = ft_abs(a);
	while (idx < la_int[LA_MAXLEN + 1] || c != 0)
	{
		c = c + la_int[idx] * a;
		la_res[idx] = c % LA_BASE;
		c = c / LA_BASE;
		idx++;
	}
	la_res[LA_MAXLEN] = sign;
	la_res[LA_MAXLEN + 1] = idx;
	return (la_res);
}

/*
** long arithmetic: mult la on la to new la (doesn't work)
*/

static void	mult(int *la, int *la_res)
{
	int		count;
	int		idx;
	int		ndx;
	int		c;

	count = do_la_qdigits(la);
	idx = 0;
	while (idx <= (count / LA_BASELEN + 1) && idx < LA_MAXLEN)
	{
		c = 0;
		ndx = 0;
		while (ndx <= (count / LA_BASELEN + 1) && idx + ndx + 1 < LA_MAXLEN)
		{
			c = la[idx] * la[ndx] + la_res[idx + ndx];
			la_res[idx + ndx] = c % LA_BASE;
			la_res[idx + ndx + 1] += c / LA_BASE;
			if (la_res[idx + ndx] != 0)
				la_res[LA_MAXLEN + 1] = idx + ndx + 1;
			ndx++;
		}
		idx++;
	}
}

void		do_la_mult_la(int *la)
{
	int	idx;
	int	la_res[LA_MAXLEN + 2];
	int	count;

	idx = 0;
	do_iarray_fill(la_res, LA_MAXLEN + 2, 0);
	mult(la, la_res);
	idx = -1;
	count = do_la_qdigits(la_res);
	while (++idx < (count / LA_BASELEN + 1))
		la[idx] = la_res[idx];
	la[LA_MAXLEN + 1] = la_res[LA_MAXLEN + 1];
}

/*
** long arithmetic: mult rla on int to la
*/

void		do_rla_mult_int(int *la_int, int a)
{
	int	idx;
	int	c;
	int	sign;

	idx = la_int[LA_MAXLEN + 1] - 1;
	sign = (a >= 0) ? 0 : 1;
	sign = sign ^ la_int[LA_MAXLEN];
	a = ft_abs(a);
	c = 0;
	while (idx >= 0)
	{
		c = c + la_int[idx] * a;
		la_int[idx] = c % LA_BASE;
		c = c / LA_BASE;
		idx--;
	}
	la_int[LA_MAXLEN] = sign;
}
