CC =            gcc
NAME =          jena
SRC =           *.c

CFLAGS =        -W -Wall -Wextra -Werror
OBJ =           $(SRC:%.c=%.o)
RM =            rm -rf
CREATE_README = echo "\n===================" >> README.txt
		date >> README.txt
		echo "\n===================" >> README.txt
		echo "Nombre de lignes : " >> README.txt
		cat *.c *.h *.txt | wc -l >> README.tx
		echo "Nombre de caracteres : " >> README.txt
		cat *.c *.h *.txt | wc -c >> README.txt

$(NAME) :	$(OBJ)
		$(CC) $(SRC) $(CFLAGS) -o $(NAME)
		$(CREATE_README)
all:		$(NAME)
clean:
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)
re:		fclean
		make