#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle14()
{
  int           action;
  char			*mort;
  int			choix;
  int           randmob;
  int           randmuni;
  int           randmedic;


  choix = 0;
  mort = NULL;
  action = 0;
  g_map[5][0].visited = 1;
  g_map[5][0].content = 1;
  look();
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
      action = readline();
      /*Traitement de laction :*/
      if (action == 2)
        {
	  my_putstr("\nCe hangard ne m'inspire vraiment pas,je prefere faire demi-tour.\n\n");
	  g_map[5][0].content = 0;
	  SALLE = 13;
          salle13();
        }
      if (action == 4)
        {
	  my_putstr("\nVous etes sur de vouloir aller par la ???\nL'air c'est extrement rafrechie ici... ce n'est pas un bon signe\n\n");
	  my_putstr("Dois-je continuer ???\n   >");
	  while (choix == 0)
	    {
	      mort = readLine();
	      if (strcmp(mort, "oui") == 0)
		choix = 1;
	      else if (strcmp(mort, "non") == 0)
		choix = 2;
	    }
	  if (choix == 1)
	    {
	      if (COMBI == 0)
		{
		  my_putstr("J'entre dans le hangar !\nIl y a un enorme trou dans la coque !\n");
		  my_putstr("Je me sens mal !...\n");
		  ////sleep(2);
		  my_putstr("Je...\n");
		  gameover();
		  score();
		}
	      else
		{
		  my_putstr("\nPfiou!!! Heureusement que j'ai ma combinaison sinon je ne pense pas survivre.\n\n");
		  g_map[5][0].content = 0;
		  SALLE = 15;
		  salle15();
		  choix = 0;
		}
	    }
	  else
	    {
	      my_putstr("\nVous avez surement raison une foi de plus,je vais vous ecouter\n\n");
	      choix = 0;
	      action = 0;
	    }
	}
      /*Prendre*/
      if (action == 5)
        {
          prendre();
          action = 0;
        }
      /*fin prendre*/
      if ((action == 1) || (action == 3))
	{
	  erreur_depla();
	  action = 0;
	}
    }
}
