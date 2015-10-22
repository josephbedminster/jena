#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void		stats_jena(int is_lvlup)
{
  my_putstr("\n=========================\n");
  my_putstr("           JENA");
  my_putstr("\n=========================\n");
  if (is_lvlup)
    printf("Niveau : \033[1;31m%d\033[0m\n", jena.lvl);
  else
    printf("Niveau : %d\n", jena.lvl);
  printf("Experience : %d\n", jena.exp);
  printf("Prochain niveau : %d\n", jena.expnext);
  if (is_lvlup)
    printf("PV's : [%d/%d]\n", jena.pv, jena.pvmax);
  else
   printf("PV's : \033[1;31m[%d/%d]\033[0m\n", jena.pv, jena.pvmax);
  printf("Equipé : %s\n -%d dégats par tir\n", jena.weaponTab[ARME_EQUIP].name, jena.weaponTab[ARME_EQUIP].damage);
  printf("Munitions : %d/%d\n", jena.munitions, jena.munitionsmax);
  printf("Médicaments : %d\n\n", jena.medicaments);
}

void		stats_arme()
{
  my_putstr("\n================\n");
  printf("    Arme : %s\n", jena.weaponTab[ARME_EQUIP].name);
  my_putstr("\n================\n");
  printf("Dégats : %d par tir\n", jena.weaponTab[ARME_EQUIP].damage);
  printf("Utilise : %d\n", jena.weaponTab[ARME_EQUIP].munitions);
  printf("Munitions : %d/%d\n\n", jena.munitions, jena.munitionsmax);
}

int		give_exp()
{
  int		xpneeded;

  jena.exp = jena.exp + 10;
  xpneeded = xpNeeded(jena.lvl);
  if (jena.exp >= xpneeded)
    {
      jena.lvl = jena.lvl + 1;
      jena.exp = (jena.exp - xpneeded);
      jena.pvmax = jena.pvmax + 10;
      jena.pv = jena.pv + 10;
      return (1);
   }
  return (0);
}
