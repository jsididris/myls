/*
** t_file.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Nov 30 02:16:50 2016 Jérémy Sid Idris
** Last update Wed Nov 30 02:16:50 2016 Jérémy Sid Idris
*/

#ifndef T_FILE_H_
# define T_FILE_H_

typedef struct		s_file
{
  char			*path;
  char			*raw_path;
  char			*chmod;
  long int		links;
  char			*owner_user;
  char			*owner_group;
  long int		size;
  unsigned int		dev_major;
  unsigned int		dev_minor;
  char			*date;
  unsigned int		timestamp;
  long int		blocks;
}			t_file;

#endif /* !T_FILE_H_ */
