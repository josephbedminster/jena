#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle16()
{
  int           action;
  int           randmob;
  int           randmuni;
  int           randmedic;


  action = 0;
  g_map[7][0].visited = 1;
  g_map[7][0].content = 1;
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
      if (action == 3)
        {
	  my_putstr("\nEt bien atteindre le fond de se hangard etait long,mais bon j'ai trouver de petit");
	  my_putstr(" chose interessante mais se trou dans la coque m'inquiette.\n\n");
	  g_map[7][0].content = 0;
	  SALLE = 15;
          salle15();
        }
      /*Prendre*/
      if (action == 5)
        {
          prendre();
          action = 0;
        }
      /*fin prendre*/
      if ((action == 4) || ((action >= 1) && (action <= 2)))
        {
          erreur_depla();
          action = 0;
        }
    }
}
