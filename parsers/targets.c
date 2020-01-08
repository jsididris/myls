/*
** parse_targets.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/parsers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Nov 30 01:32:42 2016 Jérémy Sid Idris
** Last update Wed Nov 30 01:32:42 2016 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "../includes/helpers/output.h"
#include "../includes/parse_targets.h"

char	**parse_targets(int ac, char **av)
{
  char	**targets;
  int	i;
  int	i_targets;

  targets = malloc(sizeof(char *) * ac);
  if (targets == 0)
    {
      print_error("Malloc failed :(");
      exit(84);
    }
  i = 1;
  i_targets = 0;
  while (i < ac)
    {
      if (av[i][0] != '-')
	{
	  targets[i_targets] = av[i];
	  i_targets = i_targets + 1;
	}
      i = i + 1;
    }
  targets[i_targets] = 0;
  return (targets);
}

char	**handle_none_targets()
{
  char	**targets;

  targets = malloc(sizeof(char *) * 2);
  targets[0] = malloc(sizeof(char) * 3);
  targets[0][0] = '.';
  targets[0][1] = '/';
  targets[0][2] = 0;
  targets[1] = 0;
  return (targets);
}
