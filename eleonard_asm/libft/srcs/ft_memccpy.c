/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:15:11 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/07 19:54:48 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	if (ft_check_overlap(d, s, n) == 1)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
		if ((unsigned char)s[i - 1] == (unsigned char)c)
			return (d + i);
	}
	return (NULL);
}
