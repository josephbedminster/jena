#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle11(int salle)
{
  int           action;
  char          *entree;
  int           randmob;


  entree = malloc(sizeof(char*));
  action = 0;
  g_map[4][0].visited = 1;
  g_map[4][0].content = 1;
  look(salle);
  srand(time(NULL));
  randmob = rand();

  if ((randmob%4 == 0) && ((jena.weaponTab[1].available == 1) || (jena.weaponTab[2].available == 1)))
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
	  my_putstr("\nVous avez raison, quittons vite cette réserve flippante !\n");
	  g_map[4][0].content = 0;
	  salle = 8;
          salle08(salle);
        }

      /*Prendre*/
      if (action == 5)
        {
          prendre(salle);
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
