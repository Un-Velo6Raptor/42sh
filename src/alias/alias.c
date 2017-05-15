/*
** alias.c for PSU_2016_42sh in /home/sahel/rendu/PSU/PSU_2016_42sh
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 10 15:49:05 2017 Sahel Lucas--Saoudi
** Last update Mon May 15 15:20:03 2017 Sahel Lucas--Saoudi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <basic.h>
#include "main.h"
#include "alias.h"

static int		get_rc_file(char **argv, t_shell *shell)
{
  int		fd;
  char		*path;

  if (tablen_(argv) > 1)
    path = argv[1];
  else
  {
    path = strdup(shell->sh);
    path = realloc(path, strlen(path) + strlen(ALIAS_FILE) + 2);
    path = strcat(path, "/");
    path = strcat(path, ALIAS_FILE);
  }
  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (-1);
  path[strrchr(path, '/') - path] = '\0';
  free(shell->sh);
  shell->sh = path;
  return (fd);
}

void		exec_file(const int fd)
{
  char		*buf;

  buf = getnextline_(fd);
  while (buf)
    {

      buf = getnextline_(fd);
    }
}

int		source(char **argv, t_shell *shell)
{
  int		i;
  int		fd;
  int		error;

  if (tablen_(argv) == 1)
    {
      dprintf(2, "source: Too few arguments.\n");
      return (1);
    }
  i = 1;
  error = 0;
  while (argv[i])
    {
      fd = 0;
      //fd = get_fd();
      if (fd != -1)
	{
	  exec_file(fd);
	}
      else
	error = 1;
    }
  return (error);
}

char		**remake_argv_with_alias(char *alias, char **argv)
{
  char		**new;
  int		i;
  int		j;

  i = 1;
  new = parse_(alias, ' ');
  j = tablen_(new);
  while (argv && argv[i])
    {
      new = realloc(new, sizeof(char *) * (j + 1));
      new[j] = strdup(argv[i]);
      i++;
      j++;
    }
  new = realloc(new, sizeof(char *) * (j + 1));
  new[j] = NULL;
  free_tab(argv);
  return (new);
}

char		**alias(char **argv, t_shell *shell)
{
  char		*alias;
  char		*aliasname;
  int		i;

  i = 0;
  alias = NULL;
  if (!argv || !*argv || !shell->alias)
    return (argv);
  while (shell->alias && shell->alias[i])
    {
      aliasname = only_before(shell->alias[i], ' ');
      if (!strcmp(argv[0], aliasname))
	{
	  alias = without_before_(shell->alias[i], ' ');
	  argv = remake_argv_with_alias(alias, argv);
	}
      i++;
    }
  return (argv);
}

int	call_alias(char **argv, t_shell *shell)
{
  char	*alias;
  int	i;
  int	argv_i;

  i = tablen_(shell->alias);
  shell->alias = realloc(shell->alias, i + 2);
  if (!shell->alias)
    return (1);
  if (tablen_(argv) < 3)
    return (0);
  argv_i = 2;
  alias = strdup(argv[1]);
  if (!alias)
    return (1);
  alias = realloc(alias, strlen(alias) + 2);
  if (!alias)
    return (1);
  strcat(alias, " ");
  while (argv[argv_i])
    {
      alias = realloc(alias, strlen(alias) + strlen(argv[argv_i] + 3));
      if (!alias)
	return (1);
      strcat(alias, argv[argv_i]);
      strcat(alias, " ");
      argv_i++;
    }
  shell->alias[i] = alias;
  shell->alias[i + 1] = NULL;
  return (0);
}
