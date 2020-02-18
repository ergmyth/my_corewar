/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:04:44 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 11:05:10 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
** long arithmetic: sub long from long
*/

int		*do_la_sub_tonewla(int *la_int_1, int *la_int_2)
{
	int	idx;
	int	*la_res;
	int	c;
	int	fin;

	if (!(la_res = do_iarray_create(LA_MAXLEN + 1)))
		return (NULL);
	fin = ft_max2(la_int_1[LA_MAXLEN + 1], la_int_1[LA_MAXLEN + 1]);
	idx = 0;
	c = 0;
	la_res[LA_MAXLEN + 1] = fin;
	while (idx < fin)
	{
		c = c + la_int_1[idx] - la_int_2[idx];
		la_res[idx] = (c + LA_BASE) % LA_BASE;
		c = (c + LA_BASE) / LA_BASE - 1;
		idx++;
	}
	return (la_res);
}
