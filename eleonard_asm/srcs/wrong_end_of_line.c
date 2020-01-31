/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_end_of_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:05:38 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:05:39 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	wrong_end_of_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
				break ;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
