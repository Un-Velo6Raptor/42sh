/*
** reset_line.c for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue May 16 13:00:58 2017 Martin Januario
** Last update Tue May 16 13:41:05 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<term.h>
#include	<unistd.h>
#include	"my.h"

static void		loop_space(int nb)
{
  int			idx;

  idx = 0;
  while (nb > idx)
    {
      write(1, " ", 1);
      idx++;
    }
}

static int		put_line(char *str, int pos, t_key *keys)
{
  int			idx;

  idx = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0' && idx != pos)
    {
      write(1, &str[idx], 1);
      idx++;
    }
  my_putstr(keys->bold);
  my_putstr("¤");
  my_putstr("\033[0;m");
  my_putstr(&str[idx]);
  return (0);
}

int		reset_line(int max, char *str, int idx, t_key *keys)
{
  char		*ola;
  int		cpt;

  cpt = 0;
  if (!str || !(ola = tgetstr("le", NULL)))
    return (84);
  while (cpt <= max)
    {
      write(1, ola, my_strlen(ola));
      cpt++;
    }
  put_line(str, idx, keys);
  loop_space(max - my_strlen(str));
  return (0);
}
