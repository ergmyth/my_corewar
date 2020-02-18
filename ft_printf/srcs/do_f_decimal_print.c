/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_f_decimal_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:05:04 by clianne           #+#    #+#             */
/*   Updated: 2019/10/26 15:25:27 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** functions to print decimal part from long arithmetic array
*/

char			*get_s(int n, size_t bl)
{
	char	*sres;
	char	*s1;
	char	*s2;
	size_t	idx;

	if (!(s1 = ft_itoa(n)))
		return (NULL);
	if (ft_strlen(s1) >= bl)
		return (s1);
	if (!(s2 = ft_strnew(bl - ft_strlen(s1))))
	{
		ft_strdel(&s1);
		return (NULL);
	}
	idx = 0;
	while (idx < bl - ft_strlen(s1))
	{
		s2[idx] = '0';
		idx++;
	}
	sres = ft_strjoin(s2, s1);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return ((sres) ? (sres) : (NULL));
}

static int		print_dec(char *s, int q)
{
	int	ndx;
	int	qr;

	ndx = 0;
	qr = q;
	while (qr > 0 && s[ndx] != '\0')
	{
		ft_putchar(s[ndx]);
		ndx++;
		qr--;
	}
	return (ndx);
}

void			do_f_decpart_print(int *la_int, int q)
{
	int		idx;
	char	*s;

	q = (q == -1) ? do_rla_qdigits(la_int) : q;
	if (q == -1)
		return ;
	idx = 0;
	while (idx < LA_MAXLEN && q > 0)
	{
		if (!(s = get_s(la_int[idx], LA_BASELEN)))
			return ;
		q -= print_dec(s, q);
		ft_strdel(&s);
		idx++;
	}
}

int				do_g_decpart_print(int *la_int, int q)
{
	int		idx;
	char	*s;

	q = (q == -1) ? do_rla_qdigits(la_int) : q;
	if (q == -1)
		return (0);
	idx = 0;
	while (idx < LA_MAXLEN && q > 0)
	{
		if (!(s = get_s(la_int[idx], LA_BASELEN)))
			return (0);
		q -= print_dec(s, q);
		ft_strdel(&s);
		idx++;
	}
	return (0);
}
