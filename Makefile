ALL_C_ASM = asm.c add_args_code.c add_null_octets.c add_str_to_byte_code.c add_cec.c case_of_error.c \
		check_args.c check_name.c convert_labels_to_numbers.c convert_operations_to_byte_code.c \
		create_file.c do_parse.c encrypt_line.c fill_by_zeroes.c get_args.c initialize.c print_func.c \
		read_line.c read_operation.c wrong_end_of_line.c free_struct.c init_operations.c only_spaces.c add_arg.c op.c \
		check_name_and_comment.c getter.c have_end_quote.c put_after_quote.c read_.c

ALL_C_CW = main.c main_wrap.c op.c err_exit.c \
		cw_player.c cw_player_parse.c \
		cw_arena.c cw_carriage_creation.c cw_check_code_inner_cycle.c \
		cw_game.c cw_game_inner_cycle.c cw_bitwise.c \
		cw_commands.c cw_operations_1.c cw_operations_2.c cw_operations_3.c \
		cw_operations_4.c ft_isint.c cw_display.c cw_args.c

SRCDIR_ASM = ./srcs_asm
OBJDIR_ASM = ./objs_asm

SRCDIR_CW = ./srcs_vm
OBJDIR_CW = ./objs_vm

ALL_OBJ_ASM = $(ALL_C_ASM:%.c=%.o)
OBJS_ASM = $(addprefix $(OBJDIR_ASM)/, $(ALL_OBJ_ASM))

ALL_OBJ_CW = $(ALL_C_CW:%.c=%.o)
OBJS_CW = $(addprefix $(OBJDIR_CW)/, $(ALL_OBJ_CW))

NAME_ASM = asm
NAME_CW = corewar

INCLUDES_ASM = ./includes/op.h ./includes/asm.h
INCLUDES_CW = ./includes/op.h ./includes/cw_game.h ./includes/corewar.h

COMP_LIB = make -C ft_printf/libft
COMP_PRINTF = make -C ft_printf

FLAGS = -Wall -Wextra -Werror

all: ./ft_printf/libft/libft.a ./ft_printf/libftprintf.a $(NAME_ASM) $(NAME_CW)

$(NAME_ASM): ./ft_printf/libft/libft.a $(OBJS_ASM)
	gcc $(FLAGS) $(OBJS_ASM) -L./ft_printf/libft -lft -o $@

$(OBJDIR_ASM):
	/bin/mkdir -p $(OBJDIR_ASM)

$(OBJDIR_ASM)/%.o: $(SRCDIR_ASM)/%.c $(INCLUDES_ASM) | $(OBJDIR_ASM)
	gcc $(FLAGS) -I./includes -I./ft_printf/libft/includes -c $< -o $@

$(NAME_CW): ./ft_printf/libft/libft.a ./ft_printf/libftprintf.a $(OBJS_CW)
	gcc $(FLAGS) $(OBJS_CW) -L./ft_printf -lftprintf -L./ft_printf/libft -lft -o $@

$(OBJDIR_CW):
	/bin/mkdir -p $(OBJDIR_CW)

$(OBJDIR_CW)/%.o: $(SRCDIR_CW)/%.c $(INCLUDES_CW) | $(OBJDIR_CW)
	gcc $(FLAGS) -I./includes -I./ft_printf/includes -I./ft_printf/libft/includes -c $< -o $@

./ft_printf/libft/libft.a: lib

lib:
	@$(COMP_LIB)

./ft_printf/libftprintf.a: ft_printf

ft_printf:
	@$(COMP_PRINTF)

clean:
	@/bin/rm -rf $(OBJDIR_ASM) $(OBJDIR_CW)
	@$(COMP_LIB) clean
	@$(COMP_PRINTF) clean

fclean: clean
	@/bin/rm -rf $(NAME_ASM) $(NAME_CW)
	@$(COMP_LIB) fclean
	@$(COMP_PRINTF) fclean

re: fclean all

.PHONY: lib clean fclean all re ft_printf
