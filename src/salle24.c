#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle24(int salle)
{
  int           action;
  char		*entree;

  entree = malloc(sizeof(char*));
  action = 0;
  g_map[6][2].visited = 1;
  g_map[6][2].content = 1;
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

      /*Prendre*/
      if (action == 5)
        {
          prendre(salle);
          action = 0;
        }
      /*fin prendre*/

      if (action == 3)
        {
	  my_putstr("\nj'ai besoin de retourner en arriere, vous vous souvenez la ou je pouvais marcher sur du sol et non des cartons !\n\n ");
	  g_map[6][2].content = 0;
	  salle = 23;
          salle23(salle);
        }
      if ((action == 4) || ((action >= 1) && (action <= 2)))
        {
          erreur_depla(salle);
          action = 0;
        }
    }
}
