/*
** start_end.c for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue May 16 12:36:39 2017 Martin Januario
** Last update Tue May 16 12:58:34 2017 Martin Januario
*/

#include        <sys/ioctl.h>
#include        <termios.h>
#include        <unistd.h>
#include        <stdio.h>
#include        <string.h>
#include        <stdlib.h>
#include        <curses.h>
#include        <term.h>
#include	"my.h"

char		*start_edit_line(char *term, struct termios *new,
				struct termios *save, t_key *keys)
{
  if (tgetent(NULL, term) < 0 ||
      tcgetattr(0, new) < 0 ||
      tcgetattr(0, save) < 0)
    return (NULL);
  new->c_lflag &= ~(ICANON | ECHO);
  if (tcsetattr(0, TCSANOW, new) == -1)
    return (NULL);
  if (isatty(0) == 1)
    my_putstr(keys->civis);
  fflush(stdout);
  return ("Ok");
}

int		end_edit_line(struct termios *save, t_key *keys)
{
  if (isatty(0) == 1)
    my_putstr(keys->cvvis);
  fflush(stdout);
  tcsetattr(0, TCSANOW, save);
  return (0);
}
