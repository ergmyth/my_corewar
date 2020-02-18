/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:44:19 by clianne           #+#    #+#             */
/*   Updated: 2019/10/23 17:45:33 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** to print qty of sym
*/

int			do_print_char(int l, int p, char c)
{
	int		idx;

	idx = 0;
	while (p > l)
	{
		ft_putchar(c);
		l++;
		idx++;
	}
	return (idx);
}

/*
** to print sign before number according to flag/negative
*/

int			n_do_print_sign(t_nprints p)
{
	if (p.sign == '-' || p.sign == '+' || p.sign == ' ')
	{
		ft_putchar(p.sign);
		return (1);
	}
	return (0);
}

/*
** to print hex_oct prefix
*/

static void	do_print_hexoct_prefix(t_nprints p)
{
	if (p.ho)
		ft_putstr(p.ho);
}

/*
** to print align
*/

int			n_do_print_align(t_options node, t_nprints p)
{
	int		idx;
	int		ho;

	ho = (p.ho) ? (int)ft_strlen(p.ho) : 0;
	if (p.align)
	{
		idx = (p.cfill == ' ') ?
			do_print_char(p.slen + p.qzero + ho, node.width, p.cfill) : 0;
		do_print_hexoct_prefix(p);
		idx += n_do_print_sign(p);
		if (p.cfill == '0' && p.is_lzero)
			idx += do_print_char(p.slen + p.qzero + ho, node.width, p.cfill);
		idx += do_print_char(0, p.qzero, '0');
	}
	else
	{
		idx = n_do_print_sign(p);
		do_print_hexoct_prefix(p);
		if (p.cfill == '0' && p.is_lzero)
			idx += do_print_char(p.slen + p.qzero + ho, node.width, p.cfill);
		idx += do_print_char(0, p.qzero, '0');
	}
	return (idx + ho);
}
