NAME	= arcade

CXX	= g++ -g3

RM	= rm -rf

SRCS	= 	./src/main.cpp \
			./src/GameCore.cpp \
			./src/createObject.cpp \

CPPFLAGS = -I ./include/
CPPFLAGS += -W -Wall -Wextra
CPPFLAGS += -ldl

MAKEFLAGS += --silent

OBJS = $(SRCS:.cpp=.o)

all:  nibbler pacman $(NAME)

$(NAME):	$(OBJS)
	printf "\033[0;33mBuilding Arcade...\033[0m\n"
	$(CXX) -o $(NAME) $(OBJS) $(CPPFLAGS)
	printf "[\033[0;32mArcade built\033[0m]   \t\t\t\t\t\t\t%s\n" $(NAME)

pacman:
	printf "\033[0;33mCompiling Pacman...\033[0m\n"
	make -C games/pacman/

nibbler:
	printf "\033[0;33mCompiling Nibbler...\033[0m\n"
	make -C games/nibbler/

clean:
	$(RM) $(OBJS)
	printf "[\033[0;31mdeleted\033[0m] \t\t\t\t\t\t\t\t%s\n" $(OBJS)
	make clean -C games/pacman/
	make clean -C games/nibbler/

fclean:
	$(RM) $(NAME)
	printf "[\033[0;31mdeleted\033[0m] \t\t\t\t\t\t\t\t%s\n" $(NAME)
	$(RM) $(OBJS)
	printf "[\033[0;31mdeleted\033[0m] \t\t\t\t\t\t\t\t%s\n" $(OBJS)
	make fclean -C games/pacman/
	make fclean -C games/nibbler/

re: fclean all pacman nibbler

.PHONY: all pacman nibbler clean fclean re
