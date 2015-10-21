#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle14(int salle)
{
  int           action;

  action = 0;
  g_map[5][0].visited = 1;
  g_map[5][0].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 2)
        {
	  my_putstr("\nCe hangard ne m'inspire vraiment pas,je prefere faire demi-tour.\n\n");
	  g_map[5][0].content = 0;
	  salle = 13;
          salle13(salle);
        }
      if (action == 4)
        {
	  if (COMBI == 0)
	    {
	      my_putstr("J'entre dans le hangar !\nIl y a un enorme trou dans la coque !\n");
	      my_putstr("Je me sens mal !...\n");
	      sleep(3);
	      my_putstr("Je...\n");
	      score();
	      gameover();
	    }
	  else
	    {
	      my_putstr("\nPfiou!!! Heureusement que j'ai ma combinaison sinon je ne pense pas survivre.\n\n");
	      g_map[5][0].content = 0;
	      salle = 15;
	      salle15(salle);
	    }
	}
      /*Prendre*/
      if (action == 5)
        {
          prendre(salle);
          action = 0;
        }
      /*fin prendre*/
      if ((action == 1) || (action == 3))
	{
	  erreur_depla(salle);
	  action = 0;
	}
    }
}
