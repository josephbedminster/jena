int             prompt(t_creature *mob)
{
  char          *entree;
  int           result;

  result = 0;
  while (result == 0)
    {
      entree = malloc(sizeof(char*));
      my_putstr(" > ");
      my_strcpy(entree, readLine());
      result = comp(entree);
    }
  return (result);
}
