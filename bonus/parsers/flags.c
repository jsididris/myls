/*
** flags.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/parsers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Nov 29 23:58:18 2016 Jérémy Sid Idris
** Last update Tue Nov 29 23:58:18 2016 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "../../includes/helpers/output.h"
#include "../includes/t_flags.h"
#include "../includes/parse_flags.h"

t_flags		*parse_flags(int ac, char **av, char *error_context)
{
  t_flags	*flags;
  int		i;
  int		n;

  flags = init_flags();
  i = 0;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  n = 1;
	  while (av[i][n] != 0)
	    {
	      if ((flags = populate_flags(flags, av[i][n], error_context)) == 0)
		return (0);
	      n = n + 1;
	    }
	}
      i = i + 1;
    }
  return (flags);
}

t_flags	*populate_flags(t_flags *flags, char c, char *err)
{
  if (is_flag(c))
    {
      flags->list = (c == 'l' ? 1 : flags->list);
      flags->reverse = (c == 'r' ? 1 : flags->reverse);
      flags->recursive = (c == 'R' ? 1 : flags->recursive);
      flags->dir_list = (c == 'd' ? 1 : flags->dir_list);
      flags->time_sort = (c == 't' || c == 'u' ? 1 : flags->time_sort);
      flags->no_sort = (c == 'U' || c == 'f' ? 1 : flags->no_sort);
      flags->hidden = (c == 'a' || c == 'f' ? 1 : flags->hidden);
      flags->asort = (c == 'u' ? 1 : flags->asort);
      flags->sufixed = (c == 'F' ? 1 : flags->sufixed);
    }
  else
    {
      *err = c;
      return (0);
    }
  return (flags);
}

t_flags		*init_flags()
{
  t_flags	*flags;

  flags = malloc(sizeof(t_flags));
  if (flags == 0)
    {
      print_error("Malloc failed :(");
      exit(84);
    }
  flags->list = 0;
  flags->reverse = 0;
  flags->recursive = 0;
  flags->dir_list = 0;
  flags->time_sort = 0;
  flags->no_sort = 0;
  flags->asort = 0;
  flags->hidden = 0;
  flags->sufixed = 0;
  return (flags);
}

int	is_flag(char c)
{
  return (c == 'l' ||
	  c == 'r' ||
	  c == 'R' ||
	  c == 'd' ||
	  c == 'a' ||
	  c == 'u' ||
	  c == 'U' ||
	  c == 'f' ||
	  c == 'F' ||
	  c == 't');
}
