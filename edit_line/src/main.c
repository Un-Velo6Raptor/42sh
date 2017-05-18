/*
** main.c for  in /home/januar_m/delivery/PSU/edit_line
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 17 15:35:14 2017 Martin Januario
** Last update Thu May 18 12:55:23 2017 Martin Januario
*/

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
  else if ((tmp = malloc(my_strlen(str) + my_strlen(line) + 1)) == NULL)
    return (NULL);
  tmp[0] = '\0';
  strncat(tmp, line, keys->idx);
  strcat(tmp, str);
  strcat(tmp, &line[keys->idx]);
  free(line);
  return (tmp);
}

static void		print_line(char *str)
{
  my_putstr(tgetstr("im", NULL));
  my_putstr(str);
  my_putstr(tgetstr("ei", NULL));
}

static char		*loop_read(t_key *keys)
{
  char		str[8];
  char		*line;
  int		size;

  keys->idx = 0;
  line = NULL;
  size = read(0, &str, 8);
  while (size > 0)
    {
      str[size] = '\0';
      if (strcmp(str, "\n") == 0)
	return ((line == NULL) ? strdup("") : line);
      if ((my_strlen(str) == 1 && str[0] == 4 && my_strlen(line) == 0))
	return (NULL);
      if (check_is_key(keys, str, line) == 0)
	{
	  line = my_concat(line, str, keys);
	  if (line == NULL)
	    return (NULL);
	  keys->idx += my_strlen(str);
	  print_line(str);
	}
      size = read(0, &str, 8);
    }
  return (line);
}

int			main(int __attribute__ ((unused)) argc,
			     char __attribute__ ((unused)) **argv, char **env)
{
  struct termios	newT;
  struct termios	oldT;
  t_key			keys;
  int			pos;

  pos = found_term(env);
  if (pos == -1)
    return (my_puterror("No variable term set.\n"));
  if (tgetent(NULL, &env[pos][5]) < 0 ||
      tcgetattr(0, &newT) < 0 ||
      tcgetattr(0, &oldT) < 0)
    return (84);
  newT.c_lflag &= ~(ICANON | ECHO);
  if (tcsetattr(0, TCSANOW, &newT) == -1)
    return (84);
  if (ini_keys(&keys, &env[pos][5]) == 84)
    return (84);
  printf("\nline: %s\n", loop_read(&keys));
  tcsetattr(0, TCSANOW, &oldT);
  return (0);
}
