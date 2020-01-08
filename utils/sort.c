/*
** sort.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/utils
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sun Dec  4 02:55:33 2016 Jérémy Sid Idris
** Last update Sun Dec  4 02:55:33 2016 Jérémy Sid Idris
*/

#include "../includes/helpers/string.h"
#include "../includes/t_file.h"
#include "../includes/sort.h"

t_file		**sort_asc_by_name(t_file **unsorted_files)
{
  int		i;
  int		n;
  t_file	*temp;

  i = 0;
  while (unsorted_files[i] != 0)
    {
      n = 0;
      while (unsorted_files[n] != 0)
	{
	  if (my_strcmp(unsorted_files[i]->path, unsorted_files[n]->path) < 1)
	    {
	      temp = unsorted_files[i];
	      unsorted_files[i] = unsorted_files[n];
	      unsorted_files[n] = temp;
	    }
	  n = n + 1;
	}
      i = i + 1;
    }
  return (unsorted_files);
}

t_file		**sort_desc_by_name(t_file **unsorted_files)
{
  int		i;
  int		n;
  t_file	*temp;

  i = 0;
  while (unsorted_files[i] != 0)
    {
      n = 0;
      while (unsorted_files[n] != 0)
	{
	  if (my_strcmp(unsorted_files[i]->path, unsorted_files[n]->path) >= 1)
	    {
	      temp = unsorted_files[i];
	      unsorted_files[i] = unsorted_files[n];
	      unsorted_files[n] = temp;
	    }
	  n = n + 1;
	}
      i = i + 1;
    }
  return (unsorted_files);
}

t_file		**sort_asc_by_mod_ts(t_file **unsorted_files)
{
  int		i;
  int		n;
  t_file	*temp;

  unsorted_files = sort_desc_by_name(unsorted_files);
  i = 0;
  while (unsorted_files[i] != 0)
    {
      n = 0;
      while (unsorted_files[n] != 0)
	{
	  if (unsorted_files[i]->timestamp < unsorted_files[n]->timestamp)
	    {
	      temp = unsorted_files[i];
	      unsorted_files[i] = unsorted_files[n];
	      unsorted_files[n] = temp;
	    }
	  n = n + 1;
	}
      i = i + 1;
    }
  return (unsorted_files);
}

t_file		**sort_desc_by_mod_ts(t_file **unsorted_files)
{
  int		i;
  int		n;
  t_file	*temp;

  unsorted_files = sort_asc_by_name(unsorted_files);
  i = 0;
  while (unsorted_files[i] != 0)
    {
      n = 0;
      while (unsorted_files[n] != 0)
	{
	  if (unsorted_files[i]->timestamp >= unsorted_files[n]->timestamp)
	    {
	      temp = unsorted_files[i];
	      unsorted_files[i] = unsorted_files[n];
	      unsorted_files[n] = temp;
	    }
	  n = n + 1;
	}
      i = i + 1;
    }
  return (unsorted_files);
}
