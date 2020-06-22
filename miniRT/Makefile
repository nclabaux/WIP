# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 18:28:50 by nclabaux          #+#    #+#              #
#    Updated: 2020/06/22 12:12:33 by nclabaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRCS =	calculus.c\
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
	set_data.c\
	vectorial_calculus.c\
	vectorial_calculus1.c\
	verification.c\
	verification1.c

A = 	\
    	main.c\
	loop.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

RM = rm -f

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

LIBFLAGS = -L./minilibx-linux -lm -lmlx -lXext -lX11 -L./libft -lft

$(NAME): $(OBJS) libraries
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) main.c $(LIBFLAGS)

all: $(NAME)

clean: 
	make -C minilibx-linux/ clean
	make -C libft/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft/ fclean
	$(RM) $(NAME)

re: fclean all

mactest:
	gcc tester.c -lmlx -framework OpenGL -framework AppKit 

linuxtest:
	make -C libft/ 
	clang tester.c f_main.c $(SRCS) $(LIBFLAGS) 

libraries:
	make -C minilibx-linux/
	make -C libft/

.PHONY: all clean fclean re

#.SILENT: all clean fclean re $(NAME) $(OBJS) make
