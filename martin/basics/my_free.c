/*
** my_free.c for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 10 14:23:43 2017 Martin Januario
** Last update Wed May 10 14:24:19 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

void		my_free(char *str)
{
  if (str != NULL)
    free(str);
  str = NULL;
}
