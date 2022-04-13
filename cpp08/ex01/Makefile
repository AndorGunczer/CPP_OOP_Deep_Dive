# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 18:10:56 by agunczer          #+#    #+#              #
#    Updated: 2022/04/13 15:37:01 by agunczer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Span.cpp

OBJ = $(SRC:.cpp=.o)

HEAD = Span.hpp
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