/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_oxx_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:47:04 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 10:59:18 by jflorent         ###   ########.fr       */
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
** to get qty sym for hex_oct prefix t
*/

static char		*get_ho_prefix(t_options node, int is_zero, int slen)
{
	if (node.type == 'o' && node.flag && ft_strchr(node.flag, '#') &&
		(node.precision == 0 || !is_zero) && node.precision <= slen)
		return (ft_strdup("0"));
	else if (node.type == 'x' && node.flag && ft_strchr(node.flag, '#') &&
		!is_zero)
		return (ft_strdup("0x"));
	else if (node.type == 'X' && node.flag && ft_strchr(node.flag, '#') &&
		!is_zero)
		return (ft_strdup("0X"));
	return (NULL);
}

void			get_oxx_nprints(t_options node, t_nprints *p)
{
	char	*s;

	if (p->snum[0] == '-')
	{
		p->sign = '-';
		s = ft_strsub(p->snum, 1, ft_strlen(p->snum) - 1);
		ft_strdel(&(p->snum));
		p->snum = s;
		p->neg = 1;
	}
	else
	{
		p->neg = 0;
		p->sign = n_get_sign(node);
	}
	p->n_is_null = ft_strcmp(p->snum, "0") == 0;
	p->cfill = (node.flag && ft_strchr(node.flag, '0') &&
		!ft_strchr(node.flag, '-') && node.precision < 0) ? '0' : ' ';
	if (node.precision == 0 && !p->n_is_null)
		p->cfill = ' ';
	p->slen = (node.precision != 0 || !p->n_is_null) ?
		(int)ft_strlen(p->snum) : 0;
	p->align = n_get_align(node);
	p->qzero = !(node.precision == 0 && p->n_is_null) ?
		n_get_qzero(node, *p) : 0;
}

/*
** to print integer numbers
*/

int				do_oxx_option(t_options node, void *data)
{
	t_nprints	p;
	int			qty;

	if (!(p.snum = get_snum(data, node)))
		return (-1);
	get_oxx_nprints(node, &p);
	p.ho = get_ho_prefix(node, p.n_is_null, (int)p.slen);
	qty = n_do_print_align(node, p);
	if (node.precision != 0 || !p.n_is_null)
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
