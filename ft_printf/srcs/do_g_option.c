/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_g_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:13:18 by clianne           #+#    #+#             */
/*   Updated: 2019/10/26 15:16:07 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** to process mantissa
*/

static void		do_g_shift(int *la, int *num, int m_shift)
{
	int	*la_m1;
	int	*la_m2;
	int	*la_m3;
	int	idx;

	if (m_shift <= 0)
		return ;
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
	la_m3 = do_la_reverse_qp(la_m3, do_la_get_qty(la_m3), do_la_get_qty(la_m3));
	do_rla_add_la(la, la_m3);
	do_iarray_del(&la_m1);
	do_iarray_del(&la_m2);
	do_iarray_del(&la_m3);
}

/*
** to count from which position in la - non zeros
*/

static int		get_g_lprec(int *la)
{
	int		a;
	char	*s;

	a = 0;
	while (la[a] == 0 && a < LA_BASELEN)
		a++;
	a *= LA_BASELEN;
	if (!(s = ft_itoa(la[a])))
		return (0);
	a += (LA_BASELEN - (int)ft_strlen(s));
	return (a);
}

/*
** to get params as fprints
*/

static void		do_get_fprints(t_fprints *fp, t_options node, int *num,
	int *la)
{
	int	lla;

	lla = do_la_qdigits(num);
	if (lla >= 1)
	{
		fp->shift = (lla <= node.precision) ? 0 : lla - 1;
		fp->l_num = (lla <= node.precision) ? lla : 1;
		fp->l_prec = (node.precision > fp->l_num) ?
			node.precision - fp->l_num : 0;
	}
	else
	{
		fp->shift = 0;
		fp->l_num = 1;
		fp->l_prec = (node.precision) ? get_g_lprec(la) + node.precision :
			get_g_lprec(la) + node.precision + 1;
	}
	fp->cfill = (node.flag && ft_strchr(node.flag, '0')) ? '0' : ' ';
	fp->align = n_get_align(node);
}

/*
** to print align
*/

static int		g_do_print_align(t_nprints np, t_fprints fp)
{
	int		idx;
	int		a;

	a = (fp.shift != 0) ? 5 : 1;
	if (np.align)
	{
		idx = (np.cfill == ' ') ?
			do_print_char(a, fp.q_align + 1, np.cfill) : 0;
		idx += n_do_print_sign(np);
		if (np.cfill == '0')
			idx += do_print_char(a, fp.q_align + 1, np.cfill);
	}
	else
	{
		idx = n_do_print_sign(np);
		if (np.cfill == '0')
			idx += do_print_char(a, fp.q_align + 1, np.cfill);
	}
	return (idx);
}

/*
** main function to print g option
*/

int				do_g_option(t_options node, long int sign, int *num,
	int *la)
{
	t_fprints	fp;
	t_nprints	np;
	int			qty;

	node.precision = (node.precision < 0) ? DEF_F_PREC : node.precision;
	do_get_fprints(&fp, node, num, la);
	do_g_shift(la, num, fp.shift);
	qty = do_la_round(la, fp.l_prec, num);
	do_la_add_int(num, qty);
	fp.l_prec = do_rla_qdigits_n(la, fp.l_prec);
	fp.q_align = (node.width >= fp.l_num + fp.l_prec) ?
		node.width - fp.l_num - fp.l_prec : 0;
	fp.q_align = (fp.l_prec > 0) ? fp.q_align - 1 : fp.q_align;
	get_e_nprints(node, &np, sign, num);
	qty = g_do_print_align(np, fp);
	do_la_print(num, 0);
	qty += fp.l_num;
	if (fp.l_prec)
	{
		ft_putchar('.');
		qty += 1 + do_g_decpart_print(la, fp.l_prec);
	}
	if (fp.shift != 0)
		qty += do_e_print(node, fp.shift);
	return (qty);
}
