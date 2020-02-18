/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:40:11 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/17 12:44:40 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int			llen_value(long long int value, int base)
{
	int		len;

	len = 0;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

static void	create_str_xx(long long int value, int base, int len,
	char *result)
{
	char	*bases;

	if (!(bases = ft_strdup("0123456789ABCDEF")))
		return ;
	while (value > base - 1)
	{
		result[--len] = bases[value % base];
		value /= base;
	}
	result[--len] = bases[value % base];
	ft_strdel(&bases);
}

static void	create_str(long long int value, int base, int len, char *result)
{
	char	*bases;

	if (!(bases = ft_strdup("0123456789abcdef")))
		return ;
	while (value > base - 1)
	{
		result[--len] = bases[value % base];
		value /= base;
	}
	result[--len] = bases[value % base];
	ft_strdel(&bases);
}

char		*ft_litoa_base(long long int value, int base, size_t xx)
{
	int		len;
	char	*result;

	if (base < 2 || base > 16)
		return (0);
	len = llen_value(value, base);
	if (value == 0 || (value < 0 && base == 10))
		len++;
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	if (value < 0 && base == 10)
	{
		if ((value + 1) == -9223372036854775807)
		{
			value = -223372036854775808;
			result[1] = '9';
		}
		result[0] = '-';
		value = -value;
	}
	result[len] = '\0';
	(xx) ? create_str_xx(value, base, len, result) :
			create_str(value, base, len, result);
	return (result);
}

int			llint_len(long long int value)
{
	int		len;
	char	*s;

	if (!(s = ft_litoa_base(value, 10, 0)))
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	ft_strdel(&s);
	return (len);
}
