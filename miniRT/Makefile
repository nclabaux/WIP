# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 18:28:50 by nclabaux          #+#    #+#              #
#    Updated: 2020/07/15 18:13:51 by nclabaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRCS =	bmp.c\
	calculus.c\
	colors.c\
	distances.c\
	errors.c\
	file_reading.c\
	file_reading1.c\
	file_reading2.c\
	images.c\
	light.c\
	intersection.c\
	intersection1.c\
	list_handling.c\
	loop.c\
	loop1.c\
    	main.c\
	ray.c\
	set_data.c\
	vectorial_calculus.c\
	vectorial_calculus1.c\
	verification.c\
	verification1.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

RM = rm -f

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

LIBFLAGS = -L./minilibx-linux -lm -lmlx -lXext -lX11 -L./libft -lft

$(NAME): $(OBJS) libraries
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)

all: $(NAME)

clean: 
	make -C minilibx-linux/ clean
	make -C libft/ clean
	$(RM) $(OBJS)

fclean: clean delsaves
	make -C libft/ fclean
	$(RM) $(NAME)

re: fclean all

libraries:
	make -C minilibx-linux/
	make -C libft/

delsaves:
	$(RM) saves/*.bmp

.PHONY: all clean fclean re
