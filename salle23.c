#include "fonctions.h"

extern t_map g_map[10][4];

void            salle23(int salle, t_player *player)
{
  int           action;

  action = 0;
  g_map[5][2].visited = 1;
  g_map[5][2].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if (action == 1)
        {
	  g_map[5][2].content = 0;
	  salle = 13;
	  salle13(salle, player);
	}
      if (action == 4)
        {
	  g_map[5][2].content = 0;
	  salle = 24;
	  salle24(salle, player);
	}

      /*Prendre*/
      if (action == 5)
        {
          prendre(salle, player);
          action = 0;
        }
      /*fin prendre*/
      if ((action >= 2) && (action <= 3))
        {
	  erreur_depla(salle);
	  action = 0;
        }
    }
}
