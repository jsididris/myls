/*
** t_dir.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Thu Dec  1 21:17:07 2016 Jérémy Sid Idris
** Last update Thu Dec  1 21:17:07 2016 Jérémy Sid Idris
*/

#ifndef T_DIR_H_
# define T_DIR_H_

typedef struct		s_dir
{
  char			*path;
  unsigned long long	size;
  t_file		**files;
}			t_dir;

#endif /* !T_DIR_H_ */
