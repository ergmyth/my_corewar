/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:04:14 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 11:04:59 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int				do_la_get_qty(int *la)
{
	int	idx;
	int	qty;

	qty = 0;
	idx = la[LA_MAXLEN + 1] - 1;
	if (idx >= 0)
		qty = int_len(la[idx]);
	qty += LA_BASELEN * idx;
	return (qty);
}

static int		do_get_int(char *s, int pos, int qty)
{
	char	*s1;
	int		a;

	if (!(s1 = ft_strsub(s, pos, qty)))
		return (0);
	a = ft_atoi(s1);
	ft_strdel(&s1);
	return (a);
}

int				*do_la_create_from_str(char *s)
{
	int		idx;
	int		*la_res;
	int		pos;

	if (!(la_res = do_iarray_create(LA_MAXLEN + 1)))
		return (NULL);
	pos = (int)ft_strlen(s);
	if (s[0] == '-')
		la_res[LA_MAXLEN] = 1;
	idx = 0;
	while (pos - la_res[LA_MAXLEN] >= LA_BASELEN)
	{
		la_res[idx] = do_get_int(s, pos - LA_BASELEN, LA_BASELEN);
		pos -= LA_BASELEN;
		idx++;
	}
	la_res[LA_MAXLEN + 1] = idx;
	if (pos > la_res[LA_MAXLEN])
	{
		la_res[idx] = do_get_int(s, 0, pos - la_res[LA_MAXLEN]);
		la_res[LA_MAXLEN + 1]++;
	}
	return (la_res);
}

int				*do_rla_create_from_str(char *s)
{
	int		idx;
	int		*la_res;
	int		pos;
	int		l;

	if (!(la_res = do_iarray_create(LA_MAXLEN + 1)))
		return (NULL);
	l = (int)ft_strlen(s);
	if (s[0] == '-')
		la_res[LA_MAXLEN] = 1;
	idx = 0;
	pos = 0;
	while (pos - la_res[LA_MAXLEN] < l)
	{
		la_res[idx] = do_get_int(s, pos, ft_min2(LA_BASELEN, l - pos));
		if (l - pos > 0 && l - pos < LA_BASELEN)
			la_res[idx] *= ft_power(10, (LA_BASELEN - (l - pos)));
		pos += ft_min2(LA_BASELEN, l - pos);
		idx++;
	}
	la_res[LA_MAXLEN + 1] = idx;
	return (la_res);
}
