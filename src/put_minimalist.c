/*
** put_minimalist.c for 42sh in /home/angevil124/prog/PSU/PSU_2016_42sh
** 
** Made by Benoit Hoffman
** Login   <benoit.hoffman@epitech.eu>
** 
** Started on  Fri May 12 15:01:52 2017 Benoit Hoffman
** Last update Sat May 13 09:10:59 2017 Benoit Hoffman
*/

#include	<string.h>
#include	<stdlib.h>
#include	"main.h"

int		put_minimalist(t_shell *shell)
{
  int		i;
  char		*tmp;

  tmp = getvar(shell->env, "PATH=*");
  shell->path = parse_(tmp, ':');
  free(tmp);
  i = 0;
  if (!shell->path)
    shell->path = malloc(sizeof(char *) * 3);
  else
    {
      while (shell->path[i])
	i += 1;
      shell->path = realloc(shell->path, sizeof(char *) * (i + 3));
    }
  if (!shell->path)
    return (84);
  shell->path[i++] = strdup("/usr/bin");
  shell->path[i++] = strdup("/bin");
  shell->path[i] = NULL;
  if (!shell->path[i - 1] || !shell->path[i - 2])
    return (84);
  return (0);
}
