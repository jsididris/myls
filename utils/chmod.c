/*
** chmod.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/utils
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Nov 30 08:57:16 2016 Jérémy Sid Idris
** Last update Wed Nov 30 08:57:16 2016 Jérémy Sid Idris
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "../includes/helpers/output.h"
#include "../includes/chmod.h"

char	*get_chmod(struct stat fs)
{
  char	*chmod;

  chmod = malloc(sizeof(char) * 11);
  if (chmod == 0)
    {
      print_error("Malloc failed :(");
      exit(84);
    }
  chmod[0] = find_chmod_type(fs.st_mode);
  chmod[1] = (fs.st_mode & S_IRUSR ? 'r' : '-');
  chmod[2] = (fs.st_mode & S_IWUSR ? 'w' : '-');
  chmod[3] = (fs.st_mode & S_IXUSR ? 'x' : '-');
  chmod[4] = (fs.st_mode & S_IRGRP ? 'r' : '-');
  chmod[5] = (fs.st_mode & S_IWGRP ? 'w' : '-');
  chmod[6] = (fs.st_mode & S_IXGRP ? 'x' : '-');
  chmod[7] = (fs.st_mode & S_IROTH ? 'r' : '-');
  chmod[8] = (fs.st_mode & S_IWOTH ? 'w' : '-');
  chmod[9] = (fs.st_mode & S_IXOTH ? 'x' : '-');
  chmod[10] = '\0';
  handle_special_bits(chmod, fs.st_mode);
  return (chmod);
}

void	handle_special_bits(char *chmod, mode_t mode)
{
  chmod[3] = (mode & S_ISUID && chmod[3] == 'x' ? 's' : chmod[3]);
  chmod[3] = (mode & S_ISUID && chmod[3] != 's' ? 'S' : chmod[3]);
  chmod[6] = (mode & S_ISGID && chmod[6] == 'x' ? 's' : chmod[6]);
  chmod[6] = (mode & S_ISGID && chmod[6] != 's' ? 'S' : chmod[6]);
  chmod[9] = (mode & S_ISVTX && chmod[9] == 'x' ? 't' : chmod[9]);
  chmod[9] = (mode & S_ISVTX && chmod[9] != 't' ? 'T' : chmod[9]);
}

char	find_chmod_type(mode_t mode)
{
  if (S_ISDIR(mode))
    return ('d');
  if (S_ISBLK(mode))
    return ('b');
  if (S_ISCHR(mode))
    return ('c');
  if (S_ISFIFO(mode))
    return ('p');
  if (S_ISSOCK(mode))
    return ('s');
  if (S_ISLNK(mode))
    return ('l');
  return ('-');
}
