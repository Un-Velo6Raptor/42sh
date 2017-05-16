/*
** is_a_key.c for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 12 14:17:32 2017 Martin Januario
** Last update Tue May 16 13:10:27 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		is_not_a_key(char **str, char **tmp, int *idx, t_key *keys)
{
  if ((*str = my_realloc_idx(*str, *tmp, *idx)) == NULL)
    return (84);
  *idx += 1 + my_strlen(*tmp);
  *tmp = my_reset(*tmp, keys);
  return (0);
}

int		is_a_key(t_key *keys, char **tmp, int *idx, char **str)
{
  int		index;

  index = 0;
  if ((*tmp = my_realloc(*tmp, keys->c)) == NULL)
    return (84);
  if ((index = same_key(keys, *tmp, idx)) != -42)
    {
      if (index == 2)
	{
	  *str = my_realloc_sup(*str, *idx, 0);
	  keys->width -= 1;
	}
      else if (index == 3)
	{
	  *str = my_realloc_sup(*str, *idx - 1, 1);
	  *idx -= 1;
	  keys->width -= 1;
	}
      else if (*idx + index >= 0 && *idx + index <= keys->width)
	*idx += index;
      *tmp = my_reset(*tmp, keys);
    }
  return (0);
}
