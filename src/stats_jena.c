#include "fonctions.h"

extern t_map g_map[10][4];
extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;

void		stats_jena(int is_lvlup)
{
  my_putstr("\n                =========================\n");
  my_putstr("                           JENA");
  my_putstr("\n                =========================\n");
  if (is_lvlup)
    printf("                Niveau : \033[1;32m%d\033[0m(+ 1)\n", jena.lvl);
  else
    printf("                Niveau : %d\n", jena.lvl);
  printf("                Experience : %d\n", jena.exp);
  printf("                Prochain niveau : %d\n", xpNeeded(jena.lvl));
  if (is_lvlup)
    printf("                PV's : \033[1;32m[%d/%d]\033[0m (+ 10)\n", jena.pv, jena.pvmax);
  else
    printf("                PV's : [%d/%d]\n", jena.pv, jena.pvmax);
  printf("                Equipé : %s\n                > [%d dégats par coup]\n", jena.weaponTab[ARME_EQUIP].name, jena.weaponTab[ARME_EQUIP].damage);
    printf("                Armure : %d\n\n", jena.armure);
}

void		stats_arme()
{
  my_putstr("\n                =========================\n");
  my_putstr("                    ");
  my_putstr(jena.weaponTab[ARME_EQUIP].name);
  my_putstr("\n                =========================\n");
  printf("                Dégats : %d par coup\n", jena.weaponTab[ARME_EQUIP].damage);
  printf("                Cartouches : %d par coup\n", jena.weaponTab[ARME_EQUIP].munitions);
  printf("                Munitions : %d/%d\n", jena.munitions, jena.munitionsmax);
}

void		inventaire()
{
  stats_arme();
  my_putstr("                =========================\n");
  my_putstr("                        EQUIPEMENT");
  my_putstr("\n                =========================\n");
  show_equip();
  my_putstr("                =========================\n");
  my_putstr("                         AUTRES");
  my_putstr("\n                =========================\n");
  show_items();
  my_putstr("                =========================\n");
  my_putstr("                        MEDICAMENTS");
  my_putstr("\n                =========================\n");
  printf("                Possédés : %d\n\n", jena.medicaments);

}

void		show_items()
{
  if (CARTE_ACCES == 1)
    my_putstr("                - Badge d'acces\n");
  if (CARTE_COM == 1)
    my_putstr("                - Carte du commandant\n");
  if (COMBI == 1)
    my_putstr("                - Combinaison\n\n");

}


void		show_equip()
{
  if (BOTTES == 1)
    my_putstr("                - Bottes en cuir (Armure +4)\n");
}

int		give_exp(int exp)
{
  int		xpneeded;

  jena.exp = jena.exp + exp;
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
