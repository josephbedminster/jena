CC =            gcc
NAME =          jena
SRC =           *.c

CFLAGS =        -W -Wall -Wextra -Werror
OBJ =           $(SRC:%.c=%.o)
RM =            rm -rf

$(NAME) :	$(OBJ)
		bash create_readme.sh
		$(CC) $(SRC) $(CFLAGS) -o $(NAME)
		rm "*.o"

all:		$(NAME)
clean:
		$(RM) $(OBJ)
		rm *.o
fclean:		clean
		$(RM) $(NAME)
		bash clean.sh
re:		fclean
		make