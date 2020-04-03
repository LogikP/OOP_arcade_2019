##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## arcade
##

NAME	=	../lib_arcade_sfml.so

CXX	=	g++ -g3 -fPIC

RM	=	rm -vf

SRCS	= 	./src/lib_sfml.cpp \
			./src/bind.cpp \
			./src/menu.cpp \

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/
CPPFLAGS += -W -Wall -Wextra
LSFML	+= -lsfml-system -lsfml-graphics -lsfml-window

all: $(NAME)

$(NAME): $(OBJS)
	printf "\033[1;34mCompiling SFML...\033[0m\n"
	$(CXX) -shared $(OBJS) -o $(NAME) $(LDFLAGS) $(LSFML)
	printf "[\033[1;32mSFML library built\033[0m]   \t\t\t\t\t\t\t%s\n" $(NAME)

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
