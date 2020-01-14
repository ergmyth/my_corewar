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

typedef struct		s_op
{
    char			*name;
    int             arg_count;
    int             arr[3];
    int             index;
    int             loops;
    char			*description;
    int             arg_type;
    int             some_int2;
}					t_op;

typedef struct		s_s
{
	int				quote_opened;
	char 			*name;
	char 			*comment;
	int 			fd;
	int				has_name;
	int				has_comment;
	char			*byte_code;
}					t_s;

void				add_str_to_byte_code(t_s *s, char *str, int len);
void				encrypt_line(char *line, t_s *s);
char            	*pf_hex(int n);
int 				wrong_end_of_line(char *str);
char		        *skip_whitespaces(char *line);
void				create_file(void);
t_s					*initialize(void);
void				print_func(char *msg, char *src_name);
int					check_name(char *name);
void				do_parse(t_s *s);
void				case_of_error(void);

#endif
