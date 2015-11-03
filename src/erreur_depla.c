#include "fonctions.h"

void		erreur_depla(int salle)
{
  /*variable qui sert a rien mais oblige sinon unused variable et la flemme de modif toutes les salles*/
  salle = salle + 1;
  salle = salle - 1;
  my_putstr("\nJe ne peux pas aller par la !\n\n");
}
