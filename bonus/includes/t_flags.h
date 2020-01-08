/*
** t_flags.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Nov 29 23:00:46 2016 Jérémy Sid Idris
** Last update Tue Nov 29 23:00:46 2016 Jérémy Sid Idris
*/

#ifndef T_FLAGS_H_
# define T_FLAGS_H_

typedef struct		s_flags
{
  int			list;
  int			reverse;
  int			recursive;
  int			dir_list;
  int			time_sort;
  int			asort;
  int			no_sort;
  int			hidden;
  int			sufixed;
}			t_flags;

#endif /* !T_FLAGS_H_ */
