/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:01:22 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/31 18:01:43 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	only_spaces(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR)
		{
			if (!is_space(str[i]))
				return (0);
			i++;
		}
	}
	return (1);
}
