/*
** my_realloc.c for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 10 14:26:27 2017 Martin Januario
** Last update Fri May 12 17:37:51 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

char		*my_realloc(char *str, char *add_str)
{
  char		*new_str;
  int		idx;
  int		idx2;

  idx = 0;
  idx2 = 0;
  if ((new_str = malloc(my_strlen(str) + my_strlen(add_str) + 3)) == NULL)
    return (NULL);
  while (str != NULL && str[idx] != '\0')
    {
      new_str[idx] = str[idx];
      idx++;
    }
  while (add_str != NULL && add_str[idx2] != '\0')
    {
      new_str[idx + idx2] = add_str[idx2];
      idx2++;
    }
  new_str[idx + idx2] = '\0';
  my_free(str);
  return (new_str);
}

char		*my_realloc_idx(char *str, char *add_str, int max)
{
  char		*new_str;
  int		idx[2];

  idx[0] = 0;
  idx[1] = 0;
  if ((new_str = malloc(my_strlen(str) + my_strlen(add_str) + 3)) == NULL)
    return (NULL);
  while (str != NULL && str[idx[0]] != '\0' && idx[0] < max - 1)
    {
      new_str[idx[0]] = str[idx[0]];
      idx[0]++;
    }
  while (add_str != NULL && add_str[idx[1]] != '\0')
    {
      new_str[idx[0] + idx[1]] = add_str[idx[1]];
      idx[1]++;
    }
  while (str != NULL && str[idx[0]] != '\0')
    {
      new_str[idx[0] + idx[1]] = str[idx[0]];
      idx[0]++;
    }
  new_str[idx[0] + idx[1]] = '\0';
  my_free(str);
  return (new_str);
}

char		*my_realloc_sup(char *str, int tmp, int opt)
{
  char		*new_str;
  int		idx;
  int		check;

  idx = 0;
  check = 0;
  (void) opt;
  if ((new_str = malloc(my_strlen(str) + 3)) == NULL)
    return (NULL);
  while (str != NULL && str[idx] != '\0' && str[idx + check] != '\0')
    {
      if (idx == tmp)
	check = 1;
      new_str[idx] = str[idx + check];
      idx++;
    }
  new_str[idx] = '\0';
  my_free(str);
  return (new_str);
}
