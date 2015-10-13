#include "fonctions.h"

void            salle04(int salle, t_player *player)
{
  int           action;

  action = 0;

  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if (action == 1)
        {
	  //	  salle = 14;
          //salle04(salle);
        }
      if (action == 4)
        {
	  //  salle = 16;
	  //salle16(salle);
	}
      if ((action == 3) || ((action >= 5) && (action <= 6)))
        {
          erreur_depla(salle);
	  action = 0;
	}
      if (action == 2)
        {
          salle = 1;
	  salle01(salle, player);                                      
        }
      
    }
}
