/*
** where.c for 42sh in /home/angevil124/prog/PSU/PSU_2016_42sh/src
** 
** Made by Benoit Hoffman
** Login   <benoit.hoffman@epitech.eu>
** 
** Started on  Mon May 15 11:33:46 2017 Benoit Hoffman
** Last update Mon May 15 12:25:04 2017 Benoit Hoffman
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

int	        call_where(char **command, t_shell *shell)
{
  int		i;
  int		j;
  char		*buffer;

  j = 1;
  buffer = NULL;
  if (check_errors(command[1]) == 1)
    return (1);
  while (command[j])
    {
      i = 0;
      while (shell->path && shell->path[i])
	{
	  buffer = cat_all(command[j], shell->path[i]);
	  if (!buffer)
	    return (1);
	  if (check_access(buffer) == 1)
	    printf("%s\n", buffer);
	  i += 1;
	  free(buffer);
	  buffer = NULL;
	}
      j += 1;
    }
  return (0);
}
