#include "fonctions.h"

extern t_map g_map[10][4];

void            salle22(int salle, t_player *player)
{
  int           action;

  action = 0;
  g_map[9][2].visited = 1;
  g_map[9][2].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if (action == 1)
        {
	  g_map[9][2].content = 0;
	  salle = 21;
	  salle21(salle, player);
	}
      if (action == 3)
        {
	  g_map[9][2].content = 0;
	  salle = 20;
	  salle20(salle, player);
	}
      /*Prendre*/
      if (action == 5)
        {
          prendre(salle, player);
          action = 0;
        }
      /*fin prendre*/
      if ((action == 2) || (action == 4))
        {
	  erreur_depla(salle);
	  action = 0;
        }
    }
}
