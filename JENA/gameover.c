#include "fonctions.h"
#include <stdio.h>
void		gameover()
{
  system("cat skull.txt");
  my_putstr("\n\n                       ===========================\n\n");
  my_putstr("                                 GAME OVER\n");
  my_putstr("\n                       ===========================\n\n");
  /* my_putstr("Votre score est de : ");
  my_putnbr(SCORE);
  my_putstr("\n");

  FILE *f = fopen("highscore.txt", "a+");
  if (f == NULL)
    {
      printf("Error opening file!\n");
      exit(1);
    }
  char		*sep;
  
  sep = " : ";
   fprintf(f,"%s", USER);
  fprintf(f, "%s", sep);
  fprintf(f,"%d Pts.\n", SCORE);  
  fclose(f);
  system("cat highscore.txt"); 
*/
}
