/*
** string.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Nov 29 23:39:23 2016 Jérémy Sid Idris
** Last update Tue Nov 29 23:39:23 2016 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "../includes/helpers/output.h"
#include "../includes/helpers/string.h"

int	my_strlen(char *str)
{
  int	count;

  count = 0;
  while (*str != 0)
    {
      count = count + 1;
      str = str + 1;
    }
  return (count);
}

char	*my_strdup(char *src)
{
  int	i;
  char	*result;

  i = 0;
  result = malloc(sizeof(char) * my_strlen(src) + 1);
  if (result == 0)
    {
      print_error("Malloc failed :(");
      exit(84);
    }
  while (i < my_strlen(src))
    {
      result[i] = src[i];
      i = i + 1;
    }
  result[i] = 0;
  return (result);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str1[i] != 0)
    i = i + 1;
  return (str1[i] - str2[i]);
}
