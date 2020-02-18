/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:57:46 by clianne           #+#    #+#             */
/*   Updated: 2019/10/26 14:49:24 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_la_round(int *la_int, int q, int *num)
{
	int	*la_tmp;
	int	idx;
	int	round;

	round = (q > LA_MAXLEN * LA_BASELEN) ? 0 : rounding(la_int, q, num);
	if (round == 0)
		return (0);
	if (q == 0)
		return (round);
	if (!(la_tmp = do_rla_create_from_str("1")))
		return (0);
	idx = 1;
	while (idx < q)
	{
		do_rla_div_int(la_tmp, 10);
		idx++;
	}
	round = do_rla_add_la(la_int, la_tmp);
	do_iarray_del(&la_tmp);
	return (round);
}
