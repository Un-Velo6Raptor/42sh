/*
** put_minimalist.c for 42sh in /home/angevil124/prog/PSU/PSU_2016_42sh
** 
** Made by Benoit Hoffman
** Login   <benoit.hoffman@epitech.eu>
** 
** Started on  Fri May 12 15:01:52 2017 Benoit Hoffman
** Last update Sat May 13 09:48:58 2017 Benoit Hoffman
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
  i = 0;
  if (!tmp)
    {
      if (!shell->path)
	{
	  shell->path = malloc(sizeof(char *) * 3);
	  if (!shell->path)
	    return (84);
	  shell->path[i++] = strdup("/usr/bin");
	  shell->path[i++] = strdup("/bin");
	  shell->path[i] = NULL;
	  if (!shell->path[i - 1] || !shell->path[i - 2])
	    return (84);
	}
    }
  free(tmp);
  return (0);
}
