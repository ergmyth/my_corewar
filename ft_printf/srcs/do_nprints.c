/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_nprints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:49:32 by clianne           #+#    #+#             */
/*   Updated: 2019/10/23 20:16:38 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
** to get align: 0 - left, 1 - right
*/

size_t		n_get_align(t_options node)
{
	if (node.flag && ft_strchr(node.flag, '-'))
		return (0);
	return (1);
}

/*
** to get qty of symbols for printing
*/

size_t		n_get_slen(t_nprints p, int is_zero)
{
	size_t	len;

	len = (p.sign == ' ' || p.sign == '+' || p.sign == '-') ? 1 : 0;
	if (!(is_zero))
		len += ft_strlen(p.snum);
	return (len);
}

/*
** to get sign char according to flag/positive/negative
*/

char		n_get_sign(t_options node)
{
	if ((node.type == 'd' || node.type == 'i' || node.type == 'f')
		&& node.flag)
	{
		if (ft_strchr(node.flag, '+'))
			return ('+');
		else if (ft_strchr(node.flag, ' '))
			return (' ');
	}
	return ('a');
}
