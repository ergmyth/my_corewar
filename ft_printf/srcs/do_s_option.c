/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:08:51 by clianne           #+#    #+#             */
/*   Updated: 2019/10/25 17:15:34 by jflorent         ###   ########.fr       */
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
	char		x;

	i = 0;
	x = ' ';
	if (node.flag && ft_strchr(node.flag, '0'))
		x = '0';
	while (i++ < (node.width - min))
		ft_putchar(x);
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

int				do_s_option(t_options node, void *data)
{
	char	*str;
	int		min;

	if (!data)
		str = "(null)";
	else
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
