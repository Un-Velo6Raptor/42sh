/*
** init.c for 42sh in /home/angevil124/prog/PSU/PSU_2016_42sh
** 
** Made by Benoit Hoffman
** Login   <benoit.hoffman@epitech.eu>
** 
** Started on  Fri May 19 13:50:52 2017 Benoit Hoffman
** Last update Fri May 19 14:01:18 2017 Benoit Hoffman
*/

#include		<stdio.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		<term.h>
#include		"edit.h"

int			initial_checks(char **env, t_key *keys,
				       struct termios *new,
				       struct termios *save)
{
  int			pos;

  pos = found_term(env);
  if (isatty(0) == 1 && pos == -1)
    {
      dprintf(2, "No variable term set.\n");
      return (84);
    }
  if (isatty(0) == 1 && (tgetent(NULL, &env[pos][5]) < 0
                         || tcgetattr(0, new) < 0 || tcgetattr(0, save) < 0))
    {
      dprintf(2, "Cannot set new Term.\n");
      return (84);
    }
  new->c_lflag &= ~(ICANON | ECHO);
  if (isatty(0) == 1 && tcsetattr(0, TCSANOW, new) == -1)
    {
      dprintf(2, "Cannot set new attribute.\n");
      return (84);
    }
  if (isatty(0) == 1 && ini_keys(keys, &env[pos][5]) == 84)
    {
      dprintf(2, "Cannot get keys.\n");
      return (84);
    }
  return (0);
}
