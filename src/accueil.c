#include "fonctions.h"

void            accueil()
{
  char          *entree;

  entree = malloc(sizeof(char*));
  system("clear");
  system("clear");
  system("cat src/header.txt");

  my_putstr("\n\n\n\033[5m[Demande de communication entrante]\033[0m\n");
  sleep(1);
  my_putstr("\033[5m[Connection...]\033[0m\n");
  sleep(1);
  my_putstr("\033[5m[Communication établie]\n\033[0m");
  sleep(2);
  my_putstr("\nEh oh ! Est-ce que quelqu'un m'entend ?\n\n");
  my_putstr(" > ");
  readLine();
  my_putstr("\nJ'ai entendu quelque chose ! Il y a quelqu'un ? Qui êtes vous ?\n\n");
  my_putstr(" > Entrez votre nom : ");
  USER = readLine();
  my_putstr("\nOh mon dieu, enfin quelqu'un ! ");
  my_putstr(USER);
  my_putstr(", vous me sauvez la vie !\n");
  my_putstr("Vous êtes la seule personne joignable dans tout le secteur !\n");
  //sleep(3);
  my_putstr("Je ne sais absolument pas où je suis... On dirait l'intérieur d'un vaisseau...\n");
  //sleep(3);
  my_putstr("Aucune idée de ce que je fais ici... Vu la douleur qui me lance dans la tete, j'ai du m'evanouir...\n");
  //sleep(3);
  my_putstr("Le mur est plein de sang ! Oh... Je pense que c'est le mien. J'ai du me cogner la tête.\n");
  //sleep(3);
  my_putstr("Depuis mon réveil, une alarme resonne dans la piece, merci pour mes migraines !\n");
  //sleep(3);
  my_putstr("Mais je vais bien, au cas ou vous demanderiez !\n");
  //sleep(3);
  my_putstr("Il y a du avoir un crash, c'est la seule explication logique.\n");
  my_putstr("La question qui perdure c'est : Qu'est ce que je faisais dans ce vaisseau ?\n");
  //sleep(5);
  my_putstr("Oh ! Mais je parle depuis tout a l'heure, je ne vous ai meme pas dit comment je m'apelle !\n");
  //sleep(3);
  my_putstr("Oui, j'ai perdu la tete, mais je me souviens encore de mon nom !\n\n");
  //sleep(3);
  my_putstr("Je m'apelle Jena ! Enchantée !\n\n");
  //sleep(3);
  my_putstr(USER);
  my_putstr(", ca vous derange si je vous demande des conseils en attendant les secours ?\n");
  //sleep(3);
  my_putstr("Juste un peu ? S'il vous plait !\n");
  my_putstr("Par exemple ! Je suis dans un couloir aux murs blancs -enfin- blancs plus quelques traces de sang...\n");
  //sleep(5);
  my_putstr("Et je vois deux couloirs : un qui part... disons vers le nord pour que ce soit compréhensible pour vous.\n");
  my_putstr("Et l'autre vers le sud. Aucune idée sur ce qu'il peut y avoir plus loin.\n");
  //sleep(3);
  my_putstr("Que me conseillez-vous de faire ? Dans quelle direction dois-je aller ?\n\n");
  my_putstr("-- Liste des commandes : aide --\n\n");
}
