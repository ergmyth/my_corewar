/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:54:41 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 11:05:25 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				*do_la_reverse(int *la)
{
	int		*la_res;
	int		idx;
	int		ndx;

	if (!(la_res = do_iarray_create(LA_MAXLEN + 1)))
	{
		do_iarray_del(&la);
		return (NULL);
	}
	idx = LA_MAXLEN - 1;
	while (idx >= 0 && la[idx] == 0)
		idx--;
	ndx = 0;
	while (idx >= 0)
	{
		la_res[ndx] = la[idx];
		idx--;
		ndx++;
	}
	la_res[LA_MAXLEN] = la[LA_MAXLEN];
	do_iarray_del(&la);
	return (la_res);
}

static void		do_tmp_rev(int *la, int *la_res, int qty, int power)
{
	int	idx;
	int	ndx;

	idx = la[LA_MAXLEN + 1] - 1;
	ndx = (power > qty) ? (power - qty) / LA_BASELEN : 0;
	while (idx >= 0)
	{
		la_res[ndx] = la[idx];
		idx--;
		ndx++;
	}
	la_res[LA_MAXLEN + 1] = ndx;
}

int				*do_la_reverse_qp(int *la, int qty, int power)
{
	int		*la_res;
	int		q;
	int		a;

	q = (power - qty) % LA_BASELEN;
	a = LA_BASELEN - qty % LA_BASELEN;
	if (q < a)
		do_la_mult_int(la, ft_power(10, a - q));
	else if (q > a)
		do_la_mult_int(la, ft_power(10, LA_BASELEN - (q - a)));
	if (!(la_res = do_iarray_create(LA_MAXLEN + 1)))
	{
		do_iarray_del(&la);
		return (NULL);
	}
	do_tmp_rev(la, la_res, qty, power);
	do_iarray_del(&la);
	return (la_res);
}
