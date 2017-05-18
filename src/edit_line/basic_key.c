/*
** basic_key.c for  in /home/januar_m/delivery/PSU/edit_line
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Wed May 17 17:30:27 2017 Martin Januario
** Last update Thu May 18 13:31:20 2017 Sahel Lucas--Saoudi
*/

#include	<stdio.h>
#include	<curses.h>
#include	<term.h>
#include	<stdlib.h>
#include	"edit.h"

void		key_left_(t_key *keys, char *str, char *line)
{
  if (keys->idx < 0)
    return ;
  keys->idx -= 1;
  printf(tgetstr("le", NULL));
  fflush(stdout);
  (void) str;
  (void) line;
}

void		key_right_(t_key *keys, char *str, char *line)
{
  if (keys->idx >= my_strlen(line))
    return ;
  keys->idx += 1;
  printf(tgetstr("nd", NULL));
  fflush(stdout);
  (void) str;
  (void) line;
}

void		key_top_(t_key *keys, char *str, char *line)
{
  (void) keys;
  (void) str;
  (void) line;
}

void		key_bottom_(t_key *keys, char *str, char *line)
{
  (void) keys;
  (void) str;
  (void) line;
}
