#ifndef __HERO_H__
#define __HERO_H__
#define MAP_X 4
#define MAP_Y 10
#define NB_ATTACK 2
#define NB_WEAPON 3
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*USER*/
char*		USER;
int		SCORE;
int		ARME_EQUIP;
/*VARIABLES GLOBALES KEY*/
int		COMBI;
int		CARTE_ACCES;
int		CARTE_COM;

/*VARIABLES GLOBALES ITEMS DANS LA MAP*/
int		MEDIC_RESE;

/*VARIABLES GLOBALES DE DIALOGUE*/
int		DIAG_S12A09;
int		DIAG_S09A08;

typedef struct  s_attack
{
  char          *name;
  int           damage;
}               t_attack;

typedef struct  s_enemy
{
  char          *name;
  int           pv;
  int		pvmax;
  t_attack      *attack;
}               t_enemy;

// arme du joueur
typedef struct  s_weapon
{
  int           available;
  char          *name;
  int           damage;
}               t_weapon;

// le joueur
typedef struct  s_player
{
  int		lvl;
  int           pv;
  int		pvmax;
  int		medicaments;
  t_weapon      *weaponTab;
}               t_player;

void		init_e(t_enemy *e);
int		battle(t_enemy *e, int i);
int		start_battle();
int             enemy_attack(t_enemy *e);
int             player_attack(t_enemy *e);
void		init_globales();
char            *readLine_code();
void            erreur_prendre();
void            quisuisje();

void            salle01(int salle);
void            salle02(int salle);
void            salle03(int salle);
void            salle04(int salle);
void            salle05(int salle);
void            salle06(int salle);
void            salle07(int salle);
void            salle08(int salle);
void            salle09(int salle);
void            salle10(int salle);
void            salle11(int salle);
void            salle12(int salle);
void            salle13(int salle);
void            salle14(int salle);
void            salle15(int salle);
void            salle16(int salle);
void            salle17(int salle);
void            salle18(int salle);
void            salle19(int salle);
void            salle20(int salle);
void            salle21(int salle);
void            salle22(int salle);
void            salle23(int salle);
void            salle24(int salle);

void            spawn(int salle, t_player *player);
int             comparer(char* entree, int salle);
void            erreur_depla(int salle);
void            my_putstr(char* str);
void            my_putchar(char c);
void    	my_putnbr(int n);
int             isnegatif(int n);
int             readline(int salle);
char             *readline_prendre();
char		*readLine();
int             my_strcmp(char *s1, char *s2);
char            *my_strcpy(char *dest, char *src);
void            suspens();
void            accueil();
void            help();
void            gameover();
void    	show_map();
void            look(int salle);
int             my_strlen(char* str);
void            fouiller(int salle);
int		prendre(int salle);
void            score();

typedef struct s_tete
{
  char nom_obj;
  int def;
} t_tete;

typedef struct s_corps
{
  char nom_obj;
  int def;
} t_corps;

typedef struct s_jambes
{
  char nom_obj;
  int def;
} t_jambes;

typedef struct s_pied
{
  char nom_obj;
  int def;
} t_pied;

typedef struct s_inventaire
{
  char nom_obj;
  void *prev;
  void *next;
} t_inventaire;


typedef struct s_map
{
  int	exist;
  int	size_x;
  int	links[4];
  int	content;
  int	visited;
} t_map;

/*eauiper arme 1;*/

/*equiper main : t_player->mainWeapon = t_player->weapons[1];*/


#endif
