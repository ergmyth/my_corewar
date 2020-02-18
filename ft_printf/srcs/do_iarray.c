/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_iarray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:00:50 by clianne           #+#    #+#             */
/*   Updated: 2019/11/19 14:33:47 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
** to copy valuse from to
*/

void	do_iarray_copy(int *froma, int *toa, size_t size)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		toa[idx] = froma[idx];
		idx++;
	}
}

/*
** to fill int array with init
*/

void	do_iarray_fill(int *ia, size_t size, int init)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		ia[idx] = init;
		idx++;
	}
}

/*
** to create int array
*/

int		*do_iarray_create(size_t size)
{
	int		*ires;

	if (!(ires = (int *)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	do_iarray_fill(ires, size + 1, 0);
	return (ires);
}

/*
** to delete int array
*/

void	do_iarray_del(int **ia)
{
	if (ia && *ia)
	{
		free(*ia);
		*ia = NULL;
	}
}
