/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:47:54 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/09 11:45:26 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_2;
	unsigned char	*s_1;

	s_1 = (unsigned char*)s1;
	s_2 = (unsigned char*)s2;
	while (n > 1 && *s_1 == *s_2 && s_1++ && s_2++)
		n--;
	if (n == 0 || *s_1 == *s_2)
		return (0);
	return ((int)*s_1 - (int)*s_2);
}
