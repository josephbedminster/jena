#include "fonctions.h"

extern t_map g_map[10][4];

void            salle17(int salle, t_player *player)
{
  int           action;

  action = 0;
  g_map[6][1].visited = 1;
  g_map[6][1].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if (action == 3)
        {
	  g_map[6][1].content = 0;
	  salle = 13;                                                   
          salle13(salle, player);                           
        }
      if (action == 4)
        {
	  if (CARTE_COM == 0)
	    {
	      my_putstr("\nVous n'avez pas la carte d'acces\n");
	      action = 0;
	    }
	  else
	    {
	      g_map[6][1].content = 0;
	      salle = 18;
	      salle18(salle, player);                                                     
	    }
	}
      /*Prendre*/
      if (action == 5)
        {
          prendre(salle, player);
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
