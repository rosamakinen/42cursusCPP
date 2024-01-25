NAME := serialized
CC := c++
FLAGS := -std=c++11 -Wall -Wextra -Werror
SRC := Serializer.cpp main.cpp
OBJ := $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $(FLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all