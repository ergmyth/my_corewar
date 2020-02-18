/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nan_and_inf_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 09:26:50 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/29 13:13:11 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putnstr(char *s, int n)
{
	int		count;

	count = 0;
	while (*s && count++ < n)
		ft_putchar(*s++);
}

static int		print_sp_str(t_options node, int min, char *str)
{
	int			i;

	i = 0;
	while (i++ < (node.width - min))
		ft_putchar(' ');
	ft_putnstr(str, min);
	return (i + min - 1);
}

static int		print_str_sp(t_options node, int min, char *str)
{
	int			i;

	i = 0;
	ft_putnstr(str, min);
	while (i++ < (node.width - min))
		ft_putchar(' ');
	return (min + i - 1);
}

int				do_nai_option(t_options node, void *data)
{
	char	*str;
	int		min;

	str = (char*)data;
	if (!node.precision)
		str = "";
	if (node.precision != -1)
		min = ft_min2(ft_strlen(str), node.precision);
	else
		min = ft_strlen(str);
	if (node.width > min && (!node.flag || (node.flag &&
			!ft_strchr(node.flag, '-'))))
		return (print_sp_str(node, min, str));
	else if (node.width > min && node.flag && ft_strchr(node.flag, '-'))
		return (print_str_sp(node, min, str));
	else
		ft_putnstr(str, min);
	return (min);
}
