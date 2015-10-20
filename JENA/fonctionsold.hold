#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_player
{
  char          *name;
  int           lvl;
  int           pv;
  int           pvmax;
  int           pm;
  int           pmmax;
}		t_player;

void            salle01(int salle, t_player *player);
void            salle02(int salle, t_player *player);
void            salle03(int salle, t_player *player);
void            salle04(int salle, t_player *player);
void            salle05(int salle, t_player *player);
void            spawn(int salle, t_player *player);
int             comparer(char* entree, int salle, t_player *player);
void            erreur_depla(int salle);
int     	my_putstr(char *str);
void            my_putchar(char c);
char            *readLine();
int             readline(int salle, t_player *player);
int 	    	my_strcmp(char *s1, char *s2);
char		*my_strcpy(char *dest, char *src);
void            suspens();
void            accueil(t_player *player);
void            help();
void            gameover();
