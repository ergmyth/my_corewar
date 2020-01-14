ASM_C = asm.c
COREWAR_C = corewar.c
ALL_C =     case_of_error.c \


SRCDIR = srcs/
OBJDIR = objs/

ALL_OBJ = $(ALL_C:%.c=%.o)

OBJS = $(addprefix $(OBJDIR), $(ALL_OBJ))
ASM_OBJS = $(addprefix $(OBJDIR), $(ASM_C:%.c=%.o))
COREWAR_OBJS = $(addprefix $(OBJDIR), $(COREWAR_C:%.c=%.o))

NAME_ASM = asm
NAME_COREWAR = corewar

INCLUDES = ./includes/asm.h ./includes/corewar.h

COMP_LIB = make -C libft/

FLAGS = -Wall -Wextra -Werror

all: lib $(NAME_COREWAR) $(NAME_ASM)

$(NAME_ASM): lib $(ASM_OBJS) $(OBJS)
		@gcc $(FLAGS) -o $(NAME_ASM) $(ASM_OBJS) $(OBJS) -L./libft -lft

$(NAME_ASM): lib $(ASM_OBJS) $(OBJS)
		@gcc $(FLAGS) -o $(NAME_ASM) $(ASM_OBJS) $(OBJS) -L./libft -lft

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDES)
		@/bin/mkdir -p $(OBJDIR)
		@gcc $(FLAGS) -I./includes -I./libft/includes -c $< -o $@

lib:
		@$(COMP_LIB)

clean:
	    @/bin/rm -rf $(OBJDIR)
		@$(COMP_LIB) clean

fclean: clean
		@/bin/rm -rf $(NAME_COREWAR) $(NAME_ASM)
		@$(COMP_LIB) fclean

re: fclean all

.PHONY: lib clean fclean all re
