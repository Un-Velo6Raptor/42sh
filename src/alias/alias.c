/*
** alias.c for PSU_2016_42sh in /home/sahel/rendu/PSU/PSU_2016_42sh
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 10 15:49:05 2017 Sahel Lucas--Saoudi
** Last update Thu May 11 13:37:47 2017 Sahel Lucas--Saoudi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <basic.h>
#include "main.h"
#include "alias.h"

int		source(__attribute__ ((unused)) char **argv, t_shell *shell)
{
  char		**tab;
  char		*buff;
  int		i;
  int		fd;

  fd = open(".42shrc", O_RDONLY);
  if (fd == -1)
    return (1);
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

char		**alias(char **argv, t_shell *shell)
{
  char		**new_argv;
  char		*alias;
  int		i;
  int		j;
  char		*aliasname;

  i = 0;
  alias = NULL;
  if (!argv || !*argv || !shell->alias)
    return (argv);
  while (shell->alias && shell->alias[i])
  {
    aliasname = only_before(shell->alias[i], '=');
    if (!strcmp(argv[0], aliasname))
      alias = without_before_(shell->alias[i], '=');
    i++;
  }
  new_argv = parse_(alias, ' ');
  i = 1;
  j = tablen_(new_argv);
  if (!new_argv)
  {
    new_argv = malloc(sizeof(char *) * 1);
    new_argv[0] = strdup(argv[0]);
    j++;
  }
  while (argv && argv[i])
  {
    new_argv = realloc(new_argv, sizeof(char *) * (j + 1));
    new_argv[j] = strdup(argv[i]);
    j++;
    i++;
  }
  new_argv = realloc(new_argv, sizeof(char *) * (j + 1));
  new_argv[j] = NULL;
  return (new_argv);
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
