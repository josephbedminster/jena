#include "fonctions.h"

extern t_map g_map[10][4];

void            salle05(int salle, t_player *player)
{
  int           action;

  action = 0;
  g_map[2][0].visited = 1;
  g_map[2][0].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if (action == 2)
        {
	  my_putstr("\nOh une salle avec une porte totalement fermer, pourquoi ne pas essayer de trouver se qui la deverouille.\n\n");
	  g_map[2][0].content = 0;
          salle = 6;
	  salle06(salle, player);
        }
      if (action == 4)
        {
	  my_putstr("\nOn retourne vers le cadavre du sergent, vous etes sur de vouloir vraiment y retourner ? Moi personnelement cela ne me plait pas.");
	  g_map[2][0].content = 0;
	  salle = 8;
	  salle08(salle, player);
	}
      if (action == 5)
        {
          prendre(salle, player);
	  action = 0;
        }
      if ((action == 1) || (action == 3))
        {
	  erreur_depla(salle);
	  action = 0;
        }
    }
}
