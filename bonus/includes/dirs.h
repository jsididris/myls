/*
** dirs.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Thu Dec  1 21:32:59 2016 Jérémy Sid Idris
** Last update Thu Dec  1 21:32:59 2016 Jérémy Sid Idris
*/

#ifndef DIRS_H_
# define DIRS_H_

#include <dirent.h>
#include "t_flags.h"
#include "../../includes/t_dir.h"

t_dir	*to_dir(char *target, DIR *opened_dir, t_flags *flags);
int	how_many_files_in_dir(DIR *dir);
char	*init_get_path(int *size, int dir_size, int file_size, int *i);
char	*get_path(char *directory, char *filename);
void	iterate_dir(char *t, DIR *dir, t_file **array, long long *bloc);
void	it_h_dir(char *t, DIR *dir, t_file **array, long long *bloc);

#endif /* !DIRS_H_ */
