#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle23(int salle)
{
  int           action;

  action = 0;
  g_map[5][2].visited = 1;
  g_map[5][2].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 1)
        {
	  my_putstr("\nC'est dommage de quitter cette reserve j'en suis sur que d'autre chose qui pourrait mettre utile se cache dedant.\n\n");
	  g_map[5][2].content = 0;
	  salle = 13;
	  salle13(salle);
	}
      if (action == 4)
        {
	  my_putstr("\nDes etageres remplie de cartons a ne plus savoir quoi en faire apparament, j'espere en tirer profit");
	  my_putstr(" pour tout le temp que je met a chercher dans chaque carton...\n\n");
	  g_map[5][2].content = 0;
	  salle = 24;
	  salle24(salle);
	}

      /*Prendre*/
      if (action == 5)
        {
          prendre(salle);
          action = 0;
        }
      /*fin prendre*/
      if ((action >= 2) && (action <= 3))
        {
	  erreur_depla(salle);
	  action = 0;
        }
    }
}
