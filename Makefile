# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 13:16:49 by htomas-d          #+#    #+#              #
#    Updated: 2022/09/16 10:26:38 by htomas-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		= $(wildcard srcs/*.c)

OBJS		= $(SRCS:%.c=%.o)

LIBFTA		= ./libft/libft.a

MLX		= ./mlx/libmlx.a

RM		= rm -f

CC		= gcc #-Wall -Wextra -Werror #-g -fsanitize=address

MLX_FLAGS	= -lXext -lX11 -lm -lz

.c.o:
			@$(CC) -c $< -o $@

all:		$(NAME)

$(NAME): 	 $(MLX) $(LIBFTA) $(OBJS)
			$(CC) $(OBJS) $(MLX) $(LIBFTA) $(MLX_FLAGS) -o $(NAME)
			@echo "$(GREEN)Successfully built --> $(YELLOW)$(NAME)$(DEFAULT)"

$(MLX):
			@make -C mlx

$(LIBFTA):
			@make -C libft

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make -C libft fclean
			make -C mlx clean
			@echo "$(RED)Files Removed!$(DEFAULT)"

re:			fclean all

god:
			git status
			git add .
			git commit -m "random Makefile commit😋"

.PHONY:		all clean re fclean

#COLORS
GREEN = \033[1;32m
RED = \033[1;31m
DEFAULT = \033[0m
YELLOW = \033[1;33m
