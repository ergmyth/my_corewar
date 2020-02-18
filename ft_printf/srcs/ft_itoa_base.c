/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:07:46 by exam              #+#    #+#             */
/*   Updated: 2019/10/17 12:44:40 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int			len_value(int value, int base)
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

static void	create_str(int value, int base, int len, char *result)
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

char		*ft_itoa_base(int value, int base)
{
	int		len;
	char	*result;

	if ((value < 0 && base != 10) || (base < 2 || base > 16))
		return (0);
	len = len_value(value, base);
	if (value == 0 || (value < 0 && base == 10))
		len++;
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	if (value < 0 && base == 10)
	{
		if (value == -2147483648)
		{
			value = -147483648;
			result[1] = '2';
		}
		result[0] = '-';
		value = -value;
	}
	result[len] = '\0';
	create_str(value, base, len, result);
	return (result);
}

int			int_len(int value)
{
	int		len;
	char	*s;

	if (!(s = ft_itoa_base(value, 10)))
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	ft_strdel(&s);
	return (len);
}
