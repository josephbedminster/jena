#include "fonctions.h"
extern t_player jena;

int             readline()
{
  char          *entree;
  int           result;

  result = 0;
  while (result == 0)
    {
      /*GESTION DU URANDOM*/
      if (ERREUR_PROMPT == 50)
	{
	  my_putstr("\nVous ne m'etes plus d'aucune aide ! Je me debrouillerai seule !\n\n");
	  gameover();
	  exit(0);
	}
      /*FIN*/
      ERREUR_PROMPT = ERREUR_PROMPT + 1;
      my_putstr("   Que dois-je faire : ");
      entree = readLine();
      result = comparer(entree);
    }
  ERREUR_PROMPT = 0;
  return (result);
}

char             *readline_prendre()
{
  char          *entree;
  my_putstr("\n       Que dois-je prendre ? > ");
  entree = readLine();
  return (entree);
}

char             *readline_utiliser()
{
  char          *entree;
  if (SALLE == 1)
    {
      my_putstr("Je peux aussi utiliser la <console> du vaisseau\n");
      my_putstr("\n       Que dois-je utiliser ? > ");
      entree = readLine();
      return (entree);
    }
  else
    {
      if (jena.medicaments >= 1)
	{
	  printf("\nJ'ai : - %d medicaments\n", jena.medicaments);
	}
      my_putstr("\n       Que dois-je utiliser ? > ");
      entree = readLine();
      return (entree);
    }
}

char             *readLine_code()
{
  char          *entree;
  my_putstr("\n       CODE > ");
  entree = readLine();
  return (entree);
}

char             *readline_console()
{
  char          *entree;
  my_putstr("\n   > ");
  entree = readLine();
  return (entree);
}
