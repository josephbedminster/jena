#include "fonctions.h"

void		score(char *cause)
{
  my_putstr("Votre score est de : ");
  my_putnbr(SCORE);
  my_putstr("\n");
  if (strcmp(cause, "Suicide") == 0)
    {
      my_putstr("Jena est morte par suicide.\n");
      cause = "suicide";
   }
  if (strcmp(cause, "radiations") == 0)
    {
      my_putstr("Jena est morte irradiée.\n");
      cause = "radiations";
   }
  else
    {
      my_putstr("Jena s'est fait massacrer par : ");
      my_putstr(cause);
      my_putstr(".\n");
    }
 FILE *f = fopen("src/highscore.txt", "a+");
 if (f == NULL)
   {
     fprintf(stderr, "Error opening file!\n");
     exit(1);
   }

 fprintf(f,"%s : %d Pts. (Cause la mort : %s)\n", USER, SCORE, cause);
 fclose(f);
 system("cat src/highscore.txt");
 exit(0);
}
