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
#include "includes/files.h"
#include "includes/helpers/output.h"
#include "includes/helpers/string.h"
#include "includes/t_file.h"
#include "includes/t_dir.h"
#include "includes/dirs.h"

t_dir		*to_dir(char *target, DIR *opened_dir)
{
  DIR		*tmp_dir;
  t_dir		*dir;
  t_file	**file_array;
  int		size;
  long long	total_blocs;

  tmp_dir = opendir(target);
  dir = malloc(sizeof(t_dir));
  size = how_many_files_in_dir(tmp_dir);
  file_array = malloc(sizeof(t_file *) * size);
  total_blocs = 0;
  if (dir == 0 || file_array == 0)
    {
      print_error("Malloc failed :(");
      exit(84);
    }
  iterate_dir(target, opened_dir, file_array, &total_blocs);
  dir->path = target;
  dir->size = total_blocs;
  dir->files = file_array;
  closedir(tmp_dir);
  return (dir);
}

void		iterate_dir(char *t, DIR *dir, t_file **array, long long *bloc)
{
  struct dirent	*dir_entry;
  char		*r_path;
  int		i_files;

  i_files = 0;
  while ((dir_entry = readdir(dir)) != 0)
    {
      if (dir_entry->d_name[0] != '.')
	{
	  r_path = get_path(t, dir_entry->d_name);
	  array[i_files] = to_file(r_path, my_strdup(dir_entry->d_name));
	  *bloc = *bloc + array[i_files]->blocks / 2;
	  i_files = i_files + 1;
	  free(r_path);
	}
    }
  array[i_files] = 0;
}

int		how_many_files_in_dir(DIR *dir)
{
  int		count;
  struct dirent	*dir_entry;

  count = 0;
  while ((dir_entry = readdir(dir)) != 0)
    count = count + 1;
  return (count);
}

char	*init_get_path(int *size, int dir_size, int file_size, int *i)
{
  char	*path;

  *size = dir_size + file_size + 2;
  path = malloc(sizeof(char) * *size);
  if (path == 0)
    {
      print_error("Malloc failed :(");
      exit(84);
    }
  *i = 0;
  return (path);
}

char	*get_path(char *directory, char *filename)
{
  char	*path;
  int	dir_size;
  int	size;
  int	i;

  dir_size = my_strlen(directory);
  path = init_get_path(&size, dir_size, my_strlen(filename), &i);
  while (i < (size - 1))
    {
      if (i < dir_size)
	{
	  path[i] = *directory;
	  directory = directory + 1;
	}
      else if (i == dir_size)
	path[i] = '/';
      else
	{
	  path[i] = *filename;
	  filename = filename + 1;
	}
      i = i + 1;
    }
  path[i] = 0;
  return (path);
}
