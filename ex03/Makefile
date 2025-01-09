NAME = claptrap

SRC = main.cpp \
	ClapTrap.cpp \
	ScavTrap.cpp \
	FragTrap.cpp \
	DiamondTrap.cpp \

OBJ = $(SRC:.cpp=.o)

CC = c++
# -Wshadow -- warns about local variables or type declarations that
#       	shadow other variables, parameters, types, class members
# -Wno-shadow --  disable this warning globally or for specific parts
#			of the code. For instance, to suppress the warning in cases
#			where shadowing is intentional and not a mistake.
FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	/bin/rm -rf $(OBJ)

fclean : clean
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re