/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_till_cec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:05:29 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/31 18:06:34 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_till_cec(t_s *s)
{
	s->comment_written = 1;
	add_null_octets(s);
	s->cec_ind = add_null_octets(s);
	add_str_to_byte_code(s, s->comment, COMMENT_LENGTH * 2);
	add_null_octets(s);
}
