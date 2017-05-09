/*
** dico.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Sat Mar 25 12:55:41 2017 Sahel Lucas--Saoudi
** Last update Sat Apr  8 17:11:52 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include <stdarg.h>
#include "basic.h"

char		**c_dico(int nb_arg, ...)
{
  char		**dico;
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, nb_arg);
  dico = malloc(sizeof(char *) * (nb_arg + 1));
  if (!dico)
    return (NULL);
  while (i < nb_arg)
    {
      dico[i] = va_arg(ap, char *);
      i++;
    }
  dico[i] = NULL;
  return (dico);
}

int	howmany_(char *str, char c)
{
  int	str_i;
  int	nb;

  str_i = 0;
  nb = 0;
  while (str && str[str_i])
    {
      if (str[str_i] == c)
	nb++;
      str_i++;
    }
  return (nb);
}
