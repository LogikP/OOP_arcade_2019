NAME	=	../lib_arcade_ncurses.so

CXX	=	g++ -g3 -lncurses -fPIC -Iinclude

RM	=	rm -vf

SRCS	= 	./src/lib_ncurses.cpp \
			./src/MyWindow.cpp \

OBJS	=	$(SRCS:.cpp=.o)

LNCURSE	+=	-lncurses

CPPFLAGS +=	-W -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJS)
	printf "\033[1;34mCompiling Ncurses...\033[0m\n"
	$(CXX) -shared $(OBJS) -o $(NAME) $(LNCURSES)
	printf "[\033[1;32mNcurses library built\033[0m]   \t\t\t\t\t\t%s\n" lib_arcade_ncurses.so

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
