/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tinkotsu <tinkotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:33:36 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/13 18:59:36 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*pf_hex(int n)
{
	int		len;
	char	*arr;
	int		nb;

	len = 1;
	nb = n;
	while (nb /= 16)
		len++;
	if (!(arr = (char*)malloc(len + 1)))
		case_of_error();
	arr[len] = '\0';
	arr[--len] = (n % 16 < 10) ? (n % 16) + 48 : (n % 16) + 87;
	while (n /= 16)
		arr[--len] = (n % 16 < 10) ? (n % 16) + 48 : (n % 16) + 87;
	return (arr);
}
