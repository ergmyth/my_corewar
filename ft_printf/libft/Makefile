# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifran <ifran@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:14:58 by eleonard          #+#    #+#              #
#    Updated: 2020/02/18 20:09:37 by eleonard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =           ft_atoi.c 			ft_bzero.c 			ft_strchr.c \
         	    ft_check_overlap.c	ft_isalnum.c		ft_isalpha.c \
         		ft_isascii.c 		ft_isdigit.c		ft_isprint.c \
         		ft_memalloc.c		ft_memccpy.c		ft_memchr.c \
         		ft_memcmp.c			ft_memcpy.c			ft_memdel.c \
         		ft_memmove.c		ft_memset.c			ft_putchar.c \
         		ft_putendl.c		ft_putnbr.c			ft_putstr.c \
         		ft_strcat.c			ft_strclr.c			ft_strcmp.c \
         		ft_strcpy.c			ft_strdel.c			ft_strdup.c \
         		ft_strequ.c			ft_striter.c		ft_striteri.c \
         		ft_strjoin.c		ft_strlcat.c		ft_strlen.c \
         		ft_strmap.c			ft_strmapi.c		ft_strncat.c \
         		ft_strncmp.c		ft_strncpy.c		ft_strnequ.c \
         		ft_strnew.c			ft_strsplit.c		ft_strstr.c \
         		ft_strsub.c			ft_strtrim.c		ft_tolower.c \
         		ft_toupper.c		ft_strrchr.c		ft_strnstr.c \
				ft_itoa.c			ft_lstnew.c			ft_lstadd.c \
				ft_lstdelone.c		ft_lstdel.c			ft_lstiter.c \
				ft_lstmap.c			ft_lstaddtoend.c	ft_putchar_fd.c \
				ft_putstr_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c \
				ft_sqrt.c			ft_freep.c			index_of.c\
				ft_abs.c            get_next_line.c     index_of.c \
				pf_hex.c            btoh.c 				ft_recursive_power.c \
				btoi.c              ft_itob.c           only_numbers.c \
                ft_htod.c			ft_rev_binary.c		is_space.c \
                div_mod.c			ft_strqchr.c		ft_power.c \
				ft_sqrt.c			last_index_of.c

NAME	= libft.a

FLAGS	= -Wall -Wextra -Werror

INCLUDES = ./includes/libft.h

SRCDIR	= srcs/
OBJDIR	= objs/

SRCS	= $(addprefix $(SRCDIR), $(SRC))
ALL_OBJ	= $(SRC:%.c=%.o)
OBJS	= $(addprefix $(OBJDIR), $(ALL_OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDES)
	@/bin/mkdir -p $(OBJDIR)
	gcc $(FLAGS) -I./includes -c $< -o $@

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
