/*
** check_is_key.c for  in /home/januar_m/delivery/PSU/edit_line
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 17 16:52:39 2017 Martin Januario
** Last update Thu May 18 20:46:30 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<string.h>
#include	"edit.h"

int		check_is_key(t_key *keys, char *str, char *line)
{
  void		(*key_code[10])(t_key *, char *, char *) = {key_left_, key_right_,
							    key_top_, key_bottom_,
							    key_sup_, key_begin_,
							    key_end_, key_sleft_,
							    key_sright_, key_del_};
  int		idx;

  idx = 0;
  if (my_strlen(str) == 1 && str[0] == 4)
    return (1);
  if (my_strlen(str) == 1 && str[0] == '\t')
    {
      str[0] = ' ';
      return (0);
    }
  while (keys->key[idx] != NULL)
    {
      if (strcmp(keys->key[idx], str) == 0)
	{
	  key_code[idx](keys, str, line);
	  return (1);
	}
      idx++;
    }
  if (my_strlen(str) == 1 && (str[0] == 127 || str[0] == 8))
    {
      key_code[idx](keys, str, line);
      return (1);
    }
  return (0);
}
