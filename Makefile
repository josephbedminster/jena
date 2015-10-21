CC =            gcc
NAME =          jena
SRC =           *.c

CFLAGS =        -W -Wall -Wextra -Werror
OBJ =           $(SRC:%.c=%.o)
RM =            rm -rf

$(NAME) :	$(OBJ)
		bash create_readme.sh
		$(CC) $(SRC) $(CFLAGS) -o $(NAME)

all:		$(NAME)
clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean
		make