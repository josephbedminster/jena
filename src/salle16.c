#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle16(int salle)
{
  int           action;
  int           b;

  action = 0;
  g_map[7][0].visited = 1;
  g_map[7][0].content = 1;
  look(salle);
  srand(time(NULL));
  b = rand();
  if ((b%4 == 0) && ((jena.weaponTab[1].available == 1) || (jena.weaponTab[2].available == 1)))
    {
      start_battle();
    }
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 3)
        {
	  my_putstr("\nEt bien atteindre le fond de se hangard etait long,mais bon j'ai trouver de petit");
	  my_putstr(" chose interessante mais se trou dans la coque m'inquiette.\n\n");
	  g_map[7][0].content = 0;
	  salle = 15;
          salle15(salle);
        }
      /*Prendre*/
      if (action == 5)
        {
          prendre(salle);
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
