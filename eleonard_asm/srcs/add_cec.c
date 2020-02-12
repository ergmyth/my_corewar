/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:08:28 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/12 14:10:36 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_cec(t_s *s)
{
	s->comment_written = 1;
	add_null_octets(s);
	s->cec_ind = add_null_octets(s);
	add_str_to_byte_code(s, s->comment, COMMENT_LENGTH * 2);
	add_null_octets(s);
}
