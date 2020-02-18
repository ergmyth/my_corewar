/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:05:33 by clianne           #+#    #+#             */
/*   Updated: 2019/10/26 16:25:53 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*do_la_copy(int *la)
{
	int	idx;
	int	*la_new;

	idx = 0;
	if (!(la_new = do_iarray_create(LA_MAXLEN + 1)))
		return (NULL);
	while (idx < la[LA_MAXLEN + 1])
	{
		la_new[idx] = la[idx];
		idx++;
	}
	la_new[LA_MAXLEN] = la[LA_MAXLEN];
	la_new[LA_MAXLEN + 1] = la[LA_MAXLEN + 1];
	return (la_new);
}
