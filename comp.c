#include "fonctions.h"

int             comparer(char* entree, int salle, t_player *player)
{
  int           resultat;

  resultat = 0;
  resultat = my_strcmp(entree, "regarder");
  if (resultat == 0)
    {
      look(salle);
      return (0);
    }

  resultat = my_strcmp(entree, "ouest");
  if (resultat == 0)
    return (1);

  resultat = my_strcmp(entree, "est");
  if (resultat == 0)
    return (2);

  resultat = my_strcmp(entree, "nord");
  if (resultat == 0)
    return (3);

  resultat = my_strcmp(entree, "sud");
  if (resultat == 0)
    return (4);

  resultat = my_strcmp(entree, "monter");
  if (resultat == 0)
    return (5);

  resultat = my_strcmp(entree, "descendre");
  if (resultat == 0)
    return (6);

  resultat = my_strcmp(entree, "aide");
  if (resultat == 0)
    {
      help();
      return (0);
    }

  resultat = my_strcmp(entree, "qui suis-je ?");
  if (resultat == 0)
    {
      quisuisje(player);
      return (0);
    }

  return (0);
}
