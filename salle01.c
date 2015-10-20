#include "fonctions.h"

extern t_map g_map[10][4];

void            salle01(int salle, t_player *player)
{
  int		action;

  action = 0;
  g_map[0][1].visited = 1;
  g_map[0][1].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if (action == 4)
	{
	  my_putstr("\nC'est dommage je m'amuser bien dans se poste de pilotage, Vous pensez que l'on y reviendra ?\n\n");
	  g_map[0][1].content = 0;
	  salle = 3;
	  salle03(salle, player);
        }
      /*Prendre*/
      if (action == 5)
        {
          prendre(salle, player);
          action = 0;
        }
      /*fin prendre*/
      if ((action >= 1) && (action <= 3)) 
	{
          erreur_depla(salle);
          action = 0;
        }
    }
}
