#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle05(int salle)
{
  int           action;

  action = 0;
  g_map[2][0].visited = 1;
  g_map[2][0].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 2)
        {
	  if (CARTE_ACCES == 0)
	    {
	      my_putstr("\nLa porte est verouillee ! Il faudrait que je trouve ce qui la deverouille....\n");
	      my_putstr("Dis comme ca, ca parait assez facile non ?\n\n");
	      action = 0;
	    }
	  else
	    {
	      g_map[2][0].content = 0;
	      salle = 6;
	      salle06(salle);
	    }
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
