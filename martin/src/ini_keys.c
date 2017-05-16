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
#include	"my.h"

int		keys_pattern(t_key *keys)
{
  if ((keys->cvvis = tigetstr("cvvis")) == (char *) -1)
    return (84);
  if ((keys->civis = tigetstr("civis")) == (char *) -1)
    return (84);
  if ((keys->bold = tigetstr("bold")) == (char *) -1)
    return (84);
  return (0);
}

int		ini_keys(t_key *keys, char *term)
{
  char		*tmp;
  int		ret;

  if (setupterm(term, 1, &ret) == ERR)
    return (my_puterror("Can't set the term.\n"));
  tmp = tigetstr("smkx");
  my_putstr(tmp);
  if ((keys->key_l = tigetstr("kcub1")) == (char *) -1)
    return (84);
  if ((keys->key_r = tigetstr("kcuf1")) == (char *) -1)
    return (84);
  if ((keys->key_sup = tigetstr("kdch1")) == (char *) -1)
    return (84);
  if ((keys->key_b = tigetstr("kcuu1")) == (char *) -1)
    return (84);
  if ((keys->key_t = tigetstr("kcud1")) == (char *) -1)
    return (84);
  return (keys_pattern(keys));
}
