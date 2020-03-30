NAME	= arcade

CXX	= g++ -g3

RM	= rm -rf

SRCS	= 	./src/main.cpp \
			./src/createObject.cpp \
			./src/GameCore.cpp \

CPPFLAGS = -I ./include/
CPPFLAGS += -W -Wall -Wextra
CPPFLAGS += -ldl

MAKEFLAGS += --silent

OBJS = $(SRCS:.cpp=.o)



all:  nibbler pacman sfml caca ncurses core
$(NAME):	$(OBJS)
	printf "\033[0;33mBuilding Arcade...\033[0m\n"
	$(CXX) -o $(NAME) $(OBJS) $(CPPFLAGS)
	printf "[\033[0;32mArcade built\033[0m]   \t\t\t\t\t\t\t%s\n" $(NAME)

core : $(NAME)

sfml:
	printf "\033[0;33mCompiling SFML...\033[0m\n"
	make -C lib/SFML/

caca:
	printf "\033[0;33mCompiling CACA...\033[0m\n"
	make -C lib/CACA/

ncurses:
	printf "\033[0;33mCompiling NCURSES...\033[0m\n"
	make -C lib/NCURSES/

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
	make clean -C lib/SFML/
	make clean -C lib/NCURSES/
	make clean -C lib/CACA/

fclean:
	$(RM) $(NAME)
	printf "[\033[0;31mdeleted\033[0m] \t\t\t\t\t\t\t\t%s\n" $(NAME)
	$(RM) $(OBJS)
	printf "[\033[0;31mdeleted\033[0m] \t\t\t\t\t\t\t\t%s\n" $(OBJS)
	make fclean -C games/pacman/
	make fclean -C games/nibbler/
	make fclean -C lib/SFML/
	make fclean -C lib/NCURSES/
	make fclean -C lib/CACA/

re: fclean all pacman nibbler sfml caca ncurses

.PHONY: all pacman nibbler sfml caca ncurses clean fclean re