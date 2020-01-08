/*
** sort.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sun Dec  4 02:53:47 2016 Jérémy Sid Idris
** Last update Sun Dec  4 02:53:47 2016 Jérémy Sid Idris
*/

#ifndef SORT_H_
# define SORT_H_

#include "t_file.h"

t_file	**sort_asc_by_name(t_file **unsorted_files);
t_file	**sort_desc_by_name(t_file **unsorted_files);
t_file	**sort_asc_by_mod_ts(t_file **unsorted_files);
t_file	**sort_desc_by_mod_ts(t_file **unsorted_files);

#endif /* !SORT_H_ */
