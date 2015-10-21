 #include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void            salle06(int salle)
{
  int           action;

  action = 0;
  g_map[2][1].visited = 1;
  g_map[2][1].content = 1;
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
	  my_putstr("\nCe couloir ouvre sur plusieurs portes. Il y a des noms a l'entree de chaque porte. ");
	  my_putstr("COLAS, CURLLY, ... Ce doit etre les quartiers des hommes de l'equipage.\n");
	  my_putstr("Esperons que j'en aprenne d'avantage sur l'equipage.");
	  g_map[2][1].content = 0;
	  salle = 5;
          salle05(salle);
        }
      if (action == 2)
        {
	  my_putstr("\nOn dirait... Des quartiers ! Tout est en desordre, mais je devine aux bottes et aux accessoires sur les lits que ce doit etre les quartiers des femmes.\n\n");
	  g_map[2][1].content = 0;
	  salle = 7;
	  salle07(salle);
        }
      if (action == 3)
        {
	  if (CARTE_ACCES == 0)
            {
              my_putstr("\nLa porte est fermee. On dirait qu'il faut une badge d'acces.\n");
	      my_putstr("Super, je suis piegee dans un vaisseau flippant, enfermee avec des cadavres...\n");
	      my_putstr("Tout. Va. Bien !\n\n");
              action = 0;
            }
          else
            {
	      my_putstr("J'essaye le badge sur le boitier de la porte...\n");
	      sleep(1);
	      my_putstr("Et... Ca marche, la porte s'est ouverte !\n");
              g_map[2][1].content = 0;
              salle = 3;
              salle03(salle);
            }
        }
      if (action == 4)
        {
          erreur_depla(salle);
          action = 0;
        }
      if (action == 5)
        {
          prendre(salle);
	  action = 0;
        }
    }
}
