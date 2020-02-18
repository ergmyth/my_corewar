/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_of_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:46:04 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:01:30 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	case_of_error(char *n, int line)
{
	if (line)
	{
		ft_putstr_fd(n, 2);
		ft_putnbr_fd(line, 2);
		ft_putchar('\n');
	}
	else
		ft_putendl_fd(n, 2);
	exit(1);
}
