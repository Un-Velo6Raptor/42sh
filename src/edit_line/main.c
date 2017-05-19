/*
** main.c for  in /home/januar_m/delivery/PSU/edit_line
**
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
**
** Started on  Wed May 17 15:35:14 2017 Martin Januario
** Last update Fri May 19 14:49:35 2017 Martin Januario
*/

#include	<sys/ioctl.h>
#include	<term.h>
#include	<curses.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"edit.h"

static char		*my_concat(char *line, char *str, t_key *keys)
{
  char			*tmp;

  if (line == NULL)
  {
      tmp = strdup(str);
      return (tmp);
  }
  else
  {
    tmp = malloc(my_strlen(str) + my_strlen(line) + 1);
    if (!tmp)
      return (NULL);
  }
  tmp[0] = '\0';
  strncat(tmp, line, keys->idx);
  strcat(tmp, str);
  strcat(tmp, &line[keys->idx]);
  free(line);
  return (tmp);
}

static void		print_line(char *str)
{
  printf(tgetstr("im", NULL));
  printf(str);
  printf(tgetstr("ei", NULL));
  fflush(stdout);
}

static void		get_cols(t_key *keys)
{
  struct winsize	w;

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  keys->cols = w.ws_col;
}

char		*loop_read(t_key *keys)
{
  char		str[8];
  char		*line;
  int		size;

  prompt(keys->shell->status % 255);
  keys->idx = 0;
  line = NULL;
  get_cols(keys);
  size = read(0, &str, 7);
  while (size > 0)
    {
      str[size] = '\0';
      if (strcmp(str, "\n") == 0)
	{
	  printf("\n");
	  return ((line == NULL) ? strdup("") : line);
	}
      if ((my_strlen(str) == 1 && str[0] == 4 && my_strlen(line) == 0))
	return (NULL);
      if (check_is_key(keys, str, &line) == 0 &&
	  my_strlen(line) + my_strlen(str) < keys->cols)
	{
	  line = my_concat(line, str, keys);
	  if (line == NULL)
	    return (NULL);
	  keys->idx += my_strlen(str);
	  print_line(str);
	}
      get_cols(keys);
      size = read(0, &str, 7);
    }
  return (line);
}
