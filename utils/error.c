/*
** error.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/utils
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Nov 30 12:53:55 2016 Jérémy Sid Idris
** Last update Wed Nov 30 12:53:55 2016 Jérémy Sid Idris
*/

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/helpers/output.h"
#include "../includes/error.h"

void	display_error_open_target(char *binary, char *target)
{
  print_error(binary);
  print_error(": cannot access '");
  print_error(target);
  perror("'");
}

void	display_bad_usage_error(char *binary, char context)
{
  print_error(binary);
  print_error(": invalid option -- '");
  print_error(&context);
  print_error("'\n");
  print_error("Try ");
  print_error(binary);
  print_error(" --help' for more information.\n");
  exit(84);
}
