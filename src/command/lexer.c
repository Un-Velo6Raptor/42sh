/*
** lexer.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed Apr  5 20:17:58 2017 Sahel Lucas--Saoudi
** Last update Fri Apr 28 17:03:20 2017 Sahel Lucas--Saoudi
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "basic.h"

int		good_file(char *path)
{
  char		*real;

  if (path[0] == '<')
    real = strdup_(&path[1]);
  if (path[1] == '>')
    real = strdup_(&path[2]);
  else
    real = strdup_(&path[1]);
  if (!check_file(real, path[0]))
    return (0);
  return (1);
}

int	check_filename(char **filename)
{
  int	i;
  int	right;
  int	left;

  i = 0;
  left = 0;
  right = 0;
  while (filename && filename[i])
    {
      if (good_filename(filename[i], &left, &right))
	return (1);
      i++;
    }
  if (left > 1)
    putstr_("Ambiguous input redirect.\n", 2);
  if (right > 1)
    putstr_("Ambiguous output redirect.\n", 2);
  return ((left > 1 || right > 1) ? (1) : (0));
}

int	*get_fd(char **file_name, char **buffer)
{
  int	*fd;
  int	i;

  i = 0;
  fd = malloc(sizeof(int) * (tablen_(file_name) + 1));
  if (!fd)
    exit(84);
  while (i < tablen_(file_name))
    {
      if (match(file_name[i], ">>*"))
	fd[i] = open(&file_name[i][2], O_CREAT | O_RDWR | O_APPEND, 00644);
      else if (match(file_name[i], "<<*"))
	{
	  *buffer = stralloc_(*buffer, double_redir(&file_name[i][2]));
	  fd[i] = -1;
	}
      else if (match(file_name[i], "<*"))
	fd[i] = open(&file_name[i][1], O_RDWR, 00644);
      else if (match(file_name[i], ">*"))
	fd[i] = open(&file_name[i][1], O_CREAT | O_TRUNC | O_RDWR, 00644);
      i++;
    }
  return (fd);
}

void	exec_manage(char **tab, t_shell *shell)
{
  int	*fd;
  char	**file_name;
  char	**av;
  char	*buffer;

  file_name = take_redir(tab, 1);
  if (check_filename(file_name))
    {
      shell->status = 1;
      return ;
    }
  av = take_redir(tab, 0);
  if (!av || !*av)
    {
      putstr_("Invalid null command.\n", 2);
      shell->status = 1;
      return ;
    }
  reset01(0);
  buffer = NULL;
  fd = get_fd(file_name, &buffer);
  setup_redir(buffer, fd, file_name);
  exec_manager(av, shell);
  end_manage(fd, file_name, av, tab);
}

void	lexer(char **argv, t_shell *shell)
{
  int	argv_i;

  argv_i = 0;
  while (argv[argv_i])
    {
      if (*argv[argv_i] && howmany_(argv[argv_i], ' ') +
	  howmany_(argv[argv_i], '\t') != strlen_(argv[argv_i]))
	{
	  if (sp_len_(argv[argv_i], '|') != strlen_(argv[argv_i]))
	    exec_pipe_manager(argv, argv_i, shell);
	  else
	    exec_manage(parse__redir(argv[argv_i]), shell);
	}
      argv_i++;
    }
}
