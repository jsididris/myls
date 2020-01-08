/*
** date.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/utils
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Dec  3 14:00:19 2016 Jérémy Sid Idris
** Last update Sat Dec  3 14:00:19 2016 Jérémy Sid Idris
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/helpers/string.h"
#include "../includes/helpers/output.h"
#include "../includes/date.h"

char	*get_formated_date(time_t date)
{
  char	*formated_date;
  char	*str_date;
  char	*copy_str_date;
  int	i;

  formated_date = malloc(sizeof(char) * 13);
  str_date = my_strdup(ctime(&date));
  copy_str_date = str_date;
  i = 0;
  if (formated_date == 0)
    {
      print_error("Malloc failed :(");
      exit(84);
    }
  str_date = str_date + 4;
  while (*str_date != 0)
    {
      handle_make_date(&i, date, formated_date, &str_date);
      str_date = str_date + 1;
    }
  formated_date[i] = 0;
  free(copy_str_date);
  return (formated_date);
}

void	handle_make_date(int *i, time_t date, char *formated_date, char **dt)
{
  if (*i >= 6 && *i < 12)
    {
      if (!is_special_time(date))
	{
	  formated_date[*i] = **dt;
	  *i = *i + 1;
	}
      else
	{
	  if (*i == 6)
	    {
	      formated_date[*i] = ' ';
	      *dt = *dt + 8;
	    }
	  else
	    formated_date[*i] = **dt;
	  *i = *i + 1;
	}
    }
  if (*i < 6)
    {
      formated_date[*i] = **dt;
      *i = *i + 1;
    }
}

int		is_special_time(time_t date)
{
  time_t	current_date;
  time_t	diff;

  current_date = time(0);
  diff = current_date - date;
  if (diff >= 15552000 || diff < 0)
    return (1);
  return (0);
}
