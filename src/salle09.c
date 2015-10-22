#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle09(int salle)
{
  int           action;
  int           randmob;
  int           randmuni;

  action = 0;
  g_map[3][1].visited = 1;
  g_map[3][1].content = 1;
  look(salle);
  srand(time(NULL));
  randmob = rand();
  randmuni = rand();
  MUNI_MAP = 0;


  if ((randmob%4 == 0) && ((jena.weaponTab[1].available == 1) || (jena.weaponTab[2].available == 1)))
    {
      start_battle();
    }
  if ((randmuni%4 == 0))
    {
      MUNI_MAP = 4;
    }
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle);
      /*Traitement de laction :*/
      if (action == 1)
        {
	  if (DIAG_S09A08 == 0)
	    {
	      my_putstr("\n\nJ'entre dans l'infirmierie. Esperons que j'y trouve de quoi me soigner.\n");
	      my_putstr("Il y a encore un homme mort sur la table d'operation... Le sol est recouvert de sang.\n");
	      my_putstr("Il a du se trainer jusqu'ici et se hisser sur la table...\n");
	      my_putstr("Je m'approche du corps...\n");
	      //sleep(5);
	      my_putstr("Il est ecrit -Sergent Colas- sur l'uniforme.\n");
	      //sleep(5);
	      my_putstr("Un objet semble depasser de la poche interieure de la veste.\nOn dirait un badge d'acces.\n");
	      my_putstr("Bonne nouvelle, j'ai trouvée de quoi reparer ce qui me sert de tete !\n");
	      my_putstr("Quand je vois le reste de l'equipage, je m'estime heureuse qu'elle tienne encore sur mes epaules !\n");
	      my_putstr("Attendez un minute que je desinfecte la plaie et que je fasse un pansement.\n");
	      //sleep(5);
	      my_putstr("Voila ! Bad news/Good news :\n");
	      my_putstr("Bad news : je n'aurai pas fait une bonne infirmiere ! Mon pansement ne tiendra pas une heure...\n");
	      my_putstr("Good news : la plaie etait moins grave que prevue ! Je m'en sortirai !\n");
	      my_putstr("(Mis a part mes 'petits' problemes de mémoire, tout va bien)");
	      DIAG_S09A08 = 1;
            }
          else
            {
              my_putstr("\nJe retourne vers l'infirmerie.\n");
            }
	  g_map[3][1].content = 0;
	  salle = 8;
          salle08(salle);
        }
      if (action == 2)
        {
	  if (CARTE_ACCES == 1)
	    {
	      my_putstr("\nYeah le bagde a fonctionner, j'ai acces a cette salle maintenant\n\n");
	      sleep(2);
	      my_putstr("\nAh, enfin quelque chose d'interessant ! Il y a une grande baie vitrée de ce coté.\n");
	      my_putstr("Je pense que c'est un laboratoire !\n");
	      my_putstr("Allez, ouvrons les paris ! Je parie que je vais trouver...\n");
	      my_putstr("...");
	      sleep(2);
	      my_putstr("Un microscope ! Aha !\nEt vous ?\n");
	      g_map[3][1].content = 0;
	      salle = 10;
	      salle10(salle);
	    }
	  else
	    {
	      my_putstr("\nJe crois que cette baie vitrée va rester fermer\n\n");
	      action = 0;
	    }
        }
      if (action == 4)
        {
	  my_putstr("\nJ'ai l'impression d'etre perdue, vous etes sur de ce que vous faites ?\n\n");
	  g_map[3][1].content = 0;
	  salle = 12;
	  salle12(salle);
        }
      /*Prendre*/
      if (action == 5)
        {
          prendre(salle);
          action = 0;
        }
      /*fin prendre*/
      if (action == 3)
        {
          erreur_depla(salle);
          action = 0;
        }
    }
}
