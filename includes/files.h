/*
** files.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Nov 30 09:04:18 2016 Jérémy Sid Idris
** Last update Wed Nov 30 09:04:18 2016 Jérémy Sid Idris
*/

#ifndef FILES_H_
# define FILES_H_

#include "t_file.h"

t_file	*to_file(char *target, char *real_name);
void	get_device_data(dev_t dev, t_file *file);
char	*get_symlink(char *path, char *real_name);
void	get_symlink2(char *f_path, int *i, char *b_path, int plength);

#endif /* !FILES_H_ */
