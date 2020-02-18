/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:12:29 by clianne           #+#    #+#             */
/*   Updated: 2019/11/19 16:48:44 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define T_D 'd'
# define T_DD 'D'
# define T_I 'i'
# define T_II 'I'
# define T_U 'u'
# define T_O 'o'
# define T_INT_X 'x'
# define T_INT_XX 'X'
# define T_FLOAT 'f'
# define T_FFLOAT 'F'
# define T_EFLOAT 'e'
# define T_EEFLOAT 'E'
# define T_GFLOAT 'g'
# define T_GGFLOAT 'G'
# define T_P 'p'
# define T_B 'b'
# define T_CHAR	'c'
# define T_STR 's'
# define T_FILE	'm'
# define T_DATE 'k'
# define T_SYS_CHAR 'r'
# define T_PER '%'
# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN	"\x1b[36m"
# define ANSI_COLOR_RESET	"\x1b[0m"
# define LA_BASE 10000
# define LA_BASELEN 4
# define LA_MAXLEN 5000
# define DEF_F_PREC 6

# include <stdarg.h>
# include "libft.h"

typedef struct			s_options
{
	char				*flag;
	int					argnum;
	int					width;
	int					precision;
	char				*size;
	char				type;
	int					(*f_do)(struct s_options, void *);
	int					(*f_fdo)(struct s_options, double);
	int					(*f_ldo)(struct s_options, long double);
}						t_options;

/*
** to store options for printing numbers
*/

typedef struct			s_nprints
{
	size_t				align;
	size_t				neg;
	char				sign;
	char				cfill;
	char				*snum;
	size_t				slen;
	size_t				qzero;
	char				*ho;
	char				sep;
	int					m_shift;
	size_t				is_lzero;
	int					n_is_null;
}						t_nprints;

/*
** to store options for printing float ...
*/

typedef struct			s_fprints
{
	int					shift;
	int					l_num;
	int					l_prec;
	int					q_align;
	char				cfill;
	size_t				align;
}						t_fprints;

/*
** to store list of va_arg with index
*/

typedef struct			s_va_arg
{
	int					idx;
	void				*data;
	int					flag;
	double				data1;
	long double			data2;
	struct s_va_arg		*next;
}						t_va_arg;

int						ft_printf(const char *restrict format, ...);

void					ft_putstr_sf(char const *str, size_t pos_start,
		size_t pos_finish);
void					ft_putstr_s(char const *str, size_t pos_start);
void					ft_putstr_r(char const *str, size_t n);
void					ft_putstr_fill(char const *str, size_t qfill,
		char cfill);

int						check_format(char c);
int						check_flag(char c);
int						check_width(char c);
int						check_precision(char c, size_t index);
int						check_size(char c);
int						do_print_char(int l, int p, char c);
int						n_do_print_sign(t_nprints p);
int						n_do_print_align(t_options node, t_nprints p);
int						f_do_print_align(t_options node, t_nprints p);
char					f_get_qzero(t_options node, t_nprints p);
char					*get_s(int n, size_t bl);
void					color(char *str, int *i);
int						do_tmp(t_va_arg *temp, va_list ap, int a);
int						do_func(t_options options, t_va_arg *top);

void					do_print_nprints(t_nprints p);

size_t					add_op_node(t_options *lst, char *s);

void					lst_print(t_options list);
void					fill_options(t_options *op, char type);
void					free_options(t_options *op);
char					*get_snum(void *data, t_options node);

int						options_parse(char *s);
int						do_int_option(t_options node, void *data);
int						do_oxx_option(t_options node, void *data);
int						do_date_option(t_options node, void *data);
int						do_f_option(t_options node, long int sign, int *num,
		int *la);
int						do_e_option(t_options node, long int sign, int *num,
		int *la);
void					get_e_nprints(t_options node, t_nprints *p,
		long int sign, int *num);
int						do_e_print(t_options node, int shift);
int						do_g_option(t_options node, long int sign, int *num,
		int *la);
int						do_s_option(t_options node, void *data);
int						do_c_option(t_options node, void *data);
int						do_p_option(t_options node, void *data);
int						do_b_option(t_options node, void *data);
int						float_parse(t_options options, double data);
int						do_file_option(t_options options, void *data);
int						get_next_line(const int fd, char **line);
int						double_parse(t_options options, long double num);
void					double_parse_add(int *num,
										long long int *result, int *la);
