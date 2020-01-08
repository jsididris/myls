/*
** date.h for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls/includes
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Dec  3 14:17:35 2016 Jérémy Sid Idris
** Last update Sat Dec  3 14:17:35 2016 Jérémy Sid Idris
*/

#ifndef DATE_H_
# define DATE_H_

char	*get_formated_date(time_t date);
void	handle_make_date(int *i, time_t date, char *f_date, char **r_date);
int	is_special_time(time_t date);

#endif /* !DATE_H_ */
