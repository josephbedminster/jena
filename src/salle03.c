#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle03(int salle)
{
  int           action;
  char 		*entree;

  entree = malloc(sizeof(char*));
  action = 0;
  g_map[1][1].visited = 1;
  g_map[1][1].content = 1;
  look(salle);
  if(ARME_EQUIP != 0)
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
		  my_putstr("Une minute ! Le code est mon prenom ?...\n");
		  my_putstr("Cela veut dire que ...\n");
		  sleep(2);
		  my_putstr("Je");
		  sleep(2);
		  my_putstr("\n...\n");
		  sleep(2);
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
	      my_putstr("\nTien c'ette porte un detecteur de carte magnetique, et si j'esayer la mienne...\n");
	      sleep(3);
	      my_putstr("\nMais c'ette carte me donne un grand acces on dirait.\n\n");
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
	      my_putstr("\nICARUS, logique !\nEsperons que la cabine de pilotage ne sois pas trop endommagee !\n\n");
	      g_map[1][1].content = 0;
	      salle = 1;
	      salle01(salle);
	    }
	  else
	    {
	      my_putstr("\nMAUVAIS CODE.\nLe protocole de securite est trop dur pour moi ...\n\n");
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
