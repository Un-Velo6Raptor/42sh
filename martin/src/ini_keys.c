/*
** ini_keys.c for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 10 14:50:59 2017 Martin Januario
** Last update Tue May 16 12:36:08 2017 Martin Januario
*/

#include	<curses.h>
#include	<term.h>
#include	<unistd.h>
#include	"my.h"

static int	check(char *str)
{
  if (str == (char *) -1)
    return (1);
  return (0);
}

int		ini_keys(t_key *keys, char *term)
{
  char		*tmp;
  int		ret;

  if (setupterm(term, 1, &ret) == ERR)
    return (my_puterror("Can't set the term.\n"));
  tmp = tigetstr("smkx");
  keys->key_l = tigetstr("kcub1");
  keys->key_r = tigetstr("kcuf1");
  keys->key_sup = tigetstr("kdch1");
  keys->key_b = tigetstr("kcuu1");
  keys->key_t = tigetstr("kcud1");
  keys->cvvis = tigetstr("cvvis");
  keys->civis = tigetstr("civis");
  keys->bold = tigetstr("bold");
  if (check(tmp) || check(keys->key_l) || check(keys->key_r) ||
    check(keys->key_sup) || check(keys->key_b) || check(keys->key_t) ||
    check(keys->cvvis) || check(keys->civis) || check(keys->bold))
    return (84);
  if (isatty(0) == 1)
    my_putstr(tmp);
  return (0);
}
