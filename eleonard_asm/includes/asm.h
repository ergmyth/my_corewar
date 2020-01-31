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

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <stdio.h>

# define USAGE "Usage: ./asm <sourcefile.s>"
# define INVALID_READ_MSG "Can't read source file "
# define PARSE_COMPLETE_MSG "Writing output program to "

# define ERR_MALLOC 3
# define ERR_TOO_BIG_CHAMP_SIZE 4
# define ERR_TOO_BIG_REG_NUMBER 5
# define ERR_GNL 6
# define ERR_NAME_OR_COMMENT 7
# define ERR_HAVENT_END_QUOTE 8
# define ERR_LEXICAL 9
# define ERR_TOO_LONG_NAME 10
# define ERR_TOO_LONG_COMMENT 11
# define ERR_WRONG_OP_NAME 12
# define ERR_FD 13


typedef struct	s_op
{
	char		*name;
	int			arg_count;
	int			arr[3];
	int			index;
	int			loops;
	char		*description;
	int			arg_type;
	int			dir_size;
}				t_op;

typedef struct	s_op_elem
{
	char		**labels;
	char		*name;
	int			args[3];
	char		**value;
	int			bytes_before;
	int			index;
}				t_op_elem;

typedef struct	s_labels
{
	char		**labels;
	int			*line;
	int			label_index;
	int			labels_size;
}				t_labels;

typedef struct	s_s
{
	int			byte_value;
	char		**args;
	char		*name;
	char		*comment;
	int			fd;
	t_op_elem	*operations;
	int 		cec_ind;
	int 		commands_start_ind;
	int			size;
	t_labels	*labels;
	int			line_index;
	int			oper_index;
	t_op		op_tab[17];
	int			has_name;
	int			has_comment;
	int			comment_written;
	unsigned char	*byte_code;
}				t_s;

void			create_file(char **av, char *str);
void			convert_operations_to_byte_code(t_s *s);
void			add_args_code(char *str, int *len, t_op_elem cur_op, t_s *s);
void			convert_labels_to_numbers(t_s *s);
int				check_labels(t_s *s);
int				check_args(int op_index, t_s *s);
void			get_args(int op_index, t_s *s, char *str);
void			read_operation(char *line, t_s *s);
void			read_line(char *line, t_s *s);
void			add_till_cec(t_s *s);
void			fill_by_zeroes(char *str, int len);
void			add_str_to_byte_code(t_s *s, char *str, int len);
void			encrypt_line(char *line, t_s *s);
int				wrong_end_of_line(char *str);
t_s				*initialize(void);
void			print_func(char *msg, char *src_name);
int				check_name(char *name);
void			do_parse(t_s *s);
void			case_of_error(int n);
int				add_null_octets(t_s *s);

#endif
