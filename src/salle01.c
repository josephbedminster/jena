#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle01(int salle)
{
  int		action;

  action = 0;
  g_map[0][1].visited = 1;
  g_map[0][1].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 4)
	{
	  my_putstr("\nJe ne peux rien faire de plus dans le poste de pilotage pour le moment, je reprends ma route.\n\n");
	  g_map[0][1].content = 0;
	  salle = 3;
	  salle03(salle);
        }
      /*Prendre*/
      if (action == 5)
        {
          prendre(salle);
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