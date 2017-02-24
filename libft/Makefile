#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/19 17:33:39 by rpatillo          #+#    #+#              #
#    Updated: 2015/05/18 16:24:47 by rpatillo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = libft.a

SRC_PATH = ./

OBJ_PATH = ./

INC_PATH = ./inc/

SRC_NAME = 	ft_isdigit.c \
		ft_memcpy.c \
		ft_putendl_fd.c \
		ft_strclr.c \
		ft_striteri.c \
		ft_strncmp.c \
		ft_strstr.c \
		ft_isprint.c \
		ft_memdel.c \
		ft_putnbr.c \
		ft_strcmp.c \
		ft_strjoin.c \
		ft_strncpy.c \
		ft_strsub.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_memmove.c \
		ft_putnbr_fd.c \
		ft_strcpy.c	\
		ft_strlcat.c \
		ft_strnequ.c \
		ft_strtrim.c \
		ft_bzero.c \
		ft_memalloc.c \
		ft_memset.c \
		ft_putstr.c \
		ft_strdel.c	\
		ft_strlen.c	\
		ft_strnew.c	\
		ft_tolower.c \
		ft_isalnum.c \
		ft_memccpy.c \
		ft_putchar.c \
		ft_putstr_fd.c \
		ft_strdup.c \
		ft_strmap.c	\
		ft_strnstr.c \
		ft_toupper.c \
		ft_isalpha.c \
		ft_memchr.c \
		ft_putchar_fd.c	\
		ft_strcat.c	\
		ft_strequ.c	\
		ft_strmapi.c \
		ft_strrchr.c \
		ft_isascii.c \
		ft_memcmp.c	\
		ft_putendl.c \
		ft_strchr.c	\
		ft_striter.c \
		ft_strncat.c \
		ft_strsplit.c \
		ft_mallocat.c \
		get_next_line.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	gcc -Wall -Werror -Wextra -I$(INC_PATH) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all