/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:37:25 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/08 18:33:42 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (ft_check_overlap(d, s, n) == 1)
		return (ft_memmove(dst, src, n));
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
