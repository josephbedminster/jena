#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle03(int salle)
{
  int           action;
  char  	*entree;
  int           randmuni;
  int           randmedic;
  int		randmob;

  entree = malloc(sizeof(char*));
  action = 0;
  g_map[1][1].visited = 1;
  g_map[1][1].content = 1;
  look(salle);
  srand(time(NULL));
  randmuni = rand();
  randmedic = rand();
  randmob = rand();
  MUNI_MAP = 0;
  MEDIC_MAP = 0;

  if (randmedic%10 == 0)
    {
      MEDIC_MAP = 1;
    }
  if ((randmuni%4 == 0))
    {
      MUNI_MAP = 4;
    }
  if ((randmob%4 == 0) && ((jena.weaponTab[1].available == 1) || (jena.weaponTab[2].available == 1)))
    {
      start_battle();
    }
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 1)
        {
	  system("cat src/code_com.txt");
	  my_putstr("\n");
	  entree = readLine_code();
	  if ((strcmp(entree, "jena") == 0) || ((strcmp(entree, "JENA") == 0)))
	    {
	      if (DIAG_S03A02 == 0)
		{
		  my_putstr("Ca marche ! La porte se deverouille !\n");
		  my_putstr("Une minute ! Le code est mon prénom ?...\n");
		  my_putstr("Cela veut dire que...\n");
		  //sleep(1);
		  my_putstr("Je...\n");
		  //sleep(1);
		  my_putstr("Ce sont mes quartiers ?!\n\n");
		  DIAG_S03A02 = 1;
		  QUISUISJE = 1;
		}
	      else
		{
		  my_putstr("Je me dirige vers les quartiers du commandant.\nEnfin, vers MES quartiers.\n\n");
		}
	      g_map[1][1].content = 0;
	      salle = 2;
	      salle02(salle);
	    }
	  else
	    {
	      my_putstr("\nMAUVAIS CODE.\nOups, on dirait que ce n'est pas demain la veille que l'ont trouvera le code!\n\n");
	      action = 0;
	    }
	}
      if (action == 2)
	{
	  if (CARTE_COM == 0)
	    {
	      my_putstr("\nVous avez besoin d'une carte pour entrer.\n\n");
	      action = 0;
	    }
	  else
	    {
	      my_putstr("\nTiens, je vois un lecteur de carte pres de la porte ! J'essaye la mienne, une minute...\n");
	      //sleep(1);
	      my_putstr("\nParfait, la porte s'est ouverte !\n\n");
	      g_map[1][1].content = 0;
	      salle = 4;
	      salle04(salle);
	    }
	}
      if (action == 3)
	{
	  system("cat src/code_pil.txt");
	  my_putstr("\n");
	  entree = readLine_code();
	  if ((strcmp(entree, "ICARUS") == 0))
	    {
	      my_putstr("\nICARUS, le nom du vaisseau, logique !\nEsperons que la cabine de pilotage ne sois pas trop endommagee !\n\n");
	      g_map[1][1].content = 0;
	      salle = 1;
	      salle01(salle);
	    }
	  else
	    {
	      my_putstr("\nMAUVAIS CODE.\nLe protocole de securité est trop dur pour moi ...\n\n");
	      action = 0;
	    }
	}
      if (action == 4)
	{
	  my_putstr("\nTres bien, rebroussons chemin pour l'instant !\n\n");
	  g_map[1][1].content = 0;
	  salle = 6;
	  salle06(salle);
	}
      if (action == 5)
	{
	  prendre(salle);
	  action = 0;
	}
    }
}
