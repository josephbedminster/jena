#include "fonctions.h"

void            salle04(int salle)
{
  int           action;

  action = 0;

  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 1)
        {
          my_putstr("salle 04");
          salle = 4;
          salle04(salle);
        }
      if (action == 2)
        {
          my_putstr("salle 02");
          // salle02(salle);                                                    
        }
      if (action == 3)
        {
          my_putstr("salle 03");
          // salle03(salle);                                                    
        }
      if (action == 4)
        {
          my_putstr("salle 05");
          // salle05(salle);                                                    
        }
      if (action == 5)
        {
          my_putstr("Froussard que vous etes, vous decidez de remonter l'echell\
e.\n");
          salle = 0;
          spawn(salle);
        }
      if (action == 6)
        {
          erreur_depla(salle);
          action = 0;
        }
    }
}
