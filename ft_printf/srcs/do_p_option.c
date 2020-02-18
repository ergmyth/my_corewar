/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:06:50 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/29 15:28:00 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_sp_data(t_options node, int min, int len, void *data)
{
	int			i;

	i = 0;
	while (i++ < (node.width - min))
		ft_putchar(' ');
	ft_putstr("0x");
	if (len != min)
		while (len++ < min + 2)
			ft_putchar('0');
	ft_putstr(ft_litoa_base((long int)data, 16, 0));
}

static void		print_data_sp(t_options node, int min, int len, void *data)
{
	int			i;

	i = 0;
	ft_putstr("0x");
	if (len != min)
		while (len++ < min + 2)
			ft_putchar('0');
	ft_putstr(ft_litoa_base((long int)data, 16, 0));
	while (i++ < (node.width - min))
		ft_putchar(' ');
}

static int		ret_min(int precision, int len)
{
	if (precision > len)
		return (precision);
	else
		return (len);
}

int				do_p_option(t_options node, void *data)
{
	int		min;
	int		len;
	char	*s;

	if (!node.precision)
		return (do_s_option(node, "0x"));
	len = llen_value((long int)data, 16) + 2;
	if (len == 2)
		len++;
	min = ret_min(node.precision, len);
	if (node.width > min && (!node.flag || (node.flag &&
			!ft_strchr(node.flag, '-'))))
		print_sp_data(node, min, len, data);
	else if (node.width > min && node.flag && ft_strchr(node.flag, '-'))
		print_data_sp(node, min, len, data);
	else
	{
		ft_putstr("0x");
		if (len != min)
			while (len++ < min + 2)
				ft_putchar('0');
		ft_putstr((s = ft_litoa_base((long int)data, 16, 0)));
		ft_strdel(&s);
	}
	return (ft_max2(min, node.width));
}
