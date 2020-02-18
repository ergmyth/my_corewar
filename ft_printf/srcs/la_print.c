/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:49:29 by clianne           #+#    #+#             */
/*   Updated: 2019/10/26 14:46:25 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** long arithmetic: to print int array - 2 functions
*/

static int		do_tmp_la_print(int *la_int, int idx, int flag)
{
	int		q;
	int		ndx;
	char	*s;

	q = 0;
	ndx = idx;
	while (ndx >= 0)
	{
		s = ft_itoa(la_int[ndx]);
		if ((flag > 0) || (ndx != idx))
		{
			do_print_char((int)ft_strlen(s), LA_BASELEN, '0');
			q += LA_BASELEN - (int)ft_strlen(s);
		}
		ft_putnbr(la_int[ndx]);
		q += (int)ft_strlen(s);
		ft_strdel(&s);
		if (flag)
			ft_putchar(' ');
		ndx--;
	}
	if (flag)
		ft_putstr("\n");
	return (q + flag * (idx + 1));
}

int				do_la_print(int *la_int, int flag)
{
	int		idx;
	int		q;

	if (!la_int)
		return (0);
	q = 0;
	if (flag)
	{
		ft_putstr("\nla = ");
		q += 6;
	}
	idx = LA_MAXLEN - 1;
	while (idx >= 0 && la_int[idx] == 0)
		idx--;
	if (idx < 0)
	{
		ft_putnbr(0);
		return (1);
	}
	q += la_int[LA_MAXLEN];
	if (la_int[LA_MAXLEN])
		ft_putchar('-');
	q += do_tmp_la_print(la_int, idx, flag);
	return (q);
}

/*
** long arithmetic: to print REVERSE int array
*/

int				do_tmp_rla_print(int *la_int, int ndx, int flag)
{
	int		q;
	int		idx;
	char	*s;

	q = 0;
	idx = 0;
	while (idx <= ndx)
	{
		s = ft_itoa(la_int[idx]);
		if (idx > 0 || flag)
		{
			do_print_char((int)ft_strlen(s), LA_BASELEN, '0');
			q += LA_BASELEN - (int)ft_strlen(s);
		}
		ft_putnbr(la_int[idx]);
		q += (int)ft_strlen(s);
		ft_strdel(&s);
		if (flag)
			ft_putchar(' ');
		idx++;
	}
	if (flag)
		ft_putstr("\n");
	return (q + flag * (ndx + 1));
}

int				do_rla_print(int *la_int, int flag)
{
	int		q;
	int		ndx;

	if (!la_int)
		return (0);
	q = 0;
	if (flag)
	{
		ft_putstr("\nrla = ");
		q += 7;
	}
	ndx = LA_MAXLEN - 1;
	while (ndx >= 0 && la_int[ndx] == 0)
		ndx--;
	if (ndx < 0)
	{
		ft_putnbr(0);
		return (1);
	}
	q += la_int[LA_MAXLEN];
	if (la_int[LA_MAXLEN])
		ft_putchar('-');
	q += do_tmp_rla_print(la_int, ndx, flag);
	return (q);
}
