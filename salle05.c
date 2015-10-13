#include "fonctions.h"

void            salle05(int salle, t_player *player)
{
  int           action;

  action = 0;

  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if (action == 4)
        {
          my_putstr("\nVous avancez vers le fond de la salle...\n");
	  suspens();
	  my_putstr("\nVous glissez, et tombez dans une fosse remplies de piques !\n");
	  suspens();
	  my_putstr("\nAgonisant, vous comprenez trop tard la signification du panneau...\n\n (ATTENTION AVENTURIER LA MORT EST PROCHE)\n\n");
	  sleep(4);
	  gameover();
        }
      if (action == 3)
        {
	  my_putstr("\nVous decidez de rebrousser chemin et retournez dans la salle precedante.\n");
          salle = 1;
	  salle01(salle, player);
	}
      if ((action == 1) || (action == 2) || (action == 5) || (action == 6))
        {
	  erreur_depla(salle);
	  action = 0;
        }
    }
}
