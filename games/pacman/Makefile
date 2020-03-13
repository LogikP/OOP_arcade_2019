##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

NAME	=	lib_arcade_pacman.so

CXX	=	g++ -g3 -fPIC -Iinclude -rdynamic

RM	=	rm -vf

SRCS	= src/pacman.cpp \

OBJS	=	$(SRCS:.cpp=.o)

CPPFLAGS +=	-W -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJS)
	printf "\033[1;34mCompiling Pacman...\033[0m\n"
	$(CXX) -shared $(OBJS) -o $(NAME)
	printf "[\033[1;32mPacman library built\033[0m]   \t\t\t\t\t\t%s\n" lib_arcade_pacman.so

clean:
	printf "\033[1;31m[deleting]\033[0;35m\n"
	$(RM) $(OBJS)
	printf "\033[0m"

fclean: clean
	printf "\033[1;31m[deleting]\033[0;35m\n"
	$(RM) $(NAME)
	printf "\033[0m"

re: fclean all

.PHONY: all clean fclean re
