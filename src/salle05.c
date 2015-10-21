#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle05(int salle)
{
  int           action;
  int           b;

  action = 0;
  g_map[2][0].visited = 1;
  g_map[2][0].content = 1;
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
      if (action == 2)
        {
	  my_putstr("\nje traverse un petit couloir etroit. Je commence a avoir sacrementpeur...\n\n");
	      g_map[2][0].content = 0;
	      salle = 6;
	      salle06(salle);
	}
      if (action == 4)
        {
	  my_putstr("\nOn retourne vers le cadavre du sergent, vous etes sur de vouloir vraiment y retourner ? Moi personnelement cela ne me plait pas.");
	  g_map[2][0].content = 0;
	  salle = 8;
	  salle08(salle);
	}
      if (action == 5)
        {
          prendre(salle);
	  action = 0;
        }
      if ((action == 1) || (action == 3))
        {
	  erreur_depla(salle);
	  action = 0;
        }
    }
}
