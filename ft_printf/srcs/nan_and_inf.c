/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nan_and_inf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:22:09 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/29 13:12:49 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr_m(char *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_strchr(s, c));
}

int			nan_and_inf(t_options options, long int *result)
{
	options.precision = -1;
	if (result[2] == 0)
	{
		if (!result[0] && ft_strchr_m(options.flag, '+'))
			return (do_nai_option(options, (void*)"+inf"));
		else if (!result[0] && ft_strchr_m(options.flag, ' '))
			return (do_nai_option(options, (void*)" inf"));
		else if (!result[0] && !ft_strchr_m(options.flag, '+'))
			return (do_nai_option(options, (void*)"inf"));
		else
			return (do_nai_option(options, (void*)"-inf"));
	}
	else
		return (do_nai_option(options, (void*)"nan"));
}

static int	check_bits(long long int result)
{
	int		j;

	j = 63;
	while (j >= 48)
	{
		if ((result >> j) & 1)
			return (1);
		j--;
	}
	return (0);
}

int			d_nan_and_inf(t_options options, long long int *result)
{
	options.precision = -1;
	if (!check_bits(result[3]))
	{
		if (!result[0] && ft_strchr_m(options.flag, '+'))
			return (do_nai_option(options, (void*)"+inf"));
		else if (!result[0] && ft_strchr_m(options.flag, ' '))
			return (do_nai_option(options, (void*)" inf"));
		else if (!result[0] && !ft_strchr_m(options.flag, '+'))
			return (do_nai_option(options, (void*)"inf"));
		else
			return (do_nai_option(options, (void*)"-inf"));
	}
	else
		return (do_nai_option(options, (void*)"nan"));
}
