/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:03:03 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:03:04 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itob(int n)
{
	int		len;
	char	*arr;
	int		nb;

	len = 1;
	nb = n;
	while (nb /= 2)
		len++;
	if (!(arr = (char*)malloc(len + 1)))
		return (NULL);
	arr[len] = '\0';
	arr[--len] = n % 2 == 0 ? '0' : '1';
	while (n /= 2)
		arr[--len] = n % 2 == 0 ? '0' : '1';
	return (arr);
}
