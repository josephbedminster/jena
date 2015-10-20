#include "fonctions.h"

extern t_map g_map[10][4];

void            salle11(int salle, t_player *player)
{
  int           action;
  char		*entree;

  entree = malloc(sizeof(char*));
  action = 0;
  g_map[4][0].visited = 1;
  g_map[4][0].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if (action == 3)
        {
	  my_putstr("\nJe pense tout avoir pris dans la reserve, alons-y !");
	  g_map[4][0].content = 0;
	  salle = 8;                                                   
          salle08(salle, player);                           
        }

      /*Prendre*/
      if (action == 5)
        {
          prendre(salle, player);
          action = 0;
        }
      /*fin prendre*/

      if ((action == 1) || (action == 2) || (action == 4))
	{
	  erreur_depla(salle);
	  action = 0;
	}
    }
}
