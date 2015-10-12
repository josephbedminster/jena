#include "fonctions.h"

void            salle01(int salle)
{
  int		action;

  action = 0;

  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 1)
	{
	  my_putstr("\nVous avez pris le passage qui menait a l'ouest. Vous traversez un long couloir.\n");
	  salle = 4;
	  salle04(salle);
	}
      if (action == 2)
	{
	  my_putstr("\nVous poussez une vielle porte en bois, et penetrez dans la salle suivante.\n");
	  salle = 2;
	  salle02(salle);
        }
      if (action == 3)
	{
	  my_putstr("\nPendant que vous marchez vers la salle au nord, des rats dans votre direction.\n ");
	  my_putstr("Effraye, vous vous collez au mur et attendez que tout les rats soient passes.\n");
	  salle = 3;
	  salle03(salle);
        }
      if (action == 4)
	{
	  my_putstr("\nLe couloir que vous traversez est eclaire par quelques torches.\n");
	  salle = 5;
	  salle05(salle);
        }
      if (action == 5)
	{
	  my_putstr("\nFroussard que vous etes, vous decidez de remonter l'echelle.\n");
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
