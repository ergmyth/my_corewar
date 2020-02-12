ALL_C = asm.c add_args_code.c add_null_octets.c add_str_to_byte_code.c add_cec.c case_of_error.c \
		check_args.c check_name.c convert_labels_to_numbers.c convert_operations_to_byte_code.c \
		create_file.c do_parse.c encrypt_line.c fill_by_zeroes.c get_args.c initialize.c print_func.c \
		read_line.c read_operation.c wrong_end_of_line.c free_struct.c init_operations.c only_spaces.c add_arg.c op.c

SRCDIR = ./srcs
OBJDIR = ./objs

ALL_OBJ = $(ALL_C:%.c=%.o)

OBJS = $(addprefix $(OBJDIR)/, $(ALL_OBJ))

NAME = asm

INCLUDES = ./includes/op.h ./includes/asm.h

COMP_LIB = make -C libft

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ./libft/libft.a $(OBJS)
	gcc $(FLAGS) $(OBJS) -L./libft -lft -o $@

$(OBJDIR):
	/bin/mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES) | $(OBJDIR)
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
