/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:40:11 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/04 18:58:41 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	ullen_value(unsigned long long int value, int base)
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

static void	create_str_xx(unsigned long long int value, int base, int len,
	char *result)
{
	char	*bases;

	if (!(bases = ft_strdup("0123456789ABCDEF")))
		return ;
	while (value > (unsigned long long int)(base - 1))
	{
		result[--len] = bases[value % base];
		value /= base;
	}
	result[--len] = bases[value % base];
	ft_strdel(&bases);
}

static void	create_str(unsigned long long int value, int base, int len,
	char *result)
{
	char	*bases;

	if (!(bases = ft_strdup("0123456789abcdef")))
		return ;
	while (value > (unsigned long long int)(base - 1))
	{
		result[--len] = bases[value % base];
		value /= base;
	}
	result[--len] = bases[value % base];
	ft_strdel(&bases);
}

char		*ft_ulitoa_base(unsigned long long int value, int base, size_t xx)
{
	int		len;
	char	*result;

	if (base < 2 || base > 16)
		return (0);
	len = ullen_value(value, base);
	if (value == 0)
		len++;
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	(xx) ? create_str_xx(value, base, len, result) :
			create_str(value, base, len, result);
	return (result);
}
