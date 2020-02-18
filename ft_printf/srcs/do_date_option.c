/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_date_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 08:59:50 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 16:12:23 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <time.h>

static int		do_print_ymd(struct tm *dt, char *s, char c)
{
	size_t	q;
	int		ymd;
	char	*s1;

	q = 0;
	while (s[q] == c && s[q] != '\0')
		q++;
	if (c == 'Y')
		ymd = dt->tm_year + 1900;
	else if (c == 'M')
		ymd = dt->tm_mon + 1;
	else if (c == 'D')
		ymd = dt->tm_mday;
	else
		return (0);
	s1 = ft_itoa(ymd);
	if (!s1)
		return (0);
	if (q <= ft_strlen(s1))
		ft_putstr_r(s1, q);
	else
		ft_putstr_fill(s1, q, '0');
	ft_strdel(&s1);
	return ((int)q);
}

static int		do_print_hm(struct tm *dt, char *s, char c)
{
	size_t	q;
	int		ymd;
	char	*s1;

	q = 0;
	while (s[q] == c && s[q] != '\0')
		q++;
	if (c == 'h')
		ymd = dt->tm_hour;
	else if (c == 'm')
		ymd = dt->tm_min;
	else if (c == 's')
		ymd = dt->tm_sec;
	else
		return (0);
	s1 = ft_itoa(ymd);
	if (!s1)
		return (0);
	if (q <= ft_strlen(s1))
		ft_putstr_r(s1, q);
	else
		ft_putstr_fill(s1, q, '0');
	ft_strdel(&s1);
	return ((int)q);
}

static int		do_tmp_dt_print(char a, struct tm	*dt)
{
	if (a == 'Y' || a == 'M' || a == 'D')
		return (do_print_ymd(dt, &a, a));
	else if (a == 'h' || a == 'm' || a == 's')
		return (do_print_hm(dt, &a, a));
	else
	{
		ft_putchar(a);
		return (1);
	}
	return (0);
}

int				do_date_option(t_options node, void *data)
{
	char		*str;
	struct tm	*dt;
	time_t		tm;
	int			idx;

	node.type = 'k';
	if (!data)
	{
		ft_putstr("(null)");
		return (6);
	}
	tm = time(0);
	dt = localtime(&tm);
	str = (char*)data;
	idx = 0;
	while (str[idx] != '\0')
		idx += do_tmp_dt_print(str[idx], dt);
	return (idx);
}
