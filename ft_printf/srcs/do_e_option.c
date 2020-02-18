/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_e_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:39:33 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 11:24:21 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				e_do_print_align(t_options node, t_nprints p)
{
	int		idx;
	int		a;

	a = (node.precision == 0 && (node.type == T_FLOAT || node.type == T_FFLOAT
		|| node.type == T_EFLOAT || node.type == T_EEFLOAT)) ? 1 : 0;
	if (p.align)
	{
		idx = (p.cfill == ' ') ?
			do_print_char((int)p.slen + (int)p.qzero + node.precision - a,
				node.width - 1, p.cfill) : 0;
		idx += n_do_print_sign(p);
		if (p.cfill == '0')
			idx += do_print_char((int)p.slen + (int)p.qzero + node.precision
				- a, node.width - 1, p.cfill);
		idx += do_print_char(0, p.qzero, '0');
	}
	else
	{
		idx = n_do_print_sign(p);
		if (p.cfill == '0')
			idx += do_print_char((int)p.slen + (int)p.qzero + node.precision
				- a, node.width - 1, p.cfill);
		idx += do_print_char(0, p.qzero, '0');
	}
	return (idx);
}

void			get_e_nprints(t_options node, t_nprints *p, long int sign,
	int *num)
{
	p->cfill = (node.flag && ft_strchr(node.flag, '0')) ? '0' : ' ';
	p->align = n_get_align(node);
	p->neg = (size_t)sign;
	p->sign = (sign) ? '-' : n_get_sign(node);
	p->slen = (size_t)do_la_qdigits(num);
	p->ho = NULL;
	p->qzero = f_get_qzero(node, *p);
}

int				do_e_print(t_options node, int shift)
{
	char	*s;

	if (!(s = ft_itoa(ft_abs(shift))))
		return (0);
	if (node.type == T_EFLOAT || node.type == T_GFLOAT)
		ft_putchar('e');
	else
		ft_putchar('E');
	(shift >= 0) ? ft_putchar('+') : ft_putchar('-');
	ft_putstr_fill(s, 2, '0');
	ft_strdel(&s);
	return (4);
}

static int		e_get_shift(int *num, int *la)
{
	int		m_shift;
	int		a;
	char	*s;
	int		lla;

	lla = do_la_qdigits(num);
	m_shift = 0;
	if (lla == 0)
	{
		a = 0;
		while (la[a] == 0 && a < la[LA_MAXLEN + 1])
			a++;
		m_shift = -1 * a * LA_BASELEN;
		if (!(s = ft_itoa(la[a])))
			return (0);
		if (la[LA_MAXLEN + 1] != 0)
			m_shift -= (LA_BASELEN - (int)ft_strlen(s) + 1);
		num[0] = s[0] - '0';
		ft_strdel(&s);
	}
	else
		m_shift = lla - 1;
	return (m_shift);
}

int				do_e_option(t_options node, long int sign, int *num,
	int *la)
{
	t_nprints	fp;
	int			qty;
	int			m_shift;

	m_shift = e_get_shift(num, la);
	do_e_shift(la, num, m_shift);
	node.precision = (node.precision < 0) ? DEF_F_PREC : node.precision;
	fp.m_shift = 4;
	qty = do_la_round(la, node.precision, num);
	do_la_add_int(num, qty);
	get_e_nprints(node, &fp, sign, num);
	fp.slen += 4;
	qty = e_do_print_align(node, fp);
	do_la_print(num, 0);
	if (node.precision)
	{
		ft_putchar('.');
		do_f_decpart_print(la, node.precision);
		qty++;
	}
	qty += (int)fp.slen + node.precision;
	do_e_print(node, m_shift);
	return (qty);
}
