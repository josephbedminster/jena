#include "fonctions.h"

void		accueil(t_player *player)
{
  char		*entree;
  
  entree = malloc(sizeof(char*));
   my_putstr("\n\n ============================================\n");
  my_putstr("            Bienvenue dans ZORK-ETNA            \n");
  my_putstr(" ============================================\n\n");
  my_putstr("Aventurier, entrez votre nom : ");
  my_strcpy(entree, readLine());
  player->name = entree;
  my_putstr("\nBienvenue ");
  my_putstr(player->name);
  my_putstr(" ! \nVotre aventure commence dans un labyrinthe !\n");
  sleep(2);
  my_putstr("A vous de trouver le bon chemin\n");
  sleep(2);
  my_putstr("En esperant que la mort ne vous emporte pas avant !\n");
  sleep(2);
  my_putstr("Vous vous reveillez dans une petite salle sombre, sans issue apparente...\n");

}
