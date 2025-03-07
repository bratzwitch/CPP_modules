NAME = BrosFight

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJS = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		@echo "Compiling this crap"
		@c++ $(CPPFLAGS) $(OBJS) -o $(NAME)
		@echo "All good you can rest(no)"
clean:
		@echo "Trashcan opened"
		@echo "Putting all your garbage but program"
		$(RM) $(OBJS)
		@echo "Trashcan closed"

fclean:	clean
		@echo "We decided that your program garbage too"
		$(RM) $(NAME)
		@echo "Now trashcan really closed"

re: fclean all

.PHONY: all clean fclean re