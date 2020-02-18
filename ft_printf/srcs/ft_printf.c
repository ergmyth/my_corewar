/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:42:29 by clianne           #+#    #+#             */
/*   Updated: 2019/10/29 15:49:32 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_va_arg	*get_node(t_va_arg *head, int num)
{
	while (head)
	{
		if (head->idx == num)
			return (head);
		else
			head = head->next;
	}
	return (0);
}

static int		parse_args(t_options options, t_va_arg *head)
{
	t_va_arg		*top;
	static int		count;
	int				n;

	n = 0;
	top = 0;
	if (options.width == -2)
		options.width = (int)get_node(head, count++)->data;
	if (options.precision == -2)
		options.precision = (int)get_node(head, count++)->data;
	if (options.argnum != 0 && options.type != '%')
	{
		top = get_node(head, (options.argnum - 1));
		count = options.argnum;
	}
	else if (options.type != '%')
		top = get_node(head, count++);
	if (options.type != '%' && !(top->next))
		count = 0;
	if ((n = do_func(options, top)) == -1)
		return (-1);
	return (n);
}

static int		read_string(char *str, t_va_arg *head)
{
	t_options	options;
	int			i;
	int			n;
	static int	len;

	i = -1;
	n = 0;
	while (str[++i])
	{
		color(str, &i);
		if (str[i] == '%')
		{
			i += add_op_node(&options, &str[i]);
			n = parse_args(options, head);
			free_options(&options);
			if (n == -1)
				return (ret_get_list(&head, -1));
			len += n;
		}
		else
			ft_putchar(str[i]);
	}
	return (len);
}

static int		count_options(char *str, t_va_arg **list)
{
	int			i;
	t_options	options;
	int			len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			fill_options(&options, 0);
			i += add_op_node(&options, &str[i]);
			if (options.type == 0 || !get_list(options, list))
			{
				free_options(&options);
				return (ret_get_list(list, -1));
			}
			free_options(&options);
			len--;
		}
		i++;
		len++;
	}
	return (len);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_va_arg	*list;
	t_va_arg	*temp;
	int			len;
	int			n;

	list = 0;
	if ((len = count_options((char*)format, &list)) == -1)
		return (0);
	temp = list;
	va_start(ap, format);
	while (list)
	{
		if (list->flag == 2)
			list->data2 = va_arg(ap, long double);
		else if (list->flag)
			list->data1 = va_arg(ap, double);
		else
			list->data = va_arg(ap, void *);
		list = list->next;
	}
	if ((n = read_string((char*)format, temp)) == -1)
		return (-1);
	else
		return (do_tmp(temp, ap, len + n));
}
