#include "fonctions.h"

int             readline(int salle)
{
  char          *entree;
  int           result;

  result = 0;
  while (result == 0)
    {
      my_putstr("Que dois-je faire : ");
      entree = readLine();
      result = comparer(entree, salle);
    }
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
