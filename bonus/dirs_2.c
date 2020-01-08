/*
** dirs.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Thu Dec  1 21:30:27 2016 Jérémy Sid Idris
** Last update Thu Dec  1 21:30:27 2016 Jérémy Sid Idris
*/

#include <dirent.h>
#include <stdlib.h>
#include "../includes/files.h"
#include "../includes/helpers/output.h"
#include "../includes/helpers/string.h"
#include "../includes/t_file.h"
#include "../includes/t_dir.h"
#include "includes/dirs.h"

void		it_h_dir(char *t, DIR *dir, t_file **array, long long *bloc)
{
  struct dirent	*dir_entry;
  char		*r_path;
  int		i_files;

  i_files = 0;
  while ((dir_entry = readdir(dir)) != 0)
    {
	r_path = get_path(t, dir_entry->d_name);
	array[i_files] = to_file(r_path, my_strdup(dir_entry->d_name));
	*bloc = *bloc + array[i_files]->blocks / 2;
	i_files = i_files + 1;
	free(r_path);
    }
  array[i_files] = 0;
}
