/*
** array.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sun Dec  4 15:04:48 2016 Jérémy Sid Idris
** Last update Sun Dec  4 15:04:48 2016 Jérémy Sid Idris
*/

#include "../includes/helpers/array.h"

int	count_array(char **array)
{
  int	i;

  i = 0;
  while (array[i] != 0)
    {
      i = i + 1;
    }
  return (i + 1);
}
