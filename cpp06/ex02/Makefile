# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 18:10:56 by agunczer          #+#    #+#              #
#    Updated: 2022/04/09 21:17:48 by agunczer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify

CC = clang++

# CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRC = Base.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

HEAD = Base.hpp A.hpp B.hpp C.hpp
all : $(NAME)

$(NAME) : $(SRC) $(HEAD)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(OBJ)
	rm -rf  $(NAME)

re :
	make fclean
	make $(NAME)