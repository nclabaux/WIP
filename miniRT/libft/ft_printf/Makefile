# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 23:23:21 by nclabaux          #+#    #+#              #
#    Updated: 2020/02/16 00:00:16 by nclabaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =	character.c\
		ft_begin_rd.c\
		ft_printf.c\
		hex.c\
		integer.c\
		percent.c\
		pointeur.c\
		string.c\
		unsigned_integer.c\
		libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c\
		libft/ft_convert_base.c libft/ft_convert_base2.c libft/ft_digit_nbr.c\
		libft/ft_digit_nbr_hex.c libft/ft_isalnum.c libft/ft_isalpha.c\
		libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c\
		libft/ft_itoa.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c\
		libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c\
		libft/ft_lstlast.c libft/ft_lstmap.c libft/ft_lstnew.c\
		libft/ft_lstsize.c libft/ft_memccpy.c libft/ft_memchr.c\
		libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c\
		libft/ft_memset.c libft/ft_min_max.c libft/ft_putchar_cpt.c\
		libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c\
		libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c\
		libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c\
		libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c\
		libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c\
		libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c\
		libft/ft_toupper.c

OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
