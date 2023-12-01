NAME := animal
CC := c++
FLAGS := -std=c++98 -Wall -Wextra -Werror
SRC :=  Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
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