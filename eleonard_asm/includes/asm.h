/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:00:03 by eleonard          #+#    #+#             */
/*   Updated: 2020/01/13 18:59:45 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//ПРОВЕРИТЬ ВСЕ МЕТКИ
//ПРЕВРАТИТЬ ВСЕ МЕТКИ В ЗНАЧЕНИЯ
//ПРОЧИТАТЬ ВСЕ КОМАНДЫ И СОСТАВИТЬ КОД


#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <stdio.h>

# define USAGE "Usage: ./asm <sourcefile.s>"
# define INVALID_READ_MSG "Can't read source file "
# define PARSE_COMPLETE_MSG "Writing output program to "

typedef struct		s_op
{
    char			*name;
    int             arg_count;
    int             arr[3];
    int             index;
    int             loops;
    char			*description;
    int             arg_type;
    int             dir_size;
}					t_op;

typedef struct		s_op_elem
{
    char            **labels;
    char            *name;
    int				args[3];
    char 			**value;
	int             bytes_before;
	int             index;

}                   t_op_elem;

typedef struct		s_labels
{
	char			**labels;
	int 			*line;
	int 			label_index;
	int 			labels_size;
}					t_labels;

typedef struct		s_s
{
	int				byte_value;
    char            **cur_args;
	char 			*name;
	char 			*comment;
	int 			fd;
	t_op_elem       *operations;
	int 			operations_size;
	t_labels 		*labels;
	int				line_index;
	int 			operations_index;
	t_op            op_tab[17];
	int				has_name;
	int				has_comment;
	int 			comment_written;
	char			*byte_code;
}					t_s;

char				*btoh(char *str);
void				add_args_code(char *str, int *len, t_op_elem cur_op, t_s *s);
int					only_numbers(const char *str);
void				convert_labels_to_numbers(t_s *s);
int					check_labels(t_s *s);
int 				check_args(int op_index, t_s *s);
void	            get_args(int op_index, t_s *s, char *str);
void	            read_operation(char *line, t_s *s);
void                read_line(char *line, t_s *s);
void				add_till_CEC(t_s *s);
void				fill_by_zeroes(char *str, int len);
void				add_str_to_byte_code(t_s *s, char *str, int len);
void				encrypt_line(char *line, t_s *s);
char            	*pf_hex(int n);
int 				wrong_end_of_line(char *str);
t_s					*initialize(void);
void				print_func(char *msg, char *src_name);
int					check_name(char *name);
void				do_parse(t_s *s);
void				case_of_error(void);
void				add_null_octets(t_s *s);

#endif
