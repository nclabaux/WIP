# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nclabaux </var/mail/nclabaux>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/01 17:04:15 by nclabaux          #+#    #+#              #
#    Updated: 2020/05/15 17:57:10 by nclabaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRCS = main.c\
       file_reading.c\
       file_reading1.c\
       file_reading2.c\
       list_handling.c\
       distances.c\
       errors.c\
       vectorial_calculus.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

RM = rm -f

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
LIBFLAGS = -lm -lmlx -lXext -lX11 -L./libft -lft

$(NAME): $(OBJS)
	make -C libft/ 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)

all: $(NAME)

clean: 
	make -C libft/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft/ fclean
	$(RM) $(NAME)

re: fclean all

mactest:
	gcc tester.c -lmlx -framework OpenGL -framework AppKit 

linuxtest:
	clang tester.c rgb_to_int.c -lm -lmlx -lXext -lX11 

.PHONY: all clean fclean re

#.SILENT: all clean fclean re $(NAME) $(OBJS) make
