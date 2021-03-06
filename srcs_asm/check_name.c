/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:45:25 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:01:52 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_name(char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (name[len - 2] == '.' && name[len - 1] == 's')
		return (1);
	else
		return (0);
}
