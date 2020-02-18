/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_iarray_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:33:27 by clianne           #+#    #+#             */
/*   Updated: 2019/11/19 14:51:51 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
** to sort bubble int array, order: 1 - asc, 2 - desc
*/

void		do_iarray_sort_bubble(int *ia, size_t size, size_t order)
{
	int		buf;
	size_t	idx;
	size_t	jdx;

	idx = 0;
	while (idx < size)
	{
		jdx = idx;
		while (jdx < size)
		{
			if ((order == 1 && ia[idx] > ia[jdx]) ||
				(order == 2 && ia[idx] < ia[jdx]))
			{
				buf = ia[idx];
				ia[idx] = ia[jdx];
				ia[jdx] = buf;
				jdx = idx;
			}
			else
				jdx++;
		}
		idx++;
	}
}

/*
** to sort quick int array, order: 1 - asc, 2 - desc
*/

static void	quick_sort_moving(int *ia, int *left, int *right, int pivot)
{
	while (*left < *right)
	{
		while ((ia[*right] >= pivot) && (*left < *right))
			(*right)--;
		if (*left != *right)
		{
			ia[*left] = ia[*right];
			(*left)++;
		}
		while ((ia[*left] <= pivot) && (*left < *right))
			(*left)++;
		if (*left != *right)
		{
			ia[*right] = ia[*left];
			(*right)--;
		}
	}
}

void		do_iarray_sort_quick(int *ia, int left, int right)
{
	int pivot;
	int l_hold;
	int r_hold;

	l_hold = left;
	r_hold = right;
	pivot = ia[left];
	quick_sort_moving(ia, &left, &right, pivot);
	ia[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		do_iarray_sort_quick(ia, left, pivot - 1);
	if (right > pivot)
		do_iarray_sort_quick(ia, pivot + 1, right);
}
