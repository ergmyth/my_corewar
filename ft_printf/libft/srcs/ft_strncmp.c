/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:16:47 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/12 09:38:14 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 1 && (unsigned char)*s1 == (unsigned char)*s2
			&& *s2 && s1++ && s2++)
		n--;
	if (n == 0 || (unsigned char)*s1 == (unsigned char)*s2)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
