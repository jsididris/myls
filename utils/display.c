/*
** display.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/utils
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Fri Dec  2 00:03:38 2016 Jérémy Sid Idris
** Last update Fri Dec  2 00:03:38 2016 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "../includes/helpers/output.h"
#include "../includes/helpers/array.h"
#include "../includes/sort.h"
#include "../includes/t_file.h"
#include "../includes/t_dir.h"
#include "../includes/t_flags.h"
#include "../includes/display.h"

void	display_file_array(t_file **file_array, t_flags *flags)
{
  int	i;

  i = 0;
  if (flags->time_sort)
    {
      if (flags->reverse)
	file_array = sort_asc_by_mod_ts(file_array);
      else
	file_array = sort_desc_by_mod_ts(file_array);
    }
  else
    {
      if (flags->reverse)
	file_array = sort_desc_by_name(file_array);
      else
	file_array = sort_asc_by_name(file_array);
    }
  while (file_array[i] != 0)
    {
      show_file(flags, file_array[i]);
      free_file(file_array[i]);
      i = i + 1;
    }
}

void	free_file(t_file *file)
{
  free(file->owner_user);
  free(file->owner_group);
  free(file->chmod);
  free(file->date);
  free(file);
}

void	show_file(t_flags *flags, t_file *file)
{
  if (flags->list)
    {
      my_putstr(file->chmod);
      my_putstr(" ");
      my_putnbr(file->links);
      my_putstr(" ");
      my_putstr(file->owner_user);
      my_putstr(" ");
      my_putstr(file->owner_group);
      my_putstr(" ");
      if (file->chmod[0] == 'c' || file->chmod[0] == 'b')
	{
	  my_putnbr(file->dev_major);
	  my_putstr(", ");
	  my_putnbr(file->dev_minor);
	}
      else
	my_putnbr(file->size);
      my_putstr(" ");
      my_putstr(file->date);
      my_putstr(" ");
    }
  my_putstr((flags->list ? file->path : file->raw_path));
  my_putstr("\n");
}

void	display_dir_array(t_dir **dir_array, t_flags *flags, char **tgc)
{
  int	i;

  i = 0;
  while (dir_array[i] != 0)
    {
      if (count_array(tgc) > 2)
	{
	  my_putstr(dir_array[i]->path);
	  my_putstr(":\n");
	}
      if (flags->list)
	{
	  my_putstr("total ");
	  my_putnbr(dir_array[i]->size);
	  my_putchar('\n');
	}
      display_file_array(dir_array[i]->files, flags);
      free(dir_array[i]->files);
      free(dir_array[i]);
      i = i + 1;
      if (dir_array[i] != 0)
	my_putchar('\n');
    }
}
