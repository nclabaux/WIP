# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 18:28:50 by nclabaux          #+#    #+#              #
#    Updated: 2020/08/02 19:36:21 by nclabaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRCS =	srcs/bmp.c\
	srcs/calculus.c\
	srcs/clear.c\
	srcs/colors.c\
	srcs/distances.c\
	srcs/errors.c\
	srcs/file_reading.c\
	srcs/file_reading1.c\
	srcs/file_reading2.c\
	srcs/file_reading3.c\
	srcs/images.c\
	srcs/light.c\
	srcs/intersection.c\
	srcs/intersection_cy.c\
	srcs/list_handling.c\
	srcs/loop.c\
	srcs/main.c\
	srcs/ray.c\
	srcs/set_data.c\
	srcs/utils.c\
	srcs/vectorial_calculus.c\
	srcs/vectorial_calculus1.c\
	srcs/verification.c\
	srcs/verification1.c

OBJS = $(SRCS:.c=.o)

SAVE_DIR = saves/

CC = gcc 

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LIBFLAGS = -L./minilibx-linux -lm -lmlx -lXext -lX11 -L./libft -lft

$(NAME): $(OBJS)
	make -C minilibx-linux/
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)
	mkdir -p $(SAVE_DIR)

all: $(NAME)

clean: 
	make -C minilibx-linux/ clean
	make -C libft/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft/ fclean
	$(RM) $(NAME) $(SAVE_DIR)

re: fclean all

.PHONY: all clean fclean re
