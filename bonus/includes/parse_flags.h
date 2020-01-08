/*
** parse_flags.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Nov 30 00:00:08 2016 Jérémy Sid Idris
** Last update Wed Nov 30 00:00:08 2016 Jérémy Sid Idris
*/

#ifndef PARSE_FLAGS_H_
# define PARSE_FLAGS_H_

#include "t_flags.h"

t_flags	*parse_flags(int ac, char **av, char *err_context);
t_flags	*populate_flags(t_flags *flags, char c, char *err);
t_flags	*init_flags();
int	is_flag(char c);

#endif /* !PARSE_FLAGS_H_ */
