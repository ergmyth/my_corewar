/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:58:34 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/29 13:11:42 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static long long int	get_basis(unsigned char *data)
{
	long long int		result;
	unsigned char		temp;

	result = 0;
	temp = *data--;
	result |= temp;
	result &= 127;
	result <<= 8;
	temp = *data;
	result |= temp;
	return (result - 16382);
}

static long long int	get_mant1(unsigned char *data)
{
	long long int		result;
	long long int		temp;
	int					i;

	result = 0;
	--data;
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

static long long int	get_mant2(unsigned char *data)
{
	long long int		result;
	long long int		temp;
	int					i;

	result = 0;
	data -= 7;
	i = 7;
	while (i >= 0)
	{
		temp = *(--data);
		temp <<= (i * 8);
		result |= temp;
		i--;
	}
	return (result);
}

static void				get_sign_and_mant(long long int *result,
										unsigned char *data)
{
	result[0] = (long long int)(*data & (1 << 7));
	result[1] = get_basis(data);
	result[2] = get_mant1(data);
	result[3] = get_mant2(data);
}

int						double_parse(t_options options, long double data)
{
	unsigned char		*arr;
	long long int		result[4];
	int					*num;
	int					*la;
	int					qn;

	arr = (unsigned char*)&data;
	arr += 9;
	get_sign_and_mant(result, arr);
	qn = 0;
	if (result[1] == 16385)
		return (d_nan_and_inf(options, result));
	num = do_iarray_create(LA_MAXLEN + 1);
	la = do_iarray_create(LA_MAXLEN + 1);
	double_parse_add(num, result, la);
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
