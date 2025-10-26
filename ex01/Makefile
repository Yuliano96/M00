# ...existing code...
CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98

NAME = phoneBook
SRC = Contact.cpp PhoneBook.cpp main.cpp tools.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
# ...existing code...