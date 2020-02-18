/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_f_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:06:02 by clianne           #+#    #+#             */
/*   Updated: 2019/10/26 15:22:58 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** to print align
*/

int				f_do_print_align(t_options node, t_nprints p)
{
	int		idx;
	int		dec;

	dec = (node.precision) ? 1 : 0;
	if (p.align)
	{
		idx = (p.cfill == ' ') ?
			do_print_char((int)p.slen + dec + (int)p.qzero + node.precision,
				node.width, p.cfill) : 0;
		idx += n_do_print_sign(p);
		if (p.cfill == '0')
			idx += do_print_char((int)p.slen + dec + (int)p.qzero +
				node.precision, node.width, p.cfill);
		idx += do_print_char(0, p.qzero, '0');
	}
	else
	{
		idx = n_do_print_sign(p);
		if (p.cfill == '0')
			idx += do_print_char((int)p.slen + dec + (int)p.qzero +
				node.precision, node.width, p.cfill);
		idx += do_print_char(0, p.qzero, '0');
	}
	return (idx);
}

/*
** to get qty of zero to fill precision
*/

char			f_get_qzero(t_options node, t_nprints p)
{
	if ((node.precision + (int)p.slen + 1 < node.width) &&
			p.cfill == '0')
		return (node.width - (node.precision + (int)p.slen + 1));
	else
		return (0);
}

static void		get_f_nprints(t_options node, t_nprints *fp, long int sign,
	int *num)
{
	int			a;

	a = (size_t)do_la_qdigits(num);
	fp->slen = (a) ? a : 1;
	fp->sign = (sign) ? '-' : n_get_sign(node);
	if (fp->sign == ' ' || fp->sign == '+' || fp->sign == '-')
		fp->slen++;
	fp->cfill = (node.flag && !ft_strchr(node.flag, '-') &&
		ft_strchr(node.flag, '0')) ? '0' : ' ';
	fp->align = n_get_align(node);
	fp->neg = (size_t)sign;
	fp->ho = NULL;
	fp->qzero = f_get_qzero(node, *fp);
}

int				do_f_option(t_options node, long int sign, int *num,
	int *la)
{
	t_nprints	fp;
	int			qty;

	node.precision = (node.precision < 0) ? DEF_F_PREC : node.precision;
	qty = do_la_round(la, node.precision, num);
	do_la_add_int(num, qty);
	get_f_nprints(node, &fp, sign, num);
	qty = f_do_print_align(node, fp);
	qty += do_la_print(num, 0);
	if (node.precision || (node.flag && ft_strchr(node.flag, '#')))
	{
		ft_putchar('.');
		if (node.precision)
			do_f_decpart_print(la, node.precision);
		qty++;
	}
	if (!fp.align && fp.cfill == ' ')
	{
		if ((node.flag && ft_strchr(node.flag, '#')) || node.precision != 0)
			node.width--;
		qty += do_print_char((int)fp.slen + (int)fp.qzero + node.precision,
				node.width, fp.cfill);
	}
	qty += node.precision;
	return (qty);
}
