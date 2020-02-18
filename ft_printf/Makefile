ALL_EX =    do_c_option.c do_p_option.c ft_itoa_base.c ft_printf.c parser.c \
		check_options.c do_f_option.c do_print_utils.c ft_math.c \
		do_s_option.c ft_litoa_base.c do_nprints.c arg_and_opt_lists.c \
		do_b_option.c do_int_option.c do_get_snum.c color.c \
		ft_ulitoa_base.c la_create.c la_sub.c la_mult.c la_div.c \
		do_e_option.c la_round.c la_cmp.c do_iarray.c float_parse.c \
		do_file_option.c rounding.c la_reverse.c la_add.c do_g_option.c \
		do_date_option.c ft_putstrn.c do_f_decimal_print.c la_print.c \
		double_parse.c double_parse_add.c nan_and_inf.c la_count.c \
		la_reverse.c la_copy.c spec_c.c do_oxx_option.c do_toptions.c \
		nan_and_inf_add.c do_e_option_shift.c do_check_soption.c \
		arg_and_opt_lists_add.c ft_printf_add.c do_iarray_sort.c

SRCDIR = srcs/
OBJDIR = objs/

SRCS = $(addprefix $(SRCDIR), $(ALL_EX))

ALL_OBJ = $(ALL_EX:%.c=%.o)

OBJS = $(addprefix $(OBJDIR), $(ALL_OBJ))

NAME = libftprintf.a

INCLUDES = ./includes/ft_printf.h ./libft/includes/libft.h

COMP_LIB = make -C libft/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ./libft/libft.a $(OBJS)
	@/bin/cp ./libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDES)
	@/bin/mkdir -p $(OBJDIR)
	gcc $(FLAGS) -I./includes -I./libft/includes -c $< -o $@

./libft/libft.a: lib

lib:
	@$(COMP_LIB)

clean:
	@/bin/rm -rf $(OBJDIR)
	@$(COMP_LIB) clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@$(COMP_LIB) fclean

re: fclean all

.PHONY: lib clean fclean all re
