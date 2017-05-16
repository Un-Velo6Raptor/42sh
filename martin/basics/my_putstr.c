/*
** my_putstr.c for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 10 15:04:18 2017 Martin Januario
** Last update Fri May 12 12:29:34 2017 Martin Januario
*/

#include	<unistd.h>
#include	"my.h"

int		my_puterror(char *str)
{
  if (str != NULL)
    write(2, str, my_strlen(str));
  return (84);
}

int		my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
  return (0);
}
