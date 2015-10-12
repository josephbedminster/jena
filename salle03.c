#include "fonctions.h"

void            salle03(int salle)
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
	  //salle = 12;
          //salle12(salle);
        }
      if (action == 2)
        {
	  my_putstr("\nApres 5 minute de marche, vous atteignez la salle suivante\n");
	  //salle = 6;
	  //salle06(salle);
	}
      if ((action == 3) || ((action >= 5) && (action <= 6)))
        {
          erreur_depla(salle);
	  action = 0;
	}
      if (action == 4)
        {
	  my_putstr("\nVous retournez dans la salle principale\n");
          salle = 1;
	  salle01(salle);                                                 
        }
      
    }
}
