#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle13(int salle)
{
  int           action;
  int           randmob;
  int           randmuni;
  int           randmedic;


  action = 0;
  g_map[5][1].visited = 1;
  g_map[5][1].content = 1;
  look(salle);
  srand(time(NULL));
  randmob = rand();
  randmuni = rand();
  randmedic = rand();
  MUNI_MAP = 0;
  MEDIC_MAP = 0;

  if (randmedic%10 == 0)
    {
      MEDIC_MAP = 1;
    }
  if ((randmob%4 == 0) && ((jena.weaponTab[1].available == 1) || (jena.weaponTab[2].available == 1)))
    {
      start_battle();
    }
  if ((randmuni%4 == 0))
    {
      MUNI_MAP = 4;
    }
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 1)
        {
	  my_putstr("\nPitier que je ne trouve pas de cadravre...\n\n");
	  g_map[5][1].content = 0;
	  salle = 14;
          salle14(salle);
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
	      my_putstr("\nEncore une porte verrouilee ! On peut dire que le badge d'acces du sergent m'est utile !\n");
	      my_putstr("S'il etait toujours en un seul morceau, je l'aurai bien remercie...\n\n");
	      g_map[5][1].content = 0;
	      salle = 23;
	      salle23(salle);
	    }
	}
      if (action == 3)
        {
	  my_putstr("\nOn retourne la ou je me suis reveiller, peut etre que un souvenir me reviendra...\n\n");
	  g_map[5][1].content = 0;
	  salle = 12;
	  salle12(salle);
	}
      if (action == 4)
        {
	  my_putstr("\nTout les tuyaux de se vaisseaux se dirige vers ma direction, je pense m'approcher des salles machines.\n\n");
	  g_map[5][1].content = 0;
	  salle = 17;
	  salle17(salle);
	}
      if (action == 5)
        {
          erreur_prendre();
	  action = 0;
	}
    }
}
