#include "fonctions.h"

void		look(int salle)
{
  if(salle == 0)
    {
      my_putstr("\nCette salle est vide, il n'y a rien a faire...\n\n");
    }

  if(salle == 1)
    {
      my_putstr("\nCette salle est le coeur du labyrinthe. 4 chemins se dessinent devant vous. Vous avez peur.\n\n");
    }
  if(salle == 2)
    {
      my_putstr("\nLa piece empeste la decomposition. Vous decouvrez avec horreur des cadavres nus jonchants le sol a vos pieds.\n\n");
    }
  if(salle == 3)
    {
      my_putstr("\nDes cranes recouvrent l'integralite du mur face a vous.\n");
    }
  if(salle == 4)
    {
      my_putstr("\nLa piece est etroite, et sombre. Vous sentez des toiles d'arraignees vous caresser le visage...\n\n");
    }
  if(salle == 5)
    {
      my_putstr("\nA l'entree de la salle se tient un panneau rustique a moitie lisible.\n");
      my_putstr("Vous y lisez : 'ATT..T..N .VE..U...R LA .OR. E.T .RO.HE'\n\n");
    }
}
  
  
