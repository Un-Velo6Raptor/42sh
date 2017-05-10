/*
** double_redir.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed Apr  5 20:18:54 2017 Sahel Lucas--Saoudi
** Last update Sat Apr  8 15:15:50 2017 Sahel Lucas--Saoudi
*/

#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "basic.h"

char	*stralloc_(char *str, char *s2)
{
  char	*ret;
  int	str_i;
  int	str_j;

  str_i = 0;
  str_j = 0;
  if (!(ret = malloc((str) ? (strlen_(str) + strlen_(s2) + 1) :
		     (strlen_(s2) + 1))))
    return (NULL);
  while (str && str[str_i])
    {
      ret[str_i] = str[str_i];
      str_i++;
    }
  while (s2 && s2[str_j])
    {
      ret[str_i + str_j] = s2[str_j];
      str_j++;
    }
  ret[str_i + str_j] = '\0';
  return (ret);
}

char	*double_redir(char *word)
{
  char	*buffer;
  char	*ret;

  ret = NULL;
  if (isatty(0) == 1)
    putstr_("heredoc >", 1);
  while ((buffer = getnextline_(0)))
    {
      if (match(buffer, word))
	return (ret);
      ret = stralloc_(ret, buffer);
      ret = stralloc_(ret, "\n");
      free_(buffer);
      if (isatty(0) == 1)
	putstr_("heredoc >", 1);
    }
  return (NULL);
}