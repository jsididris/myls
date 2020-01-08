/*
** my_ls.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Nov 29 23:49:28 2016 Jérémy Sid Idris
** Last update Tue Nov 29 23:49:28 2016 Jérémy Sid Idris
*/

#ifndef MY_LS_H_
# define MY_LS_H_

#include <dirent.h>
#include "files.h"

t_file	*handle_open_file(char *, char *, t_flags *, DIR *);
void	handle_targets(char **, t_flags *, t_file **, t_dir **);
void	init_targets_counters(int *i_files, int *i_dirs, DIR **cur_dir);
void	try_targets_as_file(t_flags *, t_file **, int *, char **);
void	free_all(t_file **file_a, t_dir **dir_a, t_flags *flags, char **tg);

#endif /* !MY_LS_H_ */
