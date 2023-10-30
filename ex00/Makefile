NAME = megaphone

FLAGS =  -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

%.o : %.cpp
	@c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@c++ $(FLAGS) $(OBJ) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
