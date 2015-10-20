 #include "fonctions.h"

extern t_map g_map[10][4];

void            salle06(int salle, t_player *player)
{
  int           action;
  
  action = 0;
  g_map[2][1].visited = 1;
  g_map[2][1].content = 1;
  look(salle);
  while (action == 0)
    {
      /*On propose ici le prompt au joueur*/
      action = readline(salle, player);
      /*Traitement de laction :*/
      if (action == 1)
        {
	  my_putstr("\nEt bien tout compte fait je preferais le dortoir pour homme, ");
	  my_putstr("qui sais je pourrais y trouver des informations sur les hommes mort avent.\n\n");
	  g_map[2][1].content = 0;
	  salle = 5;
          salle05(salle, player);
        }
      if (action == 2)
        {
	  my_putstr("\nEncore une salle mais combien il y en a de ce genre ? Vous pensez que c'est encore grand ?\n\n");
	  g_map[2][1].content = 0;
	  salle = 7;
	  salle07(salle, player);                                                         
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
	      my_putstr("Ca marche, la porte s'est ouverte !\n");
              g_map[2][1].content = 0;
              salle = 3;
              salle03(salle, player);
            }
        }
      if (action == 4)
        {
          erreur_depla(salle);
          action = 0;
        }
      if (action == 5)
        {
          prendre(salle, player);
	  action = 0;
        } 
    }
}
