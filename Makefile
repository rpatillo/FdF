#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/18 12:26:33 by rpatillo          #+#    #+#              #
#    Updated: 2015/06/08 11:40:42 by rpatillo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

FLAGS = -Wall -Werror -Wextra
#FLAGS = -Wall -Wextra

CC = gcc
LIB = -framework AppKit -framework OpenGL -L minilibx_macos/ -lmlx -L libft -lft
COMP = -I minilibx_macos/ -I libft/ -I inc/

FILE_SRC = ./src/fdf.c \
		./src/draw.c \
		./src/parse.c \
		./src/calc.c \
		./src/error.c

FILE_OBJ = $(FILE_SRC:.c=.o)

all: $(NAME)

$(NAME): $(FILE_OBJ)
		make -C ./libft
		make -C ./minilibx_macos
		$(CC) -o $(NAME) $(FILE_OBJ) $(FLAGS) $(COMP) $(LIB)
		@clear
		@echo	""
		@echo  	"	******** *******   ********"
		@echo	"	/**///// /**////** /**/////"
		@echo	"	/**      /**    /**/**"
		@echo	"	/******* /**    /**/*******"
		@echo	"	/**////  /**    /**/**////"
		@echo	"	/**      /**    ** /**"
		@echo	"	/**      /*******  /**"
		@echo	"	//       ///////   //			by rpatillo"
		@echo	""
		@echo "		Flags :"$(FLAGS)

clean:
		make -C ./libft/ clean
		make -C ./minilibx_macos/ clean
		rm -Rfv $(FILE_OBJ)
		@clear

fclean: clean
		make -C libft/ fclean
		make -C minilibx_macos/ clean
		rm -Rfv $(NAME) $(FILE_OBJ)
		@clear

re: fclean all

norme: norminette $(SRC) $(INC)

.PHONY:	all clean fclean re