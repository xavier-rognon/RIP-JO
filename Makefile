##
## EPITECH PROJECT, 2024
## RIP-JO
## File description:
## Makefile
##

SRC			=	$(shell find . -name "*.cpp" -type f)

OBJ			=	$(SRC:.cpp=.o)

NAME		=	RIP-JO

FLAGS		=	-W -Wall -Wextra -g -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

CXXFLAGS 	+=	$(FLAGS)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(FLAGS)

all:		$(NAME)

clean:
	rm -f $(OBJ)

fclean: 	clean
	rm -f $(NAME)

re:    		fclean all
