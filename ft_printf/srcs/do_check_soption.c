/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_check_soption.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:43:42 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 11:59:59 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** to check soption = $
*/

int		t_check__soption(int index, char *soptions,
	size_t part_of_options, t_options *data)
{
	if (ft_strchr(soptions, '$') && !(part_of_options & 16))
	{
		data->argnum = ft_atoi(soptions);
		part_of_options |= (1 << 4);
		while (soptions[index] && soptions[index] != '$')
			index++;
		if (soptions[index] == '$')
			index++;
	}
	return (index);
}

/*
** to check soption = flag
*/

int		t_check_flag_soption(int index, char *soptions,
	size_t part_of_options, t_options *data)
{
	if (check_flag(soptions[index]) && !(part_of_options & 2))
	{
		while (soptions[index] && check_flag(soptions[index]))
		{
			index++;
		}
		data->flag = ft_strsub(soptions, 0, index);
		part_of_options = part_of_options | 1 << 0;
	}
	return (index);
}

/*
** to check soption = width
*/

int		t_check_width_soption(int index, char *soptions,
	size_t part_of_options, t_options *data)
{
	if (check_width(soptions[index]) && !(part_of_options & 2))
	{
		if (soptions[index] == '*')
		{
			data->width = -2;
			index++;
		}
		else
		{
			data->width = ft_atoi(&soptions[index]);
			while (soptions[index] && check_width(soptions[index]))
				index++;
		}
		part_of_options = part_of_options | 1 << 1;
	}
	return (index);
}

/*
** to check soption = precision
*/

int		t_check_prec_soption(int index, char *soptions,
	size_t part_of_options, t_options *data)
{
	if (check_precision(soptions[index], 1) && !(part_of_options & 4))
	{
		if (soptions[++index] == '*')
		{
			data->precision = -2;
			index++;
		}
		else
		{
			data->precision = ft_atoi(&soptions[index]);
			while (soptions[index] && check_precision(soptions[index], 2))
				index++;
		}
		part_of_options = part_of_options | 1 << 2;
	}
	return (index);
}

/*
** to check soption = precision
*/

int		t_check_size_soption(int index, char *soptions,
	size_t part_of_options, t_options *data)
{
	if (check_size(soptions[index]) && !(part_of_options & 8))
	{
		data->size = ft_strsub(soptions, index, ft_strlen(soptions) - index);
		part_of_options = part_of_options | 1 << 3;
		while (soptions[index] && check_size(soptions[index]))
			index++;
	}
	return (index);
}
