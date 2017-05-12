/*
** alias.c for PSU_2016_42sh in /home/sahel/rendu/PSU/PSU_2016_42sh
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 10 15:49:05 2017 Sahel Lucas--Saoudi
** Last update Fri May 12 17:50:46 2017 Sahel Lucas--Saoudi
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

int		source(char **argv, t_shell *shell)
{
  char		**tab;
  char		*buff;
  int		i;
  int		fd;

  fd = get_rc_file(argv, shell);
  if (fd < 0)
    return (84);
  tab = malloc(sizeof(char *) * 1);
  tab[0] = NULL;
  i = 0;
  buff = getnextline_(fd);
  while (buff)
  {
    if (match(buff, "alias *"))
    {
      tab = realloc(tab, sizeof(char *) * (i + 2));
      tab[i] = strdup(&buff[6]);
      tab[i + 1] = NULL;
      i++;
    }
    buff = getnextline_(fd);
  }
  shell->alias = tab;
  return (0);
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
      aliasname = only_before(shell->alias[i], '=');
      if (!strcmp(argv[0], aliasname))
	{
	  alias = without_before_(shell->alias[i], '=');
	  argv = remake_argv_with_alias(alias, argv);
	}
      i++;
    }
  return (argv);
}

int	call_alias(char **argv, t_shell *shell)
{
  int	fd;

  if (tablen_(argv) != 2)
  {
    fprintf(stderr, "alias:\n\talias [\"]<aliasname>=<alias>[\"]\n");
    shell->status = 1;
    return (1);
  }
  fd = open(".42shrc", O_CREAT | O_APPEND | O_RDWR, 0644);
  if (fd < 0)
    return (1);
  dprintf(fd, "alias %s\n", argv[1]);
  close(fd);
  return (source(NULL, shell));
}
