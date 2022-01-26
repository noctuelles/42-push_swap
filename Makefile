# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 16:37:49 by plouvel           #+#    #+#              #
#    Updated: 2022/01/26 16:42:24 by plouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	=	srcs

INC_DIR		=	includes

OBJS_DIR	=	objs

LIBFT_DIR	=	libft

SRCS		=	main.c		\
				parsing.c	\
				stack.c

OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

NAME		=	push_swap

RM			=	rm -rf

CC			=	cc

CFLAGS		=	-I $(INC_DIR) -I $(LIBFT_DIR) \
				-Wall -Werror -Wextra

CLIBS		=	-L . -lft

$(NAME):

all:

clean:

fclean:

re:

.PHONY:			all clean fclean re
