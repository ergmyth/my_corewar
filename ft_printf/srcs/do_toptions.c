/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_toptions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:06:29 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 12:03:32 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdlib.h"

/*
** to fill fields of options structure
*/

void		fill_options(t_options *op, char ty)
{
	op->flag = NULL;
	op->width = -1;
	op->precision = -1;
	op->size = NULL;
	op->type = ty;
	op->f_do = NULL;
	op->argnum = 0;
	op->f_ldo = &double_parse;
	op->f_fdo = &float_parse;
	if (ty == T_D || ty == T_I || ty == T_I || ty == T_U || ty == T_DD)
		op->f_do = &do_int_option;
	else if (ty == T_O || ty == T_INT_X || ty == T_INT_XX)
		op->f_do = &do_oxx_option;
	else if (op->type == T_STR)
		op->f_do = &do_s_option;
	else if (op->type == T_P)
		op->f_do = &do_p_option;
	else if (op->type == T_B)
		op->f_do = &do_b_option;
	else if (op->type == T_CHAR || op->type == T_PER || op->type == T_SYS_CHAR)
		op->f_do = &do_c_option;
	else if (op->type == T_FILE)
		op->f_do = &do_file_option;
	else if (op->type == T_DATE)
		op->f_do = &do_date_option;
}

void		free_options(t_options *op)
{
	ft_strdel(&(op->flag));
	ft_strdel(&(op->size));
}
