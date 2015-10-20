#include "fonctions.h"

extern t_map g_map[10][4];

void            salle16(int salle, t_player *player)
{
  int           action;

  action = 0;
  g_map[7][0].visited = 1;
  g_map[7][0].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if (action == 3)
        {
	  g_map[7][0].content = 0;
	  salle = 15;                                                   
          salle15(salle, player);                           
        }
      /*Prendre*/
      if (action == 5)
        {
          prendre(salle, player);
          action = 0;
        }
      /*fin prendre*/
      if ((action == 4) || ((action >= 1) && (action <= 2)))
        {
          erreur_depla(salle);
          action = 0;
        }
    }
}
