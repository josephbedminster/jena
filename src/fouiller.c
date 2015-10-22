#include "fonctions.h"
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void		fouiller(int salle)
{
  int		is_muni;

  is_muni = 0;

  my_putstr("\nJe pense que je peux prendre :\n");
  if(MUNI_MAP > 0)
    {
      my_putstr(" - des <munitions>\n");
      is_muni = 1;
      /*SALLE 2*/
      if (salle == 2)
	{
	  my_putstr(" - <du repos> (permet de récupérer toute sa vie [60secondes])\n\n");
	  if (CARTE_COM == 0)
	    {
	      my_putstr(" - une <carte> d'identification\n\n");
	    }
	  return;
	}
      /*FIN SALLE02*/

      /*SALLE 04*/
      if (salle == 4)
	{
	  if (((jena.weaponTab[1].available == 0) && (jena.weaponTab[2].available == 0)) || (MUNI_ARMU > 0))
	    {
	      if ((jena.weaponTab[1].available == 0) && (jena.weaponTab[2].available == 0))
		{
		  my_putstr(" - un <pistolet> laser \n");
		  my_putstr(" - un <fusil> plasma \n");
		}
	      if (MUNI_ARMU > 0)
		{
		  my_putstr(" - des <munitions> \n\n");
		}
	      else
		my_putstr("Je suis armée et prete au combat ! Je ne vois plus rien d'utile ici !");
	      return;
	    }
	}
      /*FIN SALLE04*/

      /*SALLE 08*/
      if (salle == 8)
	{
	  if (CARTE_ACCES == 0)
	    {
	      my_putstr(" - un <badge> d'acces\n\n");
	    }
	  else
	    {
	      my_putstr("\nJ'ai beau chercher, je vois rien a récuperer.\n\n");
	    }
	  return;
	}
      /*SALLE08*/

      /*SALLE 11 RESERVE*/
      else if (salle == 11)
	{
	  if (MEDIC_RESE != 0)
	    {
	      my_putstr(" - un <medicament>\n\n");
	    }
	  else
	    {
	      my_putstr("\nJ'ai beau chercher, je vois rien a récuperer.\n\n");
	    }
	  return;
	}
      /*FIN SALLE11*/

      /*SALLE 24*/
      else if (salle == 24)
	{
	  if (COMBI == 0)
	    {
	      my_putstr(" - une <combinaison> anti-radiation\n\n");
	    }
	  else
	    {
	      my_putstr("\nJ'ai beau chercher, je vois rien a récuperer.\n\n");
	    }
	  return;
	}
      /*FIN SALLE24*/
    }
  if (is_muni == 0)
  my_putstr("\n\nHeu bah rien enfaite...\n\n");
  else
    my_putstr("\n");
}
