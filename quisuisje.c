#include "fonctions.h"

void		quisuisje(t_player *player)
{
  my_putstr("\nVous etes ");
  my_putstr(player->name);
  my_putstr(", un aventurier peureux.\n");
  my_putstr("Vous etes seul dans un labyrinthe effrayant... Bon courage !\n\n");
}
