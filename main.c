#include "fonctions.h"

int		main()
{
  int		salle;
  t_player	*player;

  salle = 12;
  player = malloc(sizeof(t_player*));
  init_globales(player);
  accueil(player);
  salle12(salle, player);
  return (0);
}
