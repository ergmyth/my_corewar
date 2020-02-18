/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:22:20 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/18 20:06:41 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	index_of(char *str, char c)
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
