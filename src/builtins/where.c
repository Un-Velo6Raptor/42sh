/*
** where.c for 42sh in /home/angevil124/prog/PSU/PSU_2016_42sh/src
** 
** Made by Benoit Hoffman
** Login   <benoit.hoffman@epitech.eu>
** 
** Started on  Mon May 15 11:33:46 2017 Benoit Hoffman
** Last update Tue May 16 08:48:21 2017 Benoit Hoffman
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<string.h>
#include	"basic.h"
#include	"main.h"

static char		*cat_all(char *cmd, char *path)
{
  char		*buffer;

  
  buffer = malloc(sizeof(char) * (strlen_(path) +
				  2 + strlen_(cmd)));
  if (!buffer || !cmd)
    return (NULL);
  buffer[0] = '\0';
  strcat(buffer, path);
  strcat(buffer, "/");
  strcat(buffer, cmd);
  return (buffer);
}

static int	check_access(const char *path)
{
  struct stat	st;

  if (stat(path, &st) == -1)
    return (0);
  if (access(path, X_OK) == 0)
    return (1);
  return (0);
}

static int	check_errors(char *str)
{
  if (!str)
    {
      dprintf(2, "where: Too few arguments.\n");
      return (1);
    }
  return (0);
}

int		do_where(char *path, int *found, int *i)
{
  if (!path)
    return (1);
  if (check_access(path) == 1)
    {
      printf("%s\n", path);
      *found = 1;
    }
  *i += 1;
  free(path);
  path = NULL;
  return (0);
}

int	        call_where(char **command, t_shell *shell)
{
  int		i;
  int		j;
  char		*buffer;
  int		error;
  int		found;

  error = 0;
  j = 1;
  if (check_errors(command[1]) == 1)
    return (1);
  while (command[j])
    {
      found = 0;
      i = 0;
      while (shell->path && shell->path[i])
	{
	  buffer = cat_all(command[j], shell->path[i]);
	  if (do_where(buffer, &found, &i) == 1)
	    return (1);
	}
      if (found == 0)
	error = 1;
      j += 1;
    }
  return (error);
}
