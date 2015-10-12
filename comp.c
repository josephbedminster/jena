int             comp(char *entree)
{
  int           resultat;

  resultat = 0;
  resultat = my_strcmp(entree, "look");
  if (resultat == 0)
    return (1);

  resultat = my_strcmp(entree, "gauche");
  if (resultat == 0)
    return (2);

  resultat = my_strcmp(entree, "droite");
  if (resultat == 0)
    return (3);

  resultat = my_strcmp(entree, "haut");
  if (resultat == 0)
    return (4);

  resultat = my_strcmp(entree, "bas");
  if (resultat == 0)
    return (5);

  resultat = my_strcmp(entree, "take");
  if (resultat == 0)
    return (6);

  resultat = my_strcmp(entree, "help");
  if (resultat == 0)
    return (7);

  return (0);
}
