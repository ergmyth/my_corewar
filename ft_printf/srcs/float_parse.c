/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:09:31 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/29 11:57:34 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static long int	get_basis(unsigned char *data)
{
	short int		result;
	unsigned char	temp;

	result = 0;
	temp = *data--;
	result |= temp;
	result &= 127;
	result <<= 8;
	temp = *data;
	result |= temp;
	result >>= 4;
	return ((long int)(result - 1023));
}

static long int	get_mant(unsigned char *data)
{
	long int		result;
	long int		temp;
	int				i;

	result = 0;
	result |= *(--data);
	result &= 15;
	result <<= 48;
	i = 5;
	while (i >= 0)
	{
		temp = *(--data);
		temp <<= (i * 8);
		result |= temp;
		i--;
	}
	return (result);
}

static void		get_sign_and_mant(long int *result, unsigned char *data)
{
	result[0] = *data & (1 << 7);
	result[1] = get_basis(data);
	result[2] = get_mant(data);
}

static void		get_la(int *num, long int *result, int *la)
{
	int		j;

	j = 51;
	if (result[1] < 0 && result[1] != -1023)
		do_power5(la, ft_abs((int)result[1]--));
	else if (result[1] != -1023)
	{
		do_power2(num, ft_abs((int)result[1]));
		result[1]--;
		while (result[1] >= 0 && j >= 0)
		{
			if ((result[2] >> j--) & 1)
				do_power2(num, ft_abs((int)result[1]));
			result[1]--;
		}
	}
	while (result[1] != 1023 && j >= 0)
	{
		if ((result[2] >> j--) & 1)
			do_power5(la, ft_abs((int)result[1]));
		result[1]--;
	}
}

int				float_parse(t_options options, double data)
{
	unsigned char	*arr;
	long int		result[3];
	int				*num;
	int				qn;
	int				*la;

	arr = (unsigned char*)&data;
	arr += 7;
	get_sign_and_mant(result, arr);
	if (result[1] == 1024)
		return (nan_and_inf(options, result));
	num = do_iarray_create(LA_MAXLEN + 1);
	la = do_iarray_create(LA_MAXLEN + 1);
	qn = 0;
	get_la(num, result, la);
	if (options.type == T_FLOAT || options.type == T_FFLOAT)
		qn = do_f_option(options, result[0], num, la);
	else if (options.type == T_EFLOAT || options.type == T_EEFLOAT)
		qn = do_e_option(options, result[0], num, la);
	else if (options.type == T_GFLOAT || options.type == T_GGFLOAT)
		qn = do_g_option(options, result[0], num, la);
	do_iarray_del(&la);
	do_iarray_del(&num);
	return (qn);
}
