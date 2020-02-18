/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:05:20 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/23 19:56:11 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_even(int *la, int index, int iind, int *num)
{
	if (iind == 1 && index > 0)
	{
		index--;
		iind = LA_BASELEN + 1;
	}
	if (iind == 1 && index == 0)
	{
		if (num[0] % 10 % 2 == 0)
			return (1);
		else
			return (0);
	}
	if (la[index] / ft_power(10, LA_BASELEN - iind + 1) % 10 % 2 == 0)
		return (1);
	else
		return (0);
}

static int	check_half(int *half, int digit)
{
	if (!(*half) && digit == 5)
		*half = 1;
	else if (!(*half) && digit < 5)
		return (0);
	else if (!(*half) && digit > 5)
		return (1);
	else if (*half && digit > 0)
		return (1);
	return (-1);
}

int			rounding(int *la, int pos, int *num)
{
	int		index;
	int		iind;
	int		digit;
	int		even;
	int		half;

	index = 0;
	even = 0;
	half = 0;
	index += pos / LA_BASELEN;
	iind = pos % LA_BASELEN + 1;
	if (check_even(la, index, iind, num))
		even = 1;
	while (index < LA_MAXLEN)
	{
		while (iind <= LA_BASELEN)
			if ((digit = check_half(&half,
				la[index] / ft_power(10, LA_BASELEN - iind++) % 10)) != -1)
				return (digit);
		iind = 0;
		index++;
	}
	if (half && even)
		return (0);
	return (1);
}
