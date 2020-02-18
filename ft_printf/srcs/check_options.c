/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:32:26 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 16:18:57 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  check for format symbols
*/

int		check_format(char c)
{
	if (c == T_D || c == T_DD || c == T_I || c == T_II ||
		c == 'u' || c == 'f' || c == 'F' ||
		c == 'e' || c == 'E' || c == 'g' || c == 'G' || c == 'x' ||
		c == 'X' || c == 'o' || c == 's' || c == 'c' || c == 'p' ||
		c == 'a' || c == 'A' || c == 'b' || c == '%' ||
		c == 'm' || c == 'k' || c == 'r')
		return (1);
	return (0);
}

/*
**  check for flag symbols
*/

int		check_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

/*
**  check for width symbols
*/

int		check_width(char c)
{
	if ((c == '*') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*
**  check for precision symbols
*/

int		check_precision(char c, size_t index)
{
	if (index == 1)
	{
		if (c == '.')
			return (1);
	}
	else if (index == 2)
	{
		if ((c == '.') || (c == '*') || (c >= '0' && c <= '9'))
			return (1);
	}
	return (0);
}

/*
**  check for size symbols
*/

int		check_size(char c)
{
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z' ||
		c == 't' || c == 'L')
		return (1);
	return (0);
}
