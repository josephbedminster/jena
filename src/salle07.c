#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle07(int salle)
{
  int           action;
  int           b;
  action = 0;
  g_map[2][2].visited = 1;
  g_map[2][2].content = 1;
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
      if (action == 1)
        {
	  my_putstr("\nApres une bonne sieste, je peux aller ou vous voulez.\n\n");
	  g_map[2][2].content = 0;
	  salle = 6;
	  salle06(salle);
	}
      if (action == 4)
        {
	  my_putstr("\nLe temps defile et pourtant je me promene dans se vaiseau encore et toujour,et pourquoi ne pas dormir ?\n\n");
	  g_map[2][2].content = 0;
	  salle = 10;
	  salle10(salle);
	}
      if (action == 5)
        {
          prendre(salle);
	  action = 0;
        }
      if ((action >= 2) && (action <= 3))
        {
	  erreur_depla(salle);
	  action = 0;
        }
    }
}
