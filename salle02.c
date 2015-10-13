#include "fonctions.h"

void            salle02(int salle, t_player *player)
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
	  my_putstr("\nA la vue des cadavres, vous retournez dans la salle precedante\n"); 
          salle = 1;                                                   
          salle01(salle, player);                           
        }
      if (action == 3)
        {
          //  salle = 6;                                                       
          //salle06(salle);                                                     
        }
      if ((action == 2) || ((action >= 4) && (action <= 6)))
        {
          erreur_depla(salle);
          action = 0;
        }
    }
}
