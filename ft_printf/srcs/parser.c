/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:56:29 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 11:58:26 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdlib.h"

/*
** to free memory, allocated for soptions
*/

static int		free_soptions(char *soptions, int len)
{
	ft_strdel(&soptions);
	return (len);
}

/*
** options parsing and node creation
*/

size_t			add_op_node(t_options *data, char *s)
{
	size_t		index;
	char		*soptions;
	size_t		part_of_options;

	index = 1;
	soptions = 0;
	while (s[index] && !check_format(s[index]))
		index++;
	if (!s[index])
		return (0);
	if (!s[index] || !(soptions = ft_strsub(s, 1, index - 1)))
		return (free_soptions(soptions, 0));
	fill_options(data, s[index]);
	index = 0;
	part_of_options = 0;
	index = t_check__soption(index, soptions, part_of_options, data);
	index = t_check_flag_soption(index, soptions, part_of_options, data);
	index = t_check_width_soption(index, soptions, part_of_options, data);
	index = t_check_prec_soption(index, soptions, part_of_options, data);
	index = t_check_size_soption(index, soptions, part_of_options, data);
	return ((!soptions) ? free_soptions(soptions, 0) :
		free_soptions(soptions, index + 1));
}
