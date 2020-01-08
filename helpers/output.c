/*
** output.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Nov 29 23:37:46 2016 Jérémy Sid Idris
** Last update Tue Nov 29 23:37:46 2016 Jérémy Sid Idris
*/

#include <unistd.h>
#include "../includes/helpers/string.h"
#include "../includes/helpers/output.h"

void	print_error(char *str)
{
  write(2, str, my_strlen(str));
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putnbr(long long int number)
{
  int	i;
  char	tmp;

  if (number < 0)
    {
      my_putchar('-');
      number = number * -1;
    }
  i = count_nbr_digits(number);
  while (i >= 1)
    {
      tmp = (number / i) + '0';
      number = number % i;
      i = i / 10;
      my_putchar(tmp);
    }
}

long long int	count_nbr_digits(long long int number)
{
  long long int	i;

  i = 1;
  while ((number / i) >= 10)
    {
      i *= 10;
    }
  return (i);
}
