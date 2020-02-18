/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:13:07 by clianne           #+#    #+#             */
/*   Updated: 2019/10/15 20:26:30 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** to print part of string between pos start and pos finish
*/

void	ft_putstr_sf(char const *str, size_t pos_start, size_t pos_finish)
{
	size_t	idx;

	if (!str)
		return ;
	idx = 0;
	while (str[idx] != '\0' && idx <= pos_finish)
	{
		if (idx >= pos_start)
			ft_putchar(str[idx]);
		idx++;
	}
}

/*
** to print part of string after pos start to EOS
*/

void	ft_putstr_s(char const *str, size_t pos_start)
{
	size_t	l;

	if (!str)
		return ;
	l = ft_strlen(str) - 1;
	ft_putstr_sf(str, pos_start, l);
}

/*
** to print part of string of last n symbols
*/

void	ft_putstr_r(char const *str, size_t n)
{
	size_t	l;

	if (!str)
		return ;
	l = ft_strlen(str);
	ft_putstr_sf(str, l - n, l - 1);
}

/*
** to print string with leading symbols
*/

void	ft_putstr_fill(char const *str, size_t qfill, char cfill)
{
	size_t	idx;

	if (!str)
		return ;
	idx = ft_strlen(str);
	while (idx < qfill)
	{
		ft_putchar(cfill);
		idx++;
	}
	ft_putstr(str);
}
