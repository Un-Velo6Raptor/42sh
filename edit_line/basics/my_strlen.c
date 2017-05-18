/*
** my_strlen.c for  in /home/januar_m/delivery/PSU/edit_line
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 17 15:37:46 2017 Martin Januario
** Last update Wed May 17 15:38:20 2017 Martin Januario
*/

#include	<stdlib.h>

int		my_strlen(char *str)
{
  int		idx;

  idx = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0')
    idx++;
  return (idx);
}
