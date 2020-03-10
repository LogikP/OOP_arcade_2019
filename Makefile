NAME	= arcade

CXX	= g++ -g3

RM	= rm -rf

SRCS	= main.cpp \

CPPFLAGS = -I ./include/
CPPFLAGS += -W -Wall -Wextra
CPPFLAGS += -ldl

MAKEFLAGS += --silent

OBJS = $(SRCS:.cpp=.o)

all: pacman nibbler sfml ncurses caca $(NAME)

$(NAME):	$(OBJS)
	printf "\033[0;33mBuilding Arcade...\033[0m\n"
	$(CXX) -o $(NAME) $(OBJS) $(CPPFLAGS)
	printf "[\033[0;32mArcade built\033[0m]   \t\t\t\t\t\t\t%s\n" $(NAME)

pacman:
	printf "\033[0;33mCompiling Pacman...\033[0m\n"
	make -C games/Pacman/

nibbler:
	printf "\033[0;33mCompiling Nibbler...\033[0m\n"
	make -C games/Nibbler/

sfml:
	printf "\033[0;33mCompiling SFML...\033[0m\n"
	make -C lib/lib_sfml/

ncurses:
	printf "\033[0;33mCompiling Ncurses Library...\033[0m\n"
	make -C lib/test_ncurses_mathis/

caca:
	printf "\033[0;33mCompiling Caca Library...\033[0m\n"
	make -C lib/lib_caca/

clean:
	$(RM) $(OBJS)
	printf "[\033[0;31mdeleted\033[0m] \t\t\t\t\t\t\t\t%s\n" $(OBJS)
	make clean -C games/Pacman/
	make clean -C games/Nibbler/
	make clean -C lib/test_ncurses_mathis/
	make clean -C lib/lib_sfml/
	make clean -C lib/lib_SDL/
	make clean -C lib/lib_caca_mathis/

fclean:
	$(RM) $(NAME)
	printf "[\033[0;31mdeleted\033[0m] \t\t\t\t\t\t\t\t%s\n" $(NAME)
	$(RM) $(OBJS)
	printf "[\033[0;31mdeleted\033[0m] \t\t\t\t\t\t\t\t%s\n" $(OBJS)
	make fclean -C games/Pacman/
	make clean -C games/Nibbler/
	make fclean -C lib/test_ncurses_mathis/
	make fclean -C lib/lib_SDL/
	make fclean -C lib/lib_caca/

re: fclean all pacman nibbler sfml ncurses

.PHONY: all pacman nibbler sfml ncurses clean fclean re
