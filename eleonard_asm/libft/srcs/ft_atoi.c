/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:15:19 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/25 19:25:00 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long long int	res;
	int				sign;

	sign = 1;
	res = 0;
	if (*str == ' ' || *str == '+' || *str == '-' ||
		(*str >= 48 && *str <= 57) || (*str >= 9 && *str <= 13))
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if (*str == '+' || (*str == '-' && (sign *= -1)))
			str++;
		while (*str >= 48 && *str <= 57)
		{
			res = res * 10 + *str - '0';
			str++;
		}
		return (res * sign);
	}
	return (0);
}
