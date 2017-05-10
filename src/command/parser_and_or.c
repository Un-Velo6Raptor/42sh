/*
** parser_and_or.c for PSU_2016_42sh in /home/shintaro/Work/Epitech/delivery/PSU_2016_42sh
**
** Made by Thomas GRANDJEAN
** Login   <thomas.grandjean@epitech.eu>
**
** Started on  Wed May 10 15:10:32 2017 Thomas GRANDJEAN
** Last update Wed May 10 15:10:32 2017 Thomas GRANDJEAN
*/

#include	<stdlib.h>
#include "basic.h"

static int	count_arg(char *str)
{
  int		i;
  int		amount;

  amount = 1;
  i = 0;
  while (str[i] != '\0')
  {
    if ((str[i] == '|' || str[i] == '&') && str[i + 1] == str[i])
    {
      amount += 1;
      i += 1;
    }
    i += 1;
  }
  return (amount * 2);
}

static char	*get_(char *str, int *i)
{
  int		j;

  j = 0;
  while (str[j] && (match(&str[j], "||*") == 0 || (match(&str[j], "&&*") == 0)))
    j += 1;
  if (str[j] != '\0')
    str[j + 1] = '\0';
  *i += j;
  return (str);
}

char		**parse_and_or(char *str)
{
  int		amount;
  char		**new;
  int		i;
  int		j;

  j = 0;
  i = 0;
  amount = count_arg(str);
  new = malloc(sizeof(char *) * amount);
  if (!new)
    return (NULL);
  while (i < amount -1)
  {
    new[i] = get_(strdup_(&str[j]), &j);
    if (str[j] && str[j + 1] == '|')
	 new[i + 1] = strdup_("||");
    if (str[j] && str[j + 1] == '&')
	 new[i + 1] = strdup_("&&");
    j += 3;
    i += 2;
  }
  new[i - 1] = NULL;
  return (new);
}
