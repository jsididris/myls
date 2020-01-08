/*
** color.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/bonus
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Dec  5 00:31:47 2016 Jérémy Sid Idris
** Last update Mon Dec  5 00:31:47 2016 Jérémy Sid Idris
*/

#include "../includes/t_flags.h"
#include "../../includes/helpers/output.h"
#include "../includes/colors.h"

void	print_file_color(t_file *file, t_flags *flags)
{
  if (file->chmod[0] == 'd')
    my_putstr("\x1B[34m");
  else if (file->chmod[0] == 'l')
    my_putstr("\x1B[36m");
  else if (file->chmod[0] == 'p' || file->chmod[0] == 'b')
    my_putstr("\x1B[33m");
  else if (file->chmod[0] == 's')
    my_putstr("\x1B[35m");
  else if (file->chmod[9] == 'x' || file->chmod[9] == 't')
    my_putstr("\x1B[32m");
  my_putstr((flags->list ? file->path : file->raw_path));
  my_putstr("\x1B[0m");
}
