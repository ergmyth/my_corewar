/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:18:49 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/03 16:02:41 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_color2(char *color)
{
	if (!ft_strcmp(color, "magenta"))
	{
		ft_putstr(ANSI_COLOR_MAGENTA);
		return (7);
	}
	else if (!ft_strcmp(color, "cyan"))
	{
		ft_putstr(ANSI_COLOR_CYAN);
		return (4);
	}
	else if (!ft_strcmp(color, "eoc"))
	{
		ft_putstr(ANSI_COLOR_RESET);
		return (3);
	}
	return (0);
}

static int	check_color(char *color)
{
	if (!ft_strcmp(color, "red"))
	{
		ft_putstr(ANSI_COLOR_RED);
		return (3);
	}
	else if (!ft_strcmp(color, "green"))
	{
		ft_putstr(ANSI_COLOR_GREEN);
		return (5);
	}
	else if (!ft_strcmp(color, "yellow"))
	{
		ft_putstr(ANSI_COLOR_YELLOW);
		return (6);
	}
	else if (!ft_strcmp(color, "blue"))
	{
		ft_putstr(ANSI_COLOR_BLUE);
		return (4);
	}
	return (check_color2(color));
}

int			set_color(char *str)
{
	char	color[8];
	int		i;

	i = 0;
	str++;
	while (*str != '}' && *str != '\0' && i < 7)
		color[i++] = *str++;
	if (*str != '}')
		return (0);
	color[i] = '\0';
	return (check_color(color));
}
