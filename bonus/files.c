/*
** files.c for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Nov 30 02:19:28 2016 Jérémy Sid Idris
** Last update Wed Nov 30 02:19:28 2016 Jérémy Sid Idris
*/

#include <linux/limits.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../includes/helpers/output.h"
#include "../includes/helpers/string.h"
#include "../includes/t_file.h"
#include "../includes/chmod.h"
#include "../includes/date.h"
#include "includes/t_flags.h"
#include "includes/files.h"

t_file		*to_file(char *target, char *name, t_flags *flags)
{
  t_file	*file;
  struct stat	fs;
  struct passwd	*owner_pwd;
  struct group	*owner_group;

  file = malloc(sizeof(t_file));
  if (file == 0 || (lstat(target, &fs) == -1))
    {
      print_error((file == 0 ? "Malloc failed :(" : "Stat failed :/"));
      exit(84);
    }
  owner_pwd = getpwuid(fs.st_uid);
  owner_group = getgrgid(fs.st_gid);
  file->chmod = get_chmod(fs);
  file->links = fs.st_nlink;
  file->owner_user = my_strdup(owner_pwd->pw_name);
  file->owner_group = my_strdup(owner_group->gr_name);
  file->size = fs.st_size;
  file->date = get_formated_date(fs.st_mtime);
  file->timestamp = (unsigned int)((flags->asort ? fs.st_atime : fs.st_mtime));
  file->blocks = fs.st_blocks;
  file->path = (file->chmod[0] == 'l' ? get_symlink(target, name) : name);
  file->raw_path = name;
  get_device_data(fs.st_rdev, file);
  return (file);
}

void	get_device_data(dev_t dev, t_file *file)
{
  file->dev_major = ((dev >> 8) & 0xfff) | ((dev >> 32) & ~0xfff);
  file->dev_minor = (dev & 0xff) | ((dev >> 12) & ~0xff);
}

char	*get_symlink(char *path, char *real_name)
{
  char	buffer_path[PATH_MAX];
  char	*final_path;
  int	path_length;
  int	i;

  i = 0;
  if ((path_length = readlink(path, buffer_path, PATH_MAX)) == -1)
    return (real_name);
  final_path = malloc(sizeof(char) * (my_strlen(real_name) + PATH_MAX) + 5);
  if (final_path == 0)
    return (real_name);
  while (*real_name != 0)
    {
      final_path[i] = *real_name;
      i = i + 1;
      real_name = real_name + 1;
    }
  get_symlink2(final_path, &i, buffer_path, path_length);
  return (final_path);
}

void	get_symlink2(char *final_path, int *i, char *buffer_path, int plength)
{
  int	i_buffer;

  i_buffer = 0;
  final_path[*i] = ' ';
  final_path[*i + 1] = '-';
  final_path[*i + 2] = '>';
  final_path[*i + 3] = ' ';
  *i = *i + 4;
  while (i_buffer < plength)
    {
      final_path[*i] = buffer_path[i_buffer];
      *i = *i + 1;
      i_buffer = i_buffer + 1;
    }
  final_path[*i] = 0;
}
