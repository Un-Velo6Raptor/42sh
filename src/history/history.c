/*
** history.c for PSU_2016_42sh in /home/sahel/rendu/PSU/PSU_2016_42sh
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Fri May 12 14:39:29 2017 Sahel Lucas--Saoudi
** Last update Tue May 16 13:35:54 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include "main.h"
#include "history.h"
#include "basic.h"

int	get_history_file(t_shell *shell)
{
  char	*path;
  int	fd;

  printf("YOLO\n");
  path = strdup(shell->sh);
  path = realloc(path, strlen(path) + strlen(HISTORY_FILE) + 2);
  strcat(path, "/");
  strcat(path, HISTORY_FILE);
  printf("%s\n", path);
  fd = open(path, O_RDONLY);
  return (fd);
}

char	**get_history(t_shell *shell)
{
  char	**tab;
  char	*buff;
  int	i;
  int	fd;

  i = 0;
  fd = get_history_file(shell);
  printf("%i\n", fd);
  if (fd < 0)
    return (NULL);
  buff = getnextline_(fd);
  tab = NULL;
  while (buff)
  {
    tab = realloc(tab, sizeof(char *) * (i + 1));
    tab[i] = strdup(buff);
    buff = getnextline_(fd);
    i++;
  }
  tab = realloc(tab, sizeof(char *) * (i + 1));
  tab[i] = NULL;
  return (tab);
}

char	*history(char *command, t_shell *shell, int incr)
{
  char	*com;
  char	**list;
  int	i;

  list = get_history(shell);
  if (!list || shell->id_command >= tablen_(list))
  {
    dprintf(2, "42sh: no such event\n");
    return (NULL);
  }
  com = strdup(shell->command);
  com = realloc(com, strlen(com) + 1);
  strcat(com, "*");
  i = shell->id_command;
  while (i >= 0 && list[i])
  {
    if (match(list[i], com))
    {
      free(command);
      free_tab(list);
      return (strdup(list[i]));
    }
    i += incr;
  }
  free_tab(list);
  return (command);
}

int	call_history(char **argv, t_shell *shell)
{
  char	**list;
  int	i;

  i = 0;
  list = get_history(shell);
  if (!list || tablen_(argv) != 1)
    return (1);
  while (list[i])
  {
    dprintf(1, " %i  %s\n", i + 1, list[i]);
    i++;
  }
  free_tab(list);
  fflush(stdout);
  return (0);
}

void	add_to_history(char *command, t_shell *shell)
{
  char	*path;
  int	fd;

  path = strdup(shell->sh);
  if (!path)
    return ;
  path = realloc(path, strlen(path) + strlen(HISTORY_FILE) + 2);
  if (!path)
    return ;
  strcat(path, "/");
  strcat(path, HISTORY_FILE);
  fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
  if (fd == -1)
    return ;
  dprintf(fd, "%s\n", command);
  close(fd);
  shell->id_command = shell->idmax + 1;
  shell->idmax++;
  free(path);
}
