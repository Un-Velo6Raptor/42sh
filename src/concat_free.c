/*
** concat_free.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed Apr  5 20:14:48 2017 Sahel Lucas--Saoudi
** Last update Thu May 11 15:40:45 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include <unistd.h>
#include "basic.h"

char	*concat_free(char *str1, char *str2)
{
  char	*new;
  int	str_i[2];

  if (str1 && str2)
    new = malloc(strlen_(str1) + strlen_(str2) + 1);
  else
    new = malloc(strlen_((str1) ? (str1) : (str2)) + 1);
  if (!new)
    return (NULL);
  str_i[0] = 0;
  str_i[1] = 0;
  while (str1 && str1[str_i[0]])
    {
      new[str_i[0]] = str1[str_i[0]];
      str_i[0]++;
    }
  while (str2 && str2[str_i[1]])
    {
      new[str_i[0] + str_i[1]] = str2[str_i[1]];
      str_i[1]++;
    }
  new[str_i[0] + str_i[1]] = '\0';
  free_(str1);
  return (new);
}
