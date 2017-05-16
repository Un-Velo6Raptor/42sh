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

static int		loop_read(t_key *keys, char *tmp, char *str)
{
  int			idx;
  int			max;

  tmp = my_reset(tmp, keys);
  idx = my_strlen(str);
  max = 0;
  while (read(0, &keys->c, 1) > 0 && keys->c[0] != '\n')
    {
      keys->c[1] = '\0';
      if (my_strlen(str) > max)
	max = my_strlen(str);
      if (check_is_key(keys, keys->c, keys->check) == 1)
	keys->check += 1;
      else if (is_not_a_key(&str, &tmp, &idx, keys) == 84)
	return (84);
      keys->width = my_strlen(str);
      if (keys->check != 0)
	is_a_key(keys, &tmp, &idx, &str);
      else if ((str = my_realloc_idx(str, keys->c, idx)) == NULL)
	return (84);
      reset_line(max, str, idx, keys);
    }
  return (my_putstr("\n"));
}

int			main(int __attribute__ ((unused)) argc,
			     char __attribute__ ((unused)) **argv,
			     char **env)
{
  struct termios	new;
  struct termios	save;
  t_key			keys;
  int			pos;

  if ((pos = found_term(env)) < 0)
    return (84);
  if (ini_keys(&keys, &env[pos][5]) == 84)
    return (84);
  if (start_edit_line(&env[pos][5], &new, &save, &keys) == 84)
    return (84);
  loop_read(&keys, NULL, NULL);
  return (end_edit_line(&save, &keys));
}
