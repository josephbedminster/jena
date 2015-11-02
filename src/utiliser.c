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
	  my_putstr("\nVous n'avez pas de médicaments !\n");
  	}
      else
  	{
	  jena.pv += 50;
	  if (jena.pv > jena.pvmax)
		jena.pv = jena.pvmax;
	  jena.medicaments -= 1;
	  my_putstr("\n\033[1;32mVous prenez [1x] médicament. Vous regagnez 50 points de vie.\n\033[0m");
	  if (jena.medicaments > 0)
	    {
	      my_putstr("Il vous reste [");
	      my_putnbr(jena.medicaments);
	      my_putstr("x] médicaments !\n\n");
	    }
	  else
	    {
	      my_putstr("Vous n'avez plus de médicaments !\n");
	    }
  	}
    }
}
