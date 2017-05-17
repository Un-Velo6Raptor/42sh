/*
** alias.c for PSU_2016_42sh in /home/sahel/rendu/PSU/PSU_2016_42sh
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 10 15:49:05 2017 Sahel Lucas--Saoudi
** Last update Wed May 17 14:16:39 2017 Sahel Lucas--Saoudi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <basic.h>
#include "main.h"
#include "alias.h"

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
  shell->alias = realloc(shell->alias, sizeof(char *) * (i + 2));
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
      alias = realloc(alias, strlen_(alias) + strlen_(argv[argv_i]) + 3);
      if (!alias)
	return (1);
      strcat(alias, argv[argv_i]);
      if (argv[argv_i + 1] != NULL)
	strcat(alias, " ");
      argv_i++;
    }
  shell->alias[i] = alias;
  shell->alias[i + 1] = NULL;
  return (0);
}
