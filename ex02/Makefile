NAME = claptrap

SRC = main.cpp \
	ClapTrap.cpp \
	ScavTrap.cpp \
	FragTrap.cpp \

OBJ = $(SRC:.cpp=.o)

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	/bin/rm -rf $(OBJ)

fclean : clean
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re