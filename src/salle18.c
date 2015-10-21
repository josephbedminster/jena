#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle18(int salle)
{
  int           action;

  action = 0;
  g_map[7][1].visited = 1;
  g_map[7][1].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 3)
        {
	  g_map[7][1].content = 0;
	  salle = 17;
	  salle17(salle);
	}
      if (action == 4)
        {
	  g_map[7][1].content = 0;
	  salle = 19;
	  salle19(salle);
	}
      /*Prendre*/
      if (action == 5)
        {
          prendre(salle);
          action = 0;
        }
      /*fin prendre*/
      if ((action >= 1) && (action <= 2))
        {
	  erreur_depla(salle);
	  action = 0;
        }
    }
}
