# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 16:37:49 by plouvel           #+#    #+#              #
#    Updated: 2022/02/11 19:57:36 by plouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	=	srcs

INC_DIR		=	includes

OBJS_DIR	=	objs

LIBFT_DIR	=	libft

SRCS		=	program/main.c						\
				program/parsing.c					\
				program/stack.c						\
				program/debug_tools.c				\
				program/instructions.c				\
				program/sort/sort_helper.c			\
				program/sort/sort_utils.c			\
				program/sort/sort_init.c			\
				program/sort/sort_algorithm.c		\
				program/sort/move_element.c			\
				program/operations/rotate.c			\
				program/operations/reverse_rotate.c	\
				program/operations/push.c			\
				program/operations/swap.c

SRCS_CHECKER=	checker/main.c						\
				program/parsing.c					\
				program/stack.c						\
				checker/operations/rotate.c			\
				checker/operations/reverse_rotate.c	\
				checker/operations/push.c			\
				checker/operations/swap.c

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

OBJS_CHECKER=	$(addprefix $(OBJS_DIR)/, $(SRCS_CHECKER:.c=.o))

NAME		=	push_swap

NAME_CHECKER=	checker

RM			=	rm -rf

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR)

CLIBS		=	-L . -lft

LIBFT		=	libft.a

$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $(OBJS) $(CFLAGS) $(CLIBS) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR) all
				mv $(LIBFT_DIR)/$(LIBFT) .
				$(MAKE) -C $(LIBFT_DIR) fclean

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(LIBFT)
				$(RM) $(NAME)
				$(RM) $(NAME_CHECKER)

re:				fclean all

checker:		$(LIBFT) $(OBJS_CHECKER)
				$(CC) $(OBJS_CHECKER) $(CFLAGS) $(CLIBS) -o $(NAME_CHECKER)

bonus:			checker

.PHONY:			all clean fclean re bonus
