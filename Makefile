CC =            gcc
NAME =          jena
SRC =           *.c

CFLAGS =        -W -Wall -Wextra -Werror
OBJ =           $(SRC:%.c=%.o)
RM =            rm -rf

$(NAME) :	$(OBJ)
		$(CC) $(SRC) $(CFLAGS) -o $(NAME)

all:		$(NAME)
clean:
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)
		rm *.c~
		rm  *.h~
re:		fclean
		make