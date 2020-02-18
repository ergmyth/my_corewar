/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_index_of.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:04:14 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/18 20:04:29 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	last_index_of(char *str, char c)
{
	int	res;
	int	index;

	res = -1;
	index = 0;
	if (str)
	{
		while (str[index])
		{
			if (str[index] == c)
				res = index;
			index++;
		}
	}
	return (res);
}
