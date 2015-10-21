#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle12(int salle)
{
  int           action;

  action = 0;
  g_map[4][1].visited = 1;
  g_map[4][1].content = 1;
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
      if (action == 3)
        {
	  if (DIAG_S12A09 == 0)
	    {
	      my_putstr("\nJ'arrive dans une grande salle. Oh mon dieu, il y a des hommes au sol...\n");
	      //sleep(3);
	      my_putstr("J'en compte quatre. Il y a du sang partout, il s'en sont moins bien sorti que moi...\n");
	      //sleep(3);
	      my_putstr("J'ai pris leurs pouls, tous morts.\n");
	      //sleep(7);
	      my_putstr("Je ne peux rien faire pour eux, continuons.\n");
	      DIAG_S12A09 = 1;
	    }
	  else
	    {
	      my_putstr("OK, je me dirige vers la salle suivante.\n");
	    }
	  g_map[4][1].content = 0;
	  salle = 9;
	  salle09(salle);
	}
      if (action == 4)
        {
	  my_putstr("Je traverse un long couloir... Tout est silencieux ici, pas tres rassurant...\n");
	  my_putstr("Je suis arrive dans une grande salle.");
	  g_map[4][1].content = 0;
	  salle = 13;
	  salle13(salle);
	}
      if (action == 5)
        {
          prendre(salle);
          action = 0;
        }
      if ((action >= 1) && (action <= 2))
        {
	  erreur_depla(salle);
	  action = 0;
        }
    }
}
