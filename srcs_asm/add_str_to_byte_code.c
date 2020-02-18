/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_to_byte_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:00:48 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/29 15:00:51 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_str_to_byte_code(t_s *s, char *str, int len)
{
	int		i;
	char	*temp;
	int		pre_len;
	int		post_len;

	i = 0;
	pre_len = ft_strlen(s->byte_code);
	post_len = pre_len;
	while (str[i])
	{
		temp = pf_hex((unsigned char)str[i++]);
		if (ft_strlen(temp) == 1)
		{
			s->byte_code[post_len] = '0';
			s->byte_code[post_len + 1] = temp[0];
		}
		else
		{
			s->byte_code[post_len] = temp[0];
			s->byte_code[post_len + 1] = temp[1];
		}
		ft_strdel(&temp);
		post_len += 2;
	}
	fill_by_zeroes(s->byte_code, len - (post_len - pre_len));
}
