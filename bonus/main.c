/*
** main.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Nov 29 22:59:06 2016 Jérémy Sid Idris
** Last update Tue Nov 29 22:59:06 2016 Jérémy Sid Idris
*/

#include <errno.h>
#include <dirent.h>
#include <stdlib.h>
#include "../includes/error.h"
#include "includes/files.h"
#include "includes/dirs.h"
#include "../includes/display.h"
#include "../includes/helpers/output.h"
#include "../includes/helpers/array.h"
#include "includes/parse_flags.h"
#include "../includes/parse_targets.h"
#include "../includes/recursive_parse_targets.h"
#include "includes/t_flags.h"
#include "../includes/t_file.h"
#include "../includes/t_dir.h"
#include "../includes/my_ls.h"

int		main(int argc, char **argv)
{
  t_flags	*flags;
  char		error_context;
  char		**targets;
  char		**targets_copy;
  t_file	**file_array;
  t_dir		**dir_array;

  flags = parse_flags(argc, argv, &error_context);
  if (flags == 0)
    display_bad_usage_error(argv[0], error_context);
  if (flags->recursive == 0)
    targets = parse_targets(argc, argv);
  else
    targets = recursive_parse_targets(argc, argv);
  targets = (count_array(targets) == 1 ? handle_none_targets() : targets);
  targets_copy = targets;
  file_array = malloc(sizeof(t_file *) * (argc + 10));
  dir_array = malloc(sizeof(t_dir *) * count_array(targets));
  handle_targets(targets, flags, file_array, dir_array);
  display_file_array(file_array, flags);
  display_dir_array(dir_array, flags, targets_copy);
  free_all(file_array, dir_array, flags, targets_copy);
  return (0);
}

void	handle_targets(char **tg, t_flags *flags, t_file **f_a, t_dir **d_a)
{
  int	i_files;
  int	i_dirs;
  DIR	*cur_dir;

  init_targets_counters(&i_files, &i_dirs, &cur_dir);
  while (*tg != 0)
    {
      cur_dir = opendir(*tg);
      if (flags->dir_list || cur_dir == 0)
	try_targets_as_file(flags, f_a, &i_files, tg);
      else
	{
	  d_a[i_dirs] = to_dir(*tg, cur_dir, flags);
	  i_dirs = i_dirs + 1;
	}
      tg = tg + 1;
      closedir(cur_dir);
      errno = 0;
    }
  f_a[i_files] = 0;
  d_a[i_dirs] = 0;
}

void	try_targets_as_file(t_flags *flags, t_file **f_a, int *i, char **tg)
{
  if ((flags->dir_list && errno == 0) || errno == 20)
    {
      f_a[*i] = to_file(*tg, *tg, flags);
      *i = *i + 1;
    }
  else
    display_error_open_target("my_ls", *tg);
}

void	init_targets_counters(int *i_files, int *i_dirs, DIR **cur_dir)
{
  *cur_dir = 0;
  *i_files = 0;
  *i_dirs = 0;
}

void	free_all(t_file **file_a, t_dir **dir_a, t_flags *flags, char **tg)
{
  free(file_a);
  free(dir_a);
  free(flags);
  free(tg);
}
