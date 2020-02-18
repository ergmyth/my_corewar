/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_int_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:42:31 by clianne           #+#    #+#             */
/*   Updated: 2019/10/26 15:14:59 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** to get qty of zero to fill precision
*/

static char		n_get_qzero(t_options node, t_nprints p)
{
	if (node.precision > (int)ft_strlen(p.snum))
		return (node.precision - (int)ft_strlen(p.snum));
	else
		return (0);
}

/*
** to get qty sym for hex_oct prefix
*/

static char		*get_ho_prefix(t_options node, int is_zero)
{
	if (node.flag && ft_strchr(node.flag, '#'))
		if (!is_zero)
		{
			if (node.type == 'o')
				return (ft_strdup("0"));
			else if (node.type == 'x')
				return (ft_strdup("0x"));
			else if (node.type == 'X')
				return (ft_strdup("0X"));
		}
	return (NULL);
}

static void		get_p_nprints(t_options node, t_nprints *p)
{
	char	*s;

	p->cfill = (node.flag && ft_strchr(node.flag, '0') &&
		!ft_strchr(node.flag, '-') && node.precision < 0) ? '0' : ' ';
	if ((node.precision == 0 && p->n_is_null == 0) || node.type == T_INT_X
		|| node.type == T_INT_XX)
		p->cfill = ' ';
	p->neg = (p->snum[0] == '-') ? 1 : 0;
	if (p->snum[0] == '-')
	{
		p->sign = '-';
		s = ft_strsub(p->snum, 1, ft_strlen(p->snum) - 1);
		ft_strdel(&(p->snum));
		p->snum = s;
	}
	else
		p->sign = n_get_sign(node);
	p->align = n_get_align(node);
	p->qzero = !(node.precision == 0 && p->n_is_null == 0) ?
		n_get_qzero(node, *p) : 0;
	p->is_lzero = !(node.precision == 0 && p->n_is_null == 0) ? 1 : 0;
	p->slen = n_get_slen(*p, (node.precision == 0 && p->n_is_null == 0));
	p->ho = get_ho_prefix(node, p->n_is_null == 0);
}

/*
** to print integer numbers
*/

int				do_int_option(t_options node, void *data)
{
	t_nprints	p;
	int			qty;

	if (!(p.snum = get_snum(data, node)))
		return (-1);
	p.n_is_null = ft_strcmp(p.snum, "0");
	get_p_nprints(node, &p);
	qty = n_do_print_align(node, p);
	if (!(node.precision == 0 && !p.n_is_null))
	{
		ft_putstr(p.snum);
		qty += (int)ft_strlen(p.snum);
	}
	if (!p.align && p.cfill == ' ')
	{
		if (p.ho)
			qty += do_print_char(p.slen + p.qzero + (int)ft_strlen(p.ho),
				node.width, p.cfill);
		else
			qty += do_print_char(p.slen + p.qzero, node.width, p.cfill);
	}
	ft_strdel(&p.snum);
	ft_strdel(&p.ho);
	return (qty);
}
