/*
** recursive_parse_targets.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sun Dec  4 13:11:30 2016 Jérémy Sid Idris
** Last update Sun Dec  4 13:11:30 2016 Jérémy Sid Idris
*/

#ifndef RECURSIVE_PARSE_TARGETS_H_
# define RECURSIVE_PARSE_TARGETS_H_

char	**recursive_parse_targets(int ac, char **av);
void	initiate_append(char **tmp, char **targets, int ac, char **av);
void	append_folders_rec(char **targets, int *i, char *path);
void	how_many_folders_rec(int *count, char *path);

#endif /* !RECURSIVE_PARSE_TARGETS_H_ */
