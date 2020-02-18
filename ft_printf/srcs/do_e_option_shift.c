/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_e_option_shift.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:23:03 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 11:28:05 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		do_tmp_e_shift(int *la, int *num, int m_shift)
{
	int	idx;
	int	*la_m1;
	int	*la_m2;
	int	*la_m3;

	la_m1 = do_la_copy(num);
	idx = 1;
	while (idx++ <= m_shift)
	{
		do_rla_div_int(la, 10);
		do_la_div_int(num, 10);
	}
	la_m2 = do_la_copy(num);
	idx = 1;
	while (idx++ <= m_shift)
		do_la_mult_int(la_m2, 10);
	la_m3 = do_la_sub_tonewla(la_m1, la_m2);
	la_m3 = do_la_reverse_qp(la_m3, do_la_get_qty(la_m3),
		do_la_get_qty(la_m3));
	do_rla_add_la(la, la_m3);
	do_iarray_del(&la_m1);
	do_iarray_del(&la_m2);
	do_iarray_del(&la_m3);
}

void			do_e_shift(int *la, int *num, int m_shift)
{
	int	idx;

	if (m_shift > 0)
	{
		do_tmp_e_shift(la, num, m_shift);
	}
	else if (m_shift < 0)
	{
		idx = 0;
		while (idx < ft_abs(m_shift))
		{
			do_rla_mult_int(la, 10);
			idx++;
		}
	}
}
