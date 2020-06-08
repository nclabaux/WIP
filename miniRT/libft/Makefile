# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/02 16:55:41 by nclabaux          #+#    #+#              #
#    Updated: 2020/06/08 14:04:05 by nclabaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_printf/character.c\
		ft_printf/ft_begin_rd.c\
		ft_printf/ft_printf.c\
		ft_printf/hex.c\
		ft_printf/integer.c\
		ft_printf/percent.c\
		ft_printf/pointeur.c\
		ft_printf/string.c\
		ft_printf/unsigned_integer.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		libft/ft_memset.c\
		libft/ft_bzero.c\
		libft/ft_memcpy.c\
		libft/ft_memccpy.c\
		libft/ft_memmove.c\
		libft/ft_memchr.c\
		libft/ft_memcmp.c\
		libft/ft_strlen.c\
		libft/ft_isalpha.c\
		libft/ft_isdigit.c\
		libft/ft_isalnum.c\
		libft/ft_isascii.c\
		libft/ft_isprint.c\
		libft/ft_isspace.c\
		libft/ft_toupper.c\
		libft/ft_tolower.c\
		libft/ft_strchr.c\
		libft/ft_strrchr.c\
		libft/ft_strncmp.c\
		libft/ft_strlcpy.c\
		libft/ft_strlcat.c\
		libft/ft_strnstr.c\
		libft/ft_atoi.c\
		libft/ft_atod.c\
		libft/ft_calloc.c\
		libft/ft_strdup.c\
		libft/ft_substr.c\
		libft/ft_strjoin.c\
		libft/ft_strtrim.c\
		libft/ft_split.c\
		libft/ft_itoa.c\
		libft/ft_strmapi.c\
		libft/ft_putchar_fd.c\
		libft/ft_putstr_fd.c\
		libft/ft_putendl_fd.c\
		libft/ft_putnbr_fd.c\
		libft/ft_putchar_cpt.c\
		libft/ft_convert_base.c\
		libft/ft_convert_base2.c\
		libft/ft_digit_nbr.c\
		libft/ft_digit_nbr_hex.c\
		libft/ft_min_max.c

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
	
#.SILENT: all clean fclean re $(NAME) $(OBJS)
