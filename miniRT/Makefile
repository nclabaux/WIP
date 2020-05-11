# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nclabaux </var/mail/nclabaux>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/01 17:04:15 by nclabaux          #+#    #+#              #
#    Updated: 2020/05/11 15:08:01 by nclabaux         ###   ########.fr        #
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

CFLAGS = 

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft.a

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

libft: 
	make -C libft/

mactest:
	gcc tester.c -lmlx -framework OpenGL -framework AppKit 

linuxtest:
	clang tester.c rgb_to_int.c -lm -lmlx -lXext -lX11 

.PHONY: all clean fclean re
