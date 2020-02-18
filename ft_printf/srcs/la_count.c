/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:17:49 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 11:04:16 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** long arithmetic: to count digits in the int array
*/

int				do_la_qdigits(int *la)
{
	int	idx;
	int	res;
	char*s;

	if (!la)
		return (-1);
	idx = la[LA_MAXLEN + 1] - 1;
	if (idx < 0)
		return (0);
	s = ft_itoa(la[idx]);
	res = idx * LA_BASELEN + (int)ft_strlen(s);
	ft_strdel(&s);
	return (res);
}

/*
** long arithmetic: to count digits in the rev int array
*/

int				do_rla_qdigits(int *la_int)
{
	int		idx;
	int		q;

	if (!la_int)
		return (-1);
	idx = la_int[LA_MAXLEN + 1] - 1;
	q = 0;
	while (idx >= 0 && la_int[idx] - ft_power(10, q + 1) * (la_int[idx] /
		ft_power(10, q + 1)) == 0)
		q++;
	return (idx * LA_BASELEN + (LA_BASELEN - q));
}

/*
** long arithmetic: to count digits in the int rev array not more n symbols
*/

static void		do_tmp_count(int n, int *pos, char *s)
{
	int		q;

	q = LA_BASELEN - 1;
	while (q >= 0 && (*pos > n || (*pos <= n && s[q] == '0')))
	{
		q--;
		(*pos)--;
	}
}

int				do_rla_qdigits_n(int *la_int, int n)
{
	int		idx;
	int		pos;
	int		is_exit;
	char	*s;

	if (!la_int)
		return (-1);
	idx = n / LA_BASELEN;
	while (idx >= 0 && la_int[idx] == 0)
		idx--;
	pos = (idx + 1) * LA_BASELEN;
	is_exit = 0;
	while (idx >= 0 && !is_exit)
	{
		if (!(s = get_s(la_int[idx], LA_BASELEN)))
			return (n);
		is_exit = (s[0] != '0');
		do_tmp_count(n, &pos, s);
		ft_strdel(&s);
		idx--;
	}
	return (pos);
}
