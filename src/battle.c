#include "fonctions.h"

extern t_weapon weaponList;
extern t_attack attackList;
extern t_player jena;


int		player_attack(t_enemy *e)
{
  int		commande;
  int           player_attack(t_enemy *e);

  commande = 0;
  my_putstr("Que souhaitez vous faire ?\n");
  printf("1 : Utiliser %s\n2 : Prendre un médicament\n", jena.weaponTab[ARME_EQUIP].name);
  while ((commande <= 0) || (commande > 2))
    {
      my_putstr("\nEntrez une action > ");
      commande = atoi(readLine());
      if (((commande == 2) && (jena.medicaments > 0)) && (jena.pv == jena.pvmax))
	{
	  printf("\nInutile de vous soigner maintenant, vous avez %d points de vie sur %d !\n", jena.pv, jena.pvmax);
	  commande = 0;
	}
      else if ((commande == 2) && (jena.medicaments < 1))
      	{
	  my_putstr("\nVous n'avez pas de médicaments !\n");
	  commande = 0;
	}
    }

  if (commande == 1)
    {
      printf("\n\033[1;31mVous avez infligé %d dégats\n\033[0m", jena.weaponTab[ARME_EQUIP].damage);
      sleep(2);
      e->pv -= jena.weaponTab[ARME_EQUIP].damage;
    }
  else if (commande == 2)
    {
      jena.pv += 50;
      if (jena.pv > jena.pvmax)
	jena.pv = jena.pvmax;
      jena.medicaments -= 1;
      my_putstr("\n\033[1;32mVous prenez [1x] médicament. Vous regagnez 50 points de vie.\n\033[0m");
      sleep(2);
      if (jena.medicaments > 0)
	{
	  my_putstr("Il vous reste [");
	  my_putnbr(jena.medicaments);
	  my_putstr("x] médicaments !\n\n");
	}
      else
	{
	  my_putstr("Vous n'avez plus de médicaments !\n");
	}
    }

  if (e->pv <= 0)
    {
      printf("\n- JENA : [%d/%d] PV's.\n- %s : [0/%d] PV's", jena.pv, jena.pvmax, e->name, e->pvmax);
      printf("\n\n\033[1;34mVous avez tué le %s !\n\033[0m", e->name);
      return (0);
    }
  else
    return (1);
}

int		enemy_attack(t_enemy *e)
{
  int		res;
  char		*buffer;

  // 1024 parce que j'en ai rien a foutre
  if ((buffer = malloc(sizeof(char) * 1024)) == NULL)
    return -1;
  res = rand() % NB_ATTACK;
  sprintf(buffer, "\033[1;31m%s vous attaque !\nIl utilise : %s, et vous inflige %d dégats.\033[0m", e->name, e->attack[res].name, e->attack[res].damage);
  puts(buffer);
  jena.pv -= e->attack[res].damage;
  if (jena.pv <= 0)
    {
      memset(buffer, 0, strlen(buffer));
      sprintf(buffer, "%s vous a vaincu....", e->name);
      puts(buffer);
      return (0);
    }
  return (1);
}

int battle(t_enemy *e, int i)
{
  char *buffer;

  if ((buffer = malloc(sizeof(char) * 200)) == NULL)
    return (-1);
  sprintf(buffer, "- JENA : [%d/%d] PV's.\n- %s : [%d/%d] PV's", jena.pv, jena.pvmax, e->name, e->pv, e->pvmax);
  puts(buffer);
  if (i % 2 == 0)
    {
      sleep(3);
      my_putstr("\n----------------------- Votre tour ---------------------------\n\n");
      return (player_attack(e));
    }
  else
    {
      sleep(3);
      my_putstr("\n\n------------------ Tour de l'adversaire ----------------------\n\n");
      return (enemy_attack(e));
    }
  return (0);
}

void init_e(t_enemy *e)
{
  e->name = "Monstre";
  e->pv = 80;
  e->pvmax = 80;
  e->attack = &attackList;
}

int	start_battle()
{
  t_enemy e;
  int i;
  int res;

  srand(time(NULL));
  res = 1;
  i = 0;
  init_e(&e);
  puts("\nUn monstre vous attaque !\n");
  while (res != 0)
    {
      res = battle(&e, i);
      i++;
    }
  /*Traitement de la fin de combat 1 : defaite, 0 : victoire*/
  if (jena.pv < 0)
    {
      gameover();
      score();
    }
  else
    {
      SCORE = SCORE + 20;
      my_putstr("\nJ'ai eu chaud ! Merci pour votre aide !\n\n");
    }
  return (0);
}
