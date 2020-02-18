/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_parse_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:52:54 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/29 11:43:01 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_power_num(long long int result, int *j, int *num,
						long long int *power)
{
	while (*power >= 0 && *j >= 0)
	{
		if ((result >> (*j)--) & 1)
			do_power2(num, ft_abs((int)*power));
		(*power)--;
	}
}

static void	do_power_la(long long int result, int *j, int *la,
						long long int *power)
{
	while (*j >= 0)
	{
		if ((result >> (*j)--) & 1)
			do_power5(la, ft_abs((int)*power));
		(*power)--;
	}
}

void		double_parse_add(int *num, long long int *result, int *la)
{
	int		j;

	j = 47;
	result[1]--;
	do_power_num(result[2], &j, num, &result[1]);
	do_power_la(result[2], &j, la, &result[1]);
	j = 63;
	while (result[1] >= 0 && j >= 48)
	{
		if ((result[3] >> j--) & 1)
			do_power2(num, ft_abs((int)result[1]));
		result[1]--;
	}
	while (j >= 48)
	{
		if ((result[3] >> j--) & 1)
			do_power5(la, ft_abs((int)result[1]));
		result[1]--;
	}
}

void		fast_power(int *la, int power, int num)
{
	unsigned char		*bin_power;
	int					i;
	int					j;

	bin_power = (unsigned char*)&power;
	bin_power += 3;
	i = 3;
	j = 7;
	while (i-- >= 0)
	{
		while (j >= 0)
		{
			do_la_mult_la(la);
			if (*bin_power >> j & 1)
				do_la_mult_int(la, num);
			j--;
		}
		bin_power--;
		j = 7;
	}
}

void		do_power2(int *la, int power)
{
	int	la_tmp[LA_MAXLEN + 2];

	do_iarray_fill(la_tmp, LA_MAXLEN + 2, 0);
	la_tmp[0] = 1;
	la_tmp[LA_MAXLEN + 1] = 1;
	fast_power(la_tmp, power, 2);
	do_la_add_la(la, la_tmp);
}
