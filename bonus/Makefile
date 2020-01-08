##
## Makefile for my_ls in /home/jeremy/Delivery/PSU_2016_my_ls
## 
## Made by Jérémy Sid Idris
## Login   <jeremy.sid-idris@epitech.eu>
## 
## Started on  Tue Nov 29 22:58:08 2016 Jérémy Sid Idris
## Last update Tue Nov 29 22:58:08 2016 Jérémy Sid Idris
##

SRC     =       ../helpers/string.c			\
		../helpers/output.c			\
		../helpers/array.c			\
		parsers/flags.c				\
		../parsers/targets.c			\
		../parsers/recursive_targets.c		\
		../utils/error.c			\
		../utils/chmod.c			\
		../utils/date.c				\
		utils/display.c				\
		utils/colors.c				\
		../utils/sort.c				\
		files.c					\
		dirs.c					\
		dirs_2.c				\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls_bonus

CFLAGS  +=      -Wextra -Wall -Werror

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

$(NAME):	$(OBJ)
	gcc -g -o $(NAME) $(OBJ)

.PHONY: all clean fclean re
