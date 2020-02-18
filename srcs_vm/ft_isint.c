/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:09:19 by clianne           #+#    #+#             */
/*   Updated: 2020/02/15 09:12:30 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** to check if number in string is between MIN_INT and MAX_INT
*/

size_t	ft_isint(char *s)
{
	int		a;
	size_t	idx;
	char	*s1;
	int		res;

	if (!s)
		return (0);
	if (s[0] == '+' && ft_isdigit(s[1]))
	{
		idx = 1;
		while (s[idx] != '\0')
		{
			s[idx - 1] = s[idx];
			idx++;
		}
		s[idx - 1] = '\0';
	}
	a = ft_atoi(s);
	s1 = ft_itoa(a);
	res = (!ft_strcmp(s, s1) ? 1 : 0);
	ft_strdel(&s1);
	return (res);
}