int						nan_and_inf(t_options options, long int *result);
int						d_nan_and_inf(t_options options, long long int *result);
int						do_nai_option(t_options options, void *data);

size_t					n_get_align(t_options node);
size_t					n_get_slen(t_nprints p, int is_zero);
char					n_get_sign(t_options node);

int						ft_max2(int a, int b);
int						ft_max3(int a, int b, int c);
int						ft_min2(int a, int b);
int						ft_min3(int a, int b, int c);
void					do_power5(int *la, int power);
void					do_power2(int *la, int power);
int						do_la_get_qty(int *la);

int						len_value(int value, int base);
int						llen_value(long long int value, int base);
int						llint_len(long long int value);
int						int_len(int value);
char					*ft_itoa_base(int value, int base);
char					*ft_litoa_base(long long int value, int base,
		size_t xx);
char					*ft_ulitoa_base(unsigned long long int value,
		int base, size_t xx);

void					print_int(int n);
void					print_uint(int u);
void					print_double(double d);
void					print_char(char c);
void					print_str(char *s);
void					print_void(void *v);
int						push_back(t_options options, t_va_arg **head, int flag);
int						create_argnum(t_options options, t_va_arg **head,
										int flag, size_t *idx);
t_va_arg				*create_node(size_t idx, int flag);
void					free_list(t_va_arg **list);
int						ret_get_list(t_va_arg **list, int a);
int						get_list(t_options options, t_va_arg **list);
int						set_color(char *str);
int						spec1(t_options node, char c);
int						spec2(t_options node, char c);
int						spec3(t_options node, char c);

int						*do_iarray_create(size_t size);
void					do_iarray_copy(int *froma, int *toa, size_t size);
void					do_iarray_del(int **ia);
void					do_iarray_fill(int *ia, size_t size, int init);
void					do_iarray_sort_bubble(int *ia, size_t size,
		size_t order);
void					do_iarray_sort_quick(int *ia, int left, int right);

int						do_la_print(int *la_int, int flag);
int						do_rla_print(int *la_int, int flag);
int						do_la_qdigits(int *la);
int						do_rla_qdigits(int *la_int);
int						do_rla_qdigits_n(int *la_int, int n);
int						*do_la_create_from_str(char *s);
int						*do_rla_create_from_str(char *s);
int						*do_la_reverse_qp(int *la, int qty, int power);
int						*do_la_reverse(int *la);
void					do_la_add_la(int *la_int_1, int *la_int_2);
void					do_la_add_int(int *la_int_1, int a);
int						do_rla_add_la(int *la_int_1, int *la_int_2);
int						*do_la_add_la_tonew(int *la_int_1, int *la_int_2);
int						*do_la_sub_tonewla(int *la_int_1, int *ls_int_2);
void					do_la_div_int(int *la_int, int a);
void					do_rla_div_int(int *la_int, int a);
int						*do_la_div_int_tonew(int *la_int, int a);
void					do_la_mult_int(int *la_int, int a);
int						*do_la_mult_int_tonewla(int *la_int, int a);
void					do_la_mult_la(int *la);
void					do_rla_mult_int(int *la_int, int a);
int						do_la_cmp(int *la_int1, int *la_int2);
int						do_la_round(int *la_int, int q, int *num);
int						*do_la_copy(int *la);

void					do_f_decpart_print(int *la_int, int q);
int						do_g_decpart_print(int *la_int, int q);
void					do_e_shift(int *la, int *num, int m_shift);

int						rounding(int *la, int pos, int *num);
void					fast_power(int *la, int power, int num);

int						t_check__soption(int index, char *soptions,
		size_t part_of_options, t_options *data);
int						t_check_flag_soption(int index, char *soptions,
		size_t part_of_options, t_options *data);
int						t_check_width_soption(int index, char *soptions,
		size_t part_of_options, t_options *data);
int						t_check_prec_soption(int index, char *soptions,
		size_t part_of_options, t_options *data);
int						t_check_size_soption(int index, char *soptions,
		size_t part_of_options, t_options *data);

#endif
