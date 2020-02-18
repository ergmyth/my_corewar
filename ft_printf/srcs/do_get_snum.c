/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_get_snum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:16:05 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 12:05:59 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_snum_di(void *data, t_options node)
{
	if (!node.size)
		return (ft_litoa_base(((long long int)((int)data)), 10, 0));
	else if (!ft_strcmp(node.size, "h"))
		return (ft_litoa_base((long long int)((short int)data), 10, 0));
	else if (!ft_strcmp(node.size, "hh"))
		return (ft_litoa_base((long long int)((signed char)data), 10, 0));
	else if (!ft_strcmp(node.size, "l"))
		return (ft_litoa_base((long long int)((long int)data), 10, 0));
	else if (!ft_strcmp(node.size, "ll"))
		return (ft_litoa_base((long long int)data, 10, 0));
	return (NULL);
}

static char		*get_snum_u(void *data, t_options node)
{
	if (!node.size)
		return (ft_ulitoa_base(((unsigned long long int)((unsigned int)data)),
			10, 0));
	else if (!ft_strcmp(node.size, "h"))
		return (ft_ulitoa_base((unsigned long long int)
			((unsigned short int)data), 10, 0));
	else if (!ft_strcmp(node.size, "hh"))
		return (ft_ulitoa_base((unsigned long long int)((unsigned char)data),
			10, 0));
	else if (!ft_strcmp(node.size, "l"))
		return (ft_ulitoa_base((unsigned long long int)
			((unsigned long int)data), 10, 0));
	else if (!ft_strcmp(node.size, "ll"))
		return (ft_ulitoa_base(
			(unsigned long long int)((unsigned long long int)data), 10, 0));
	else
		return (NULL);
}

static char		*get_snum_oxx(void *data, t_options node, int base, size_t xx)
{
	if (!node.size)
		return (ft_ulitoa_base(((unsigned long long int)((unsigned int)data)),
					base, xx));
	else if (!ft_strcmp(node.size, "h"))
		return (ft_ulitoa_base((unsigned long long int)
					((unsigned short int)data), base, xx));
	else if (!ft_strcmp(node.size, "hh"))
		return (ft_ulitoa_base((unsigned long long int)
					((unsigned char)data), base, xx));
	else if (!ft_strcmp(node.size, "l"))
		return (ft_ulitoa_base((unsigned long long int)
					((unsigned long int)data), base, xx));
	else if (!ft_strcmp(node.size, "ll"))
		return (ft_ulitoa_base(
			(unsigned long long int)((unsigned long long int)data), base, xx));
	else
		return (NULL);
}

char			*get_snum(void *data, t_options node)
{
	if (node.type == T_D ||
		node.type == T_I || node.type == T_II)
		return (get_snum_di(data, node));
	else if (node.type == 'u' || node.type == T_DD)
		return (get_snum_u(data, node));
	else if (node.type == 'o')
		return (get_snum_oxx(data, node, 8, 0));
	else if (node.type == 'x' || node.type == 'X')
		return (get_snum_oxx(data, node, 16, node.type == 'X'));
	return (NULL);
}
