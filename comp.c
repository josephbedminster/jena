#include "fonctions.h"

int             comparer(char* entree, int salle)
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

  resultat = my_strcmp(entree, "aide");
  if (resultat == 0)
    {
      help();
      return (0);
    }

  resultat = my_strcmp(entree, "qui suis-je ?");
  if (resultat == 0)
    {
      quisuisje();
      return (0);
    }

  resultat = my_strcmp(entree, "carte");
  if (resultat == 0)
    {
      show_map();
      return (0);
    }

  resultat = my_strcmp(entree, "fouiller");
  if (resultat == 0)
    {
      fouiller(salle);
    }

  resultat = my_strcmp(entree, "prendre");
  if (resultat == 0)
    {
      return (5);
    }

  resultat = my_strcmp(entree, "va te pendre");
  if (resultat == 0)
    {
      my_putstr("Me pendre ? Des que j'aurai une corde, avec plaisir !\n");
      my_putstr("En attendant, vouz allez devoir m'aider !\n");
      return (0);
    }

  resultat = my_strcmp(entree, "quitter");
  if (resultat == 0)
    {
      score();
      exit(0);
    }

  resultat = my_strcmp(entree, "kill myself with hands");
  if (resultat == 0)
    {
      my_putstr("Vous vous etes suicide avec vos mains.\n");
      score();
      gameover();
      exit(0);
    }


  return (0);
}
