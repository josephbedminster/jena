#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle15(int salle)
{
  int           action;

  action = 0;
  g_map[6][0].visited = 1;
  g_map[6][0].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 3)
        {
	  my_putstr("\nJ'espere ne pas avoir oublier de chose dans cette hangard, et puis si je n'arrive rien a");
	  my_putstr(" faire avec mon vaisseaux mere je pourrais peut etre prendre un de ces petits vaisseaux.\n\n");
	  g_map[6][0].content = 0;
	  salle = 14;
          salle14(salle);
        }
      if (action == 4)
        {
	  my_putstr("Vous pensez que ce hangard est grand comment ? car je ne voie pas le fond");
	  g_map[6][0].content = 0;
	  salle = 16;
          salle16(salle);
        }
      /*Prendre*/
      if (action == 5)
        {
          prendre(salle);
          action = 0;
        }
      /*fin prendre*/
      if ((action == 1) || (action == 2))
	{
	  erreur_depla(salle);
	  action = 0;
	}
    }
}