#include "fonctions.h"

extern t_map g_map[10][4];

void            salle13(int salle, t_player *player)
{
  int           action;

  action = 0;
  g_map[5][1].visited = 1;
  g_map[5][1].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if (action == 1)
        {
	  g_map[5][1].content = 0;
	  salle = 14;                                                   
          salle14(salle, player);                           
        }
      if (action == 2)
        {
	  if (CARTE_ACCES == 0)
	    {
	      my_putstr("\nLa porte est fermee.\n\n");
	      action = 0;
	    }
	  else
	    {
	      g_map[5][1].content = 0;
	      salle = 23;
	      salle23(salle, player);
	    }
	}
      if (action == 3)
        {
	  g_map[5][1].content = 0;
	  salle = 12;
	  salle12(salle, player);
	}
      if (action == 4)
        {
	  g_map[5][1].content = 0;
	  salle = 17;
	  salle17(salle, player);
	}
      if (action == 5)
        {
          erreur_prendre();
	  action = 0;
	}
    }
}
