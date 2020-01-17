/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:56:42 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/13 18:04:32 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	int		fd;
	t_s		*s;

	if (ac == 2)
	{
		s = initialize();
		s->fd = open(av[1], O_RDONLY);
		if (fd == -1)
			print_func(INVALID_READ_MSG, av[1]);
		else if (check_name(av[1]))
		{
			do_parse(s);
			//create_file();
			print_func(PARSE_COMPLETE_MSG, av[1]);
		}
		else
			print_func(USAGE, av[1]);//Не подходит имя, что делать
	}
	else
		print_func(USAGE, av[1]);
}
/*
 * 1. Считать строку;
 * 2. Проверить метка ли;
 *  2.1 Записать метку в массив;
 *  2.2 Проверить есть ли после метки на той же строке инструкция;
 *   2.2.1 Перейти к след строке если нет, если да то обработать её и добавить новый элемент массива для след инструкции;
 *
 * 1. Убрать пробелы спереди. Считать строку от начала, до знака метки. Проверить чтобы таких меток больше не было.
 * 2. Если от начала до двоеточия не получается название метки, то считываю как команду.
 */