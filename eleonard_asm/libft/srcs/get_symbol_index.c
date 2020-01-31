/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbol_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:22:20 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:22:21 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_symbol_index(char *str, char c)
{
	int	res;
	int	index;

	res = -1;
	index = 0;
	if (str)
	{
		while (str[index] && str[index] != c)
			index++;
		if (str[index] && str[index] == c)
			res = index;
	}
	return (res);
}
