/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:33:39 by jflorent          #+#    #+#             */
/*   Updated: 2019/10/29 15:42:16 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		color(char *str, int *i)
{
	int		n;

	if (str[*i] == '{' && str[*i + 1] == '{')
		(*i)++;
	if (str[*i] == '{' && (!*i || str[*i - 1] != '{') &&
		(n = set_color(&str[*i])))
		*i += n + 2;
}

int			do_tmp(t_va_arg *temp, va_list ap, int a)
{
	free_list(&temp);
	va_end(ap);
	return (a);
}

int			do_func(t_options options, t_va_arg *top)
{
	int		n;

	if (options.type == '%' &&
		((n = options.f_do(options, (void *)'%')) == -1))
		return (-1);
	else if (options.type != '%' && top->flag == 2 &&
			((n = options.f_ldo(options, top->data2)) == -1))
		return (-1);
	else if (options.type != '%' && top->flag == 1 &&
			((n = options.f_fdo(options, top->data1)) == -1))
		return (-1);
	else if (options.type != '%' && !top->flag &&
			(n = options.f_do(options, top->data)) == -1)
		return (-1);
	return (n);
}
