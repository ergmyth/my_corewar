/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:00:03 by eleonard          #+#    #+#             */
/*   Updated: 2020/02/18 20:06:20 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <stdio.h>

# define INVALID_READ_MSG "Can't read source file "
# define PARSE_COMPLETE_MSG "Writing output program to "

# define ERR_TOO_BIG_REG_NUMBER "Register number error at line "
# define ERR_NAME_OR_COMMENT "Champion name or comment error at line "
# define ERR_HAVENT_END_QUOTE "Haven't end quote. Error at line "
# define ERR_LEXICAL "Lexical error at line "
# define ERR_TOO_LONG_NAME "Long name error at line "
# define ERR_TOO_LONG_COMMENT "Long comment error at line "
# define ERR_WRONG_OP_NAME "Operation name error at line "
# define ERR_COMMAND_ARG "Command argument error at line "

# define USAGE "Usage: ./asm <sourcefile.s>"
# define ERR_END_OF_FILE "Syntax error - unexpected end of input"
# define ERR_MALLOC "Allocation error"
# define ERR_GNL "Read error"
# define ERR_FD "File error"
# define ERR_NO_SUCH_LABEL ", no such label"
# define ERR_NO_CODE "Champion code error"

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

extern t_op		g_op_tab[17];

typedef struct	s_op_elem
{
	char		**l;
	char		*name;
	int			args[3];
	char		**value;
	int			l_size;
	int			bytes_before;
	int			index;
}				t_op_elem;

typedef struct	s_s
{
	int			byte_value;
	char		**args;
	char		*name;
	char		*comment;
	int			fd;
	t_op_elem	**op;
	int			cec_ind;
	int			commands_start_ind;
	int			size;
	int			line_index;
	int			op_i;
	t_op		op_tab[17];
	int			has_name;
	int			has_comment;
	int			comment_written;
	char		*byte_code;
	int			byte_code_size;
}				t_s;

int				have_one_quote(char *line, t_s *s);
void			getter(t_s *s, char *line, char c);
char			*put_after_quote(char *str, t_s *s);
char			*read_(t_s *s, char *line);
void			check_name_and_comment(t_s *s, char *str);
void			add_arg(int *len, char *command_code, t_s *s);
int				only_spaces(char *str);
void			init_operations(t_s *s, int i);
void			free_struct(t_s *s);
void			create_file(char **av, char *str);
void			convert_operations_to_byte_code(t_s *s);
void			add_args_code(int *len, t_op_elem *cur_op, t_s *s);
void			convert_labels_to_numbers(t_s *s);
int				check_args(int op_index, t_s *s);
void			get_args(int op_index, t_s *s, char *str);
void			read_operation(char *line, t_s *s);
void			read_line(char *line, t_s *s);
void			add_cec(t_s *s);
void			fill_by_zeroes(char *str, int len);
void			add_str_to_byte_code(t_s *s, char *str, int len);
void			encrypt_line(char *line, t_s *s);
int				wrong_end_of_line(char *str);
t_s				*initialize(void);
void			print_func(char *msg, char *src_name);
int				check_name(char *name);
void			do_parse(t_s *s);
int				add_null_octets(t_s *s);
void			case_of_error(char *n, int line);

#endif
