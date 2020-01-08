/*
** display.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Fri Dec  2 00:06:46 2016 Jérémy Sid Idris
** Last update Fri Dec  2 00:06:46 2016 Jérémy Sid Idris
*/

#ifndef DISPLAY_H_
# define DISPLAY_H_

#include "../../includes/t_file.h"
#include "../../includes/t_dir.h"
#include "t_flags.h"

void	display_file_array(t_file **file_array, t_flags *flags);
void	free_file(t_file *file);
void	show_file(t_flags *flags, t_file *file);
void	display_dir_array(t_dir **dir_array, t_flags *flags, char **tgc);
void	show_sufix_file(t_flags *flags, t_file *file);

#endif /* !DISPLAY_H_ */
