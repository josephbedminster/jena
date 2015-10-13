#include "fonctions.h"

void		spawn(int salle, t_player *player)
{
  int		action;
  
  action = 0;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if ((action >= 1) && (action <= 5))
	{
	  erreur_depla(salle);
	  action = 0;
	}
      else if (action == 6)
	{
	  my_putstr("\nVous descendez une echelle en bois.");
	  salle = 1;
	  salle01(salle, player);
	}
      else
	/*A RETIRER*/
	my_putstr("Erreur");
 
   }
}
