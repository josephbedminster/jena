#include "fonctions.h"

void		score()
{
  my_putstr("Votre score est de : ");
  my_putnbr(SCORE);
  my_putstr("\n");

 FILE *f = fopen("src/highscore.txt", "a+");
 if (f == NULL)
   {
     fprintf(stderr, "Error opening file!\n");
     exit(1);
   }

 fprintf(f,"%s : %d Pts.\n", USER, SCORE);
 fclose(f);
 system("cat src/highscore.txt");
 exit(0);
}
