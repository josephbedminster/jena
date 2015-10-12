void            salle01()
{
  do
    {
      read = readLine();
      if (my_strcmp(read, "gauche") == 0 )
        {
          my_putstr("Il y a un couloir pour aller a dans une autre salle.\n");
          //fichier salle04                                                                                                                                                                                                                                                   
        }
      if (my_strcmp(read, "droite") == 0 )
        {
          my_putstr("Il y a un couloir pour aller a dans une autre salle.\n");
          //fichier salle05                                                                                                                                                                                                                                                   
        }
      if (my_strcmp(read, "devant") == 0 )
        {
          my_putstr("Il y a un couloir pour aller a dans une autre salle.\n");
          //fichier salle03                                                                                                                                                                                                                                                   
        }
      if (my_strcmp(read, "derriere") == 0 )
        {
          my_putstr("Il y a un couloir pour aller a dans une autre salle.\n");
          //fichier salle05                                                                                                                                                                                                                                                   
        }
      if (my_strcmp(read, "regarder") == 0 )
        {
          my_putstr("Cette salle est le coeur du labyrinthe, vous avez acces a tout.\n");
        }
