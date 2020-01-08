/*
** recursive_targets.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/parsers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sun Dec  4 13:10:02 2016 Jérémy Sid Idris
** Last update Sun Dec  4 13:10:02 2016 Jérémy Sid Idris
*/

#include <dirent.h>
#include <stdlib.h>
#include "../includes/files.h"
#include "../includes/dirs.h"
#include "../includes/helpers/array.h"
#include "../includes/helpers/output.h"
#include "../includes/sort.h"
#include "../includes/parse_targets.h"
#include "../includes/recursive_parse_targets.h"

char	**recursive_parse_targets(int ac, char **av)
{
  char	**targets_temp;
  char	**targets;
  int	i;
  int	dir_count;
  int	mem_size;

  i = 1;
  dir_count = 0;
  targets_temp = parse_targets(ac, av);
  if (count_array(targets_temp) == 1)
    how_many_folders_rec(&dir_count, ".");
  else
    {
      while (i < ac)
	{
	  if (av[i][0] != '-')
	    how_many_folders_rec(&dir_count, av[i]);
	  i = i + 1;
	}
    }
  mem_size = dir_count + ac + 1;
  targets = malloc(sizeof(char *) * mem_size);
  initiate_append(targets_temp, targets, ac, av);
  free(targets_temp);
  return (targets);
}

void	initiate_append(char **tmp, char **targets, int ac, char **av)
{
  int	i;
  int	i_targets;

  i = 1;
  i_targets = 0;
  if (count_array(tmp) == 1)
    {
      targets[i_targets] = "./";
      i_targets = i_targets + 1;
      append_folders_rec(targets, &i_targets, ".");
    }
  else
    {
      while (i < ac)
	{
	  if (av[i][0] != '-')
	    {
	      targets[i_targets] = av[i];
	      i_targets = i_targets + 1;
	      append_folders_rec(targets, &i_targets, av[i]);
	    }
	  i = i + 1;
	}
    }
  targets[i_targets] = 0;
}

void            append_folders_rec(char **targets, int *i, char *path)
{
  DIR           *dir;
  struct dirent *in_dir;

  dir = opendir(path);
  if (dir != 0)
    {
      while ((in_dir = readdir(dir)) != 0)
	{
	  if (in_dir->d_name[0] != '.' && in_dir->d_type == DT_DIR)
	    {
	      targets[*i] = get_path(path, in_dir->d_name);
	      *i = *i + 1;
	      append_folders_rec(targets, i, get_path(path, in_dir->d_name));
	    }
	}
      closedir(dir);
    }
}

void		how_many_folders_rec(int *count, char *path)
{
  DIR		*dir;
  struct dirent	*in_dir;

  dir = opendir(path);
  if (dir != 0)
    {
      while ((in_dir = readdir(dir)) != 0)
	{
	  if (in_dir->d_name[0] != '.' && in_dir->d_type == DT_DIR)
	    {
	      *count = *count + 1;
	      how_many_folders_rec(count, get_path(path, in_dir->d_name));
	    }
	}
      closedir(dir);
    }
}
