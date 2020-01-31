/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_power.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:05:30 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:05:31 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int n, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
		return (n * ft_recursive_power(n, power - 1));
}
