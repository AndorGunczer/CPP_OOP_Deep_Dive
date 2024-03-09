NAME = Account

CC = clang++

CFLAGS = -Wall -Wextra -Werror

SRC = tests.cpp Account.cpp

OBJ = $(SRC:.cpp=.o)

HEAD = Account.hpp
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