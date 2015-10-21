#include "fonctions.h"

int             readline(int salle)
{
  char          *entree;
  int           result;

  result = 0;
  while (result == 0)
    {
      /*GESTION DU URANDOM*/
      if (ERREUR_PROMPT == 10)
	{
	  my_putstr("\nVous ne m'etes plus d'aucune aide ! Je me debrouillerai seule !\n\n");
	  gameover();
	  exit(0);
	}
      /*FIN*/
      ERREUR_PROMPT = ERREUR_PROMPT + 1;
      my_putstr("Que dois-je faire : ");
      entree = readLine();
      result = comparer(entree, salle);
    }
  ERREUR_PROMPT = 0;
  return (result);
}

char             *readline_prendre()
{
  char          *entree;
  my_putstr("   Que dois-je prendre ? > ");
  entree = readLine();
  return (entree);
}

char             *readLine_code()
{
  char          *entree;
  my_putstr("   ENTREZ VOTRE CODE > ");
  entree = readLine();
  return (entree);
}
