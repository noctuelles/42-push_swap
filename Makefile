# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 16:37:49 by plouvel           #+#    #+#              #
#    Updated: 2022/02/09 15:38:21 by plouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	=	srcs

INC_DIR		=	includes

OBJS_DIR	=	objs

LIBFT_DIR	=	libft

SRCS		=	main.c						\
				parsing.c					\
				stack.c						\
				debug_tools.c				\
				instructions.c				\
				sort/sort_small.c			\
				operations/rotate.c			\
				operations/reverse_rotate.c	\
				operations/push.c			\
				operations/swap.c

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

NAME		=	push_swap

RM			=	rm -rf

CC			=	cc

CFLAGS		=	-g3 -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR)

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
				#$(RM) $(LIBFT)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
