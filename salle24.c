#include "fonctions.h"

extern t_map g_map[10][4];

void            salle24(int salle, t_player *player)
{
  int           action;
  char		*entree;

  entree = malloc(sizeof(char*));
  action = 0;
  g_map[6][2].visited = 1;
  g_map[6][2].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/

      /*Prendre*/
      if (action == 5)
        {
          prendre(salle, player);
          action = 0;
        }
      /*fin prendre*/

      if (action == 3)
        {
	  my_putstr("\nj'ai besoin de retourner en arriere, vous vous souvenez la ou je pouvais marcher sur du sol et non des cartons !\n\n ");
	  g_map[6][2].content = 0;
	  salle = 23;
          salle23(salle, player);
        }
      if ((action == 4) || ((action >= 1) && (action <= 2)))
        {
          erreur_depla(salle);
          action = 0;
        }
    }
}
