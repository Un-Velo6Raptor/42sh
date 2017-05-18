/*
** my_putstr.c for  in /home/januar_m/delivery/PSU/edit_line
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 17 15:36:45 2017 Martin Januario
** Last update Wed May 17 16:02:51 2017 Martin Januario
*/

#include	<unistd.h>
#include	"edit.h"

int		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}

int		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  return (84);
}
