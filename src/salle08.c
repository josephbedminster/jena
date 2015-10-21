#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle08(int salle)
{
  int           action;
  char		*entree_code;
  int           b;

  entree_code = malloc(sizeof(entree_code));
  action = 0;
  g_map[3][0].visited = 1;
  g_map[3][0].content = 1;
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
      if (action == 1)
	{
	  erreur_depla(salle);
	  action = 0;
	}
      if (action == 2)
	{
	  my_putstr("\nJ'espere que tout le vaisseau n'est pas que remplis de cadavres.\n\n");
	  g_map[3][0].content = 0;
	  salle = 9;
          salle09(salle);
        }
      if (action == 3)
        {
	  my_putstr("\nA travers la porte j'ai appercu un lit, c'est vrai que je manque de someil");
	  my_putstr(" mais j'espere juste que c'est les quartiers des femmes.\n\n");
	  g_map[3][0].content = 0;
	  salle = 5;
          salle05(salle);
        }
      if (action == 4)
	{
	  system("cat src/code_inf.txt");
          my_putstr("\n");
	  entree_code = readLine_code();
          if ((strcmp(entree_code, "adn") == 0) || ((strcmp(entree_code, "ADN") == 0)))
            {
	      my_putstr("\nCa marche, la porte est déverouillée !");
	      my_putstr("\nHeureusement que vous etes la, je serai restée bloquée devant cette porte toute la journée sans vous !\n\n");
	      g_map[3][0].content = 0;
	      salle = 11;
	      salle11(salle);
	    }
	  else
	    {
	      my_putstr("J'ai l'impression qe ce n'est pas le bon code !\n");
	      action = 0;
	    }
	}
      /*Prendre*/
      if (action == 5)
        {
	  prendre(salle);
          action = 0;
        }
      /*fin prendre*/
    }
}
