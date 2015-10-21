#include "fonctions.h"
#include "fonctions.h"
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

int		prendre(int salle)
{
  char		*entree;

  entree = malloc(sizeof(char*));
  entree = readline_prendre();

  /*debut des salles*/
  /*DEBUT 02*/
  if(salle == 02)
    {
      if (strcmp(entree, "douche") == 0)
	{
	  system("cat src/douche.txt");
	  my_putstr("\n\n");
	  SCORE = SCORE + 20;
	  DOUCHE_TAKEN = 1;
	  return (0);
	}
      else if (strcmp(entree, "du repos") == 0)
	{
	  my_putstr("\n\n");
	  jena.pv = jena.pvmax;
	  my_putstr("\n\nJe me suis reposée un peu, j'ai récupéré toute ma forme !\n\n");
	  return (0);
	}
      else if (strcmp(entree, "carte") == 0)
	{
	  if (CARTE_COM == 0)
	    {
	      my_putstr("\nEcoutez, je ne sais pas si c'est important mais j'ai trouve une carte d'acces avec mon nom dessus !\n\n");
	      system("cat src/carte_com.txt");
	      my_putstr("\n");
	      CARTE_COM = 1;
	      SCORE = SCORE + 5;
	    }
	  else
	    {
	      my_putstr("Je ne vois pas de ");
	      my_putstr(entree);
	      my_putstr(" dans cette salle !\n\n");
	    }
	  return (0);
	}
    }
  /*FIN 02*/

  /*DEBUT 04*/
  if(salle == 4)
    {
      if (strcmp(entree, "pistolet") == 0)
        {
          if ((jena.weaponTab[1].available == 0) && (jena.weaponTab[2].available == 0))
            {
              my_putstr("\nJ'ai fouillé l'armurerie, et devinez ce que j'ai trouvé ?\n");
	      my_putstr("Un Pistolet Laser flambant neuf ! Il est charge et pret a l'emploi !\n");
	      my_putstr("Je me sens deja plus rassurée !\n");
              jena.weaponTab[1].available = 1;
	      ARME_EQUIP = 1;
              SCORE = SCORE + 10;
            }
	  else if (strcmp(entree, "fusil") == 0)
	    {
	      if ((jena.weaponTab[1].available == 0) && (jena.weaponTab[2].available == 0))
		{
		  my_putstr("\nJ'ai fouillé l'armurerie, et devinez ce que j'ai trouvé ?\n");
		  my_putstr("Un Fusil plasma flambant neuf ! Il est chargé et pret a l'emploi !\n");
		  my_putstr("Je me sens deja plus rassurée !\n");
		  ARME_EQUIP = 2;
		  jena.weaponTab[2].available = 1;
		  SCORE = SCORE + 10;
		}
	      else
		{
		  my_putstr("\nIl y a quelques armes et outils dont j'ignore la fonction.\n");
		  my_putstr("Je ne vois rien d'autre d'immediatement utile a emmener avec moi.\n");
		}
	    }
	  else
	    {
	      my_putstr("Je ne vois pas de ");
	      my_putstr(entree);
	      my_putstr(" dans cette salle !\n\n");
	    }
	  return (0);
	}
    }
      /*FIN 04*/

      /*DEBUT 08*/
  if(salle == 8)
    {
      if (strcmp(entree, "badge") == 0)
	{
	  if (CARTE_ACCES == 0)
	    {
	      my_putstr("\nVous etes sur ? Degoutant !\nBon, tres bien ! Je prend le badge d'acces du sergent Colas.\n\n");
	      CARTE_ACCES = 1;
	      SCORE = SCORE + 5;
	    }
	  else
	    {
	      my_putstr("\nJ'ai deja pris le badge.\nNe m'obligez pas a fouiller le cadavre d'avantage.\n\n");
	    }
	}
      else
	{
	  my_putstr("Je ne vois pas de ");
	  my_putstr(entree);
	  my_putstr(" dans cette salle !\n\n");
	}
      return (0);
    }
  /*FIN 08*/

  /*DEBUT 24*/
  if(salle == 24)
    {
      if (strcmp(entree, "combinaison") == 0)
	{
	  if (COMBI == 0)
	    {
	      my_putstr("Bonne idee, une combinaison anti-radiation ne pourra que m'etre utile !\n\n");
	      COMBI = 1;
	      SCORE = SCORE + 10;
	    }
	  else
	    {
	      my_putstr("J'ai deja pris la combinaison !\n\n");
	    }
	}
      else
	{
	  my_putstr("Je ne vois pas de ");
	  my_putstr(entree);
	  my_putstr(" dans cette salle !\n\n");
	}
      return (0);
    }
  /*FIN 24*/

  /*DEBUT 11*/
  if(salle == 11)
    {
      if (strcmp(entree, "medicament") == 0)
	{
	  if (MEDIC_RESE > 0)
	    {
	      my_putstr("J'ai fouillé dans les armoires, et ai trouvé [x1] Médicament !\n\n");
	      jena.medicaments += 1;
	      MEDIC_RESE--;
	      SCORE = SCORE + 1;
	    }
	  else
	    {
	      my_putstr("Il n' y a plus de médicaments dans la piece !\n\n");
	    }
	}
      else
	{
	  my_putstr("Je ne vois pas de ");
	  my_putstr(entree);
	  my_putstr(" dans cette salle !\n\n");
	}
      return (0);
    }
  /*FIN 11*/
  my_putstr("\nIl n'y a rien a prendre dans cette salle vous savez...\n\n");
  return (1);
}


