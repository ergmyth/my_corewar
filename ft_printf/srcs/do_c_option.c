/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_c_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:54:20 by jflorent          #+#    #+#             */
/*   Updated: 2019/11/04 13:31:06 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	spec_sym_c(t_options node, char c)
{
	if (c >= 1 && c <= 11)
		return (spec1(node, c));
	else if (c >= 12 && c <= 23)
		return (spec2(node, c));
	else if ((c >= 24 && c <= 31) || c == 127)
		return (spec3(node, c));
	return (-1);
}

static int	put_space_and_char(t_options node, char c, int width)
{
	int		i;
	char	x;

	i = 0;
	x = ' ';
	if (node.flag && ft_strchr(node.flag, '0'))
		x = '0';
	while (i++ < (width - 1))
		ft_putchar(x);
	ft_putchar(c);
	return (i);
}

static int	put_char_and_space(t_options node, char c, int width)
{
	int		i;
	char	x;

	i = 0;
	x = ' ';
	if (node.flag && ft_strchr(node.flag, '0'))
		x = '0';
	ft_putchar(c);
	while (i++ < (width - 1))
		ft_putchar(' ');
	return (i);
}

int			do_c_option(t_options node, void *data)
{
	unsigned char	c;

	c = (unsigned char)data;
	if (node.type == T_SYS_CHAR && ((c > 0 && c <= 31) || c == 127))
		return (spec_sym_c(node, c));
	if (node.width > 1 && (!node.flag || !ft_strchr(node.flag, '-')))
		return (put_space_and_char(node, c, node.width));
	else if (node.width > 1 && (node.flag && ft_strchr(node.flag, '-')))
		return (put_char_and_space(node, c, node.width));
	else
		ft_putchar(c);
	return (1);
}
