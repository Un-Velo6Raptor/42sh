/*
** main.c for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 10 13:58:43 2017 Martin Januario
** Last update Tue May 16 13:40:27 2017 Martin Januario
*/

#include	<sys/ioctl.h>
#include	<termios.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<curses.h>
#include	<term.h>
#include	"my.h"

char			*my_reset(char *tmp, t_key *keys)
{
  my_free(tmp);
  keys->check = 0;
  return (NULL);
}

char		*loop_read(t_key *keys, char *tmp, char *str)
{
  int			idx;
  int			max;

  tmp = my_reset(tmp, keys);
  idx = my_strlen(str);
  max = 0;
  while (read(0, &keys->c, 1) > 0 && keys->c[0] != '\n')
  {
    keys->c[1] = '\0';
    if (keys->c[0] == 4)
    {
      write(1, "\n", 1);
      return (str);
    }
    if (my_strlen(str) > max)
      max = my_strlen(str);
    if (check_is_key(keys, keys->c, keys->check) == 1)
	keys->check += 1;
    else if (is_not_a_key(&str, &tmp, &idx, keys) == 84)
      return (NULL);
    keys->width = my_strlen(str);
    if (keys->check != 0)
      is_a_key(keys, &tmp, &idx, &str);
    else if ((str = my_realloc_idx(str, keys->c, idx)) == NULL)
      return (NULL);
    reset_line(max, str, idx, keys);
    }
  my_putstr("\n");
  if (keys->c[0] == '\n' && str == NULL)
    return (strdup(""));
  return (str);
}
