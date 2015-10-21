#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle02(int salle)
{
  char		*entree;
  int           action;

  entree = malloc(sizeof(char*));
  action = 0;
  g_map[1][0].visited = 1;
  g_map[1][0].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 2)
        {
	  my_putstr("\nJe serai bien reste a l'abri ici pour attendre les secours... Mais je risque de manquer de nouriture et d'eau.\n");
	  my_putstr("C'est reparti pour l'aventure dans ce vaisseau super-flippant !\n");
	  g_map[1][0].content = 0;
	  salle = 3;
          salle03(salle);
        }
      /*Prendre*/
      if (action == 5)
        {
	  prendre(salle);
          action = 0;
        }
      /*fin prendre*/
      if ((action == 1) || ((action >= 3) && (action <= 4)))
        {
          erreur_depla(salle);
          action = 0;
        }
    }
}