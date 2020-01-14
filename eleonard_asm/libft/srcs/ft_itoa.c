/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:48:18 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/03 13:29:37 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		nb;
	int		t;

	len = 1;
	t = 0;
	if ((nb = n) && n < 0)
		len++;
	while (nb /= 10)
		len++;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		t = 1;
	if (n < 0 && (n = -n - t))
		str[0] = '-';
	str[--len] = n % 10 + '0' + t;
	while (n /= 10)
		str[--len] = n % 10 + '0';
	return (str);
}
