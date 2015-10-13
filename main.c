#include "fonctions.h"

int		main()
{

  int		salle;
  t_player	*player;

  salle = 0;
  player = malloc(sizeof(t_player));  
  accueil(player);
  spawn(salle, player);
  return (0);
}
