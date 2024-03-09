NAME = Phonebook

CC = clang++

CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp contact.cpp phonebook.cpp

OBJ = $(SRC:.cpp=.o)

HEAD = contact.hpp phonebook.hpp
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