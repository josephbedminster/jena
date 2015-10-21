CC =            gcc
NAME =          jena
SRC =           *.c

CFLAGS =        -W -Wall -Wextra -Werror
OBJ =           $(SRC:%.c=%.o)
RM =            rm -rf

$(NAME) :	$(OBJ)
		rm README.txt
		echo "\nPROJET --JENA--\n" >> README.txt
		echo "DEVELOPEMENT OPEN SOURCE" >> README.txt
		echo "ECOLE PREP ETNA ALTERNANCE, FRANCE\n" >> README.txt
		echo "DEVELOPEURS :" >> README.txt
		echo "- ROLLAND THOMAS (ETNA)" >> README.txt
		echo "- BEDMINSTER JOSEPH (ETNA)\n" >> README.txt
		echo "COLLABORATEURS :\n" >> README.txt
		echo "- AZIS WINDA (ETNA)" >> README.txt
		echo "- COLAS GEOFFREY (ETNA)" >> README.txt
		echo "- KAUCH JONATHAN (EPITECH)" >> README.txt
		echo "- FRAYS CHRISTOPHE (EPITECH)\n" >> README.txt
		echo "=============================" >> README.txt
		date >> README.txt
		echo "=============================" >> README.txt
		echo "Nombre de lignes : " >> README.txt
		cat *.c *.h *.txt | wc -l >> README.txt
		echo "Nombre de caracteres : " >> README.txt
		cat *.c *.h *.txt | wc -c >> README.txt
		echo "\n" >> README.txt
		clear
		$(CC) $(SRC) $(CFLAGS) -o $(NAME)
		rm "*.o"

all:		$(NAME)
clean:
		$(RM) $(OBJ)
		rm *.o
fclean:		clean
		$(RM) $(NAME)
re:		fclean
		make