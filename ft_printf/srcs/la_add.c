/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:01:50 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 11:06:27 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
** long arithmetic: add la_1 & la_2 to new la
*/

int		*do_la_add_la_tonew(int *la_int_1, int *la_int_2)
{
	int	idx;
	int	*la_res;
	int	c;

	if (!(la_res = do_iarray_create(LA_MAXLEN + 1)))
		return (NULL);
	idx = 0;
	c = 0;
	while (idx < ft_max2(la_int_1[LA_MAXLEN + 1], la_int_2[LA_MAXLEN + 1])
		|| c != 0)
	{
		c = c + la_int_1[idx] + la_int_2[idx];
		la_res[idx] = c % LA_BASE;
		c = c / LA_BASE;
		idx++;
	}
	la_res[LA_MAXLEN + 1] = idx;
	return (la_res);
}

/*
** long arithmetic: add la_1 & la_2 to la_1
*/

void	do_la_add_la(int *la_int_1, int *la_int_2)
{
	int	idx;
	int	c;

	idx = 0;
	c = 0;
	while (idx < ft_max2(la_int_1[LA_MAXLEN + 1], la_int_2[LA_MAXLEN + 1])
		|| c != 0)
	{
		c = c + la_int_1[idx] + la_int_2[idx];
		la_int_1[idx] = c % LA_BASE;
		c = c / LA_BASE;
		idx++;
	}
	la_int_1[LA_MAXLEN + 1] = idx;
}

/*
** long arithmetic: add la_1 & int to la_1
*/

void	do_la_add_int(int *la_int_1, int a)
{
	int	idx;
	int	c;

	if (a == 0)
		return ;
	idx = 0;
	c = a;
	while (idx < la_int_1[LA_MAXLEN + 1] || c != 0)
	{
		c = c + la_int_1[idx];
		la_int_1[idx] = c % LA_BASE;
		c = c / LA_BASE;
		idx++;
	}
	la_int_1[LA_MAXLEN + 1] = idx;
}

/*
** long arithmetic: add rla_1 & rla_1 to rla_1
*/

int		do_rla_add_la(int *la_int_1, int *la_int_2)
{
	int	idx;
	int	c;

	idx = ft_max2(la_int_1[LA_MAXLEN + 1], la_int_2[LA_MAXLEN + 1]) - 1;
	c = 0;
	while (idx >= 0)
	{
		c = c + la_int_1[idx] + la_int_2[idx];
		la_int_1[idx] = c % LA_BASE;
		c = c / LA_BASE;
		idx--;
	}
	la_int_1[LA_MAXLEN + 1] = ft_max2(la_int_1[LA_MAXLEN + 1],
		la_int_2[LA_MAXLEN + 1]);
	return (c);
}
