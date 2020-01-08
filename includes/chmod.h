/*
** chmod.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Nov 30 09:03:31 2016 Jérémy Sid Idris
** Last update Wed Nov 30 09:03:31 2016 Jérémy Sid Idris
*/

#ifndef CHMOD_H_
# define CHMOD_H_

char	*get_chmod(struct stat fs);
void	handle_special_bits(char *chmod, mode_t mode);
char	find_chmod_type(mode_t mode);

#endif /* !CHMOD_H_ */
