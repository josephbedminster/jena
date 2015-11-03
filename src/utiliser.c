#include "fonctions.h"
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void             utiliser()
{
  char          *entree;
  
  entree = malloc(sizeof(char*));
  entree = readline_utiliser();
  if ((strcmp(entree, "medicament") == 0) || (strcmp(entree, "medicaments") == 0))
    {
      if ((jena.medicaments > 0) && (jena.pv == jena.pvmax))
	{
	  printf("\nInutile de vous soigner maintenant, vous avez %d points de vie sur %d !\n", jena.pv, jena.pvmax);
	}
      else if (jena.medicaments < 1)
	{
	  my_putstr("\nJe n'ai pas de médicaments !\n\n");
  	}
      else
  	{
	  jena.pv += 50;
	  if (jena.pv > jena.pvmax)
		jena.pv = jena.pvmax;
	  jena.medicaments -= 1;
	  my_putstr("\n\033[1;32mJ'ai pris [1x] médicament. J'ai regagné 50 points de vie.\n\033[0m");
	  if (jena.medicaments > 0)
	    {
	      my_putstr("\nIl me reste [");
	      my_putnbr(jena.medicaments);
	      my_putstr("x] médicaments !\n\n");
	    }
	  else
	    {
	      my_putstr("Il va falloir que je fasse plus attention, je n'ai plus de médicaments !\n\n");
	    }
  	}
    }
  if (strcmp(entree, "console") == 0)
    {
      if (SALLE == 1)
	{
	  system("clear");
	  my_putstr("\nLa console me donne accées a plusieur option du vaisseaux\n\n");
	  my_putstr(" ------------------------------------------------\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|          Console générale du vaisseau          |\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|             1 : Etat du vaisseau               |\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|              2 : Débloquer acces               |\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|            3 : Démarrer propulseurs            |\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|      4 : Utiliser système de communication     |\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|                                                |\n");
	  my_putstr(" ------------------------------------------------ \n");
	  sleep(2);
	  system("clear");
	  my_putstr("\nLa console me donne accées a plusieur option du vaisseaux\n\n");
	  my_putstr(" ------------------------------------------------\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|          Console générale du vaisseau          |\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|             1 : Etat du vaisseau               |\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|              2 : Débloquer acces               |\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|            3 : Démarrer propulseurs            |\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|      4 : Utiliser système de communication     |\n");
	  my_putstr("|                                                |\n");
	  my_putstr("|               Entrez une commande :            |\n");
	  my_putstr("|                                                |\n");
	  my_putstr(" ------------------------------------------------ \n");
	  entree = NULL;
	  entree = readline_console();
	  if (strcmp(entree, "1") == 0)
	    {
	      my_putstr("blabla\n");
	    }
	  if (strcmp(entree, "2") == 0)
	    {
	      my_putstr("blabla2\n");
	    }
	  if (strcmp(entree, "3") == 0)
	    {
	      my_putstr("blabla3\n");
	    }
	  if (strcmp(entree, "4") == 0)
	    {
	      my_putstr("blabla4\n");
	      }
	}
    }
}
