/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:56:01 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/22 11:13:58 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		spec1(t_options node, char c)
{
	if (c == 1)
		return (do_s_option(node, "SOH"));
	else if (c == 2)
		return (do_s_option(node, "STX"));
	else if (c == 3)
		return (do_s_option(node, "ETX"));
	else if (c == 4)
		return (do_s_option(node, "EOT"));
	else if (c == 5)
		return (do_s_option(node, "ENQ"));
	else if (c == 6)
		return (do_s_option(node, "ACK"));
	else if (c == 7)
		return (do_s_option(node, "BEL"));
	else if (c == 8)
		return (do_s_option(node, "BS"));
	else if (c == 9)
		return (do_s_option(node, "TAB"));
	else if (c == 10)
		return (do_s_option(node, "LF"));
	else if (c == 11)
		return (do_s_option(node, "VT"));
	return (-1);
}

int		spec2(t_options node, char c)
{
	if (c == 12)
		return (do_s_option(node, "FF"));
	else if (c == 13)
		return (do_s_option(node, "CR"));
	else if (c == 14)
		return (do_s_option(node, "SO"));
	else if (c == 15)
		return (do_s_option(node, "SI"));
	else if (c == 16)
		return (do_s_option(node, "DLE"));
	else if (c == 17)
		return (do_s_option(node, "DC1"));
	else if (c == 18)
		return (do_s_option(node, "DC2"));
	else if (c == 19)
		return (do_s_option(node, "DC3"));
	else if (c == 20)
		return (do_s_option(node, "DC4"));
	else if (c == 21)
		return (do_s_option(node, "NAK"));
	else if (c == 22)
		return (do_s_option(node, "SYN"));
	else if (c == 23)
		return (do_s_option(node, "ETB"));
	return (-1);
}

int		spec3(t_options node, char c)
{
	if (c == 24)
		return (do_s_option(node, "CAN"));
	else if (c == 25)
		return (do_s_option(node, "EM"));
	else if (c == 26)
		return (do_s_option(node, "SUB"));
	else if (c == 27)
		return (do_s_option(node, "ESC"));
	else if (c == 28)
		return (do_s_option(node, "FS"));
	else if (c == 29)
		return (do_s_option(node, "GS"));
	else if (c == 30)
		return (do_s_option(node, "RS"));
	else if (c == 31)
		return (do_s_option(node, "US"));
	else if (c == 127)
		return (do_s_option(node, "DEL"));
	return (-1);
}
