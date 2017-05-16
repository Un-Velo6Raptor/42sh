/*
** pipe.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Mon Apr  3 15:31:27 2017 Sahel Lucas--Saoudi
** Last update Tue May 16 09:46:11 2017 Benoit Hoffman
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <printf.h>
#include "main.h"
#include "basic.h"

int	*command_loop(int *pid, char **command, int i, t_shell *shell)
{
  int	*fd;

  fd = malloc(8);
  if (!fd || pipe(fd) == -1)
    {
      putstr_("Not enought file descriptor.\n", 2);
      exit (1);
    }
  pid[i] = fork();
  if (pid[i] == -1)
    exit(1);
  if (pid[i] == 0)
    {
      dup2(shell->fd0, 0);
      if (command[i + 1])
	dup2(fd[1], 1);
      close_(fd[0]);
      exec_manage(parse__redir(command[i]), shell);
      close_(fd[1]);
      free_tab(command);
      exit(free_shell(shell));
    }
  close_(fd[1]);
  shell->fd0 = fd[0];
  return (fd);
}

static int	end_check_pipe(char **tab)
{
  char		**av;
  char		**file_name;
  int		ret;

  ret = 0;
  av = take_redir(tab, 0);
  file_name = take_redir(tab, 1);
  if (!av || !file_name)
    return (1);
  if (tablen_(av) == 0)
    {
      putstr_("Invalid null command.\n", 2);
      ret = 1;
    }
  if (check_filename(file_name))
    ret = 1;
  free_tab(av);
  free_tab(file_name);
  return (ret);
}

int	check_pipe(char **command, int i)
{
  char	**tab;

  while (command[i])
    {
      if (i != 0 && sp_len_(command[i], '<') != strlen_(command[i]))
	{
	  putstr_("Ambiguous input redirect.\n", 2);
	  return (1);
	}
      if (i != tablen_(command) - 1 &&
	  sp_len_(command[i], '>') != strlen_(command[i]))
	{
	  putstr_("Ambiguous output redirect.\n", 2);
	  return (1);
	}
      tab = parse__redir(command[i]);
      if (end_check_pipe(tab))
	return (1);
      free_tab(tab);
      i++;
    }
  return (0);
}

void	pipe_end(t_shell *shell, int **pipefd, int *pid, int i)
{
  int	st;

  st = 0;
  waitpid(pid[i], &shell->status, 0);
  if (shell->status % 255 == 141)
    putstr_("Broken pipe\n", 2);
  if (shell->status > 255)
    st = shell->status % 255;
  i--;
  while (i >= 0)
    {
      if (pipefd && pipefd[i] && pid[i] != -1)
	{
	  close_(pipefd[i][0]);
	  close_(pipefd[i][1]);
	  waitpid(pid[i], &shell->status, 0);
	}
      if (shell->status > 255)
	st = shell->status % 255;
      i--;
    }
  if (st != 0)
    shell->status = st;
}

void	exec_pipe_manager(char **tab, int tab_i, t_shell *shell)
{
  char	**command;
  int	**pipefd;
  int	*pid;

  command = parse_(tab[tab_i], '|');
  if (check_pipe(command, 0))
    {
      shell->status = 1;
      return ;
    }
  shell->fd0 = 0;
  pipefd = malloc(sizeof(int *) * (tablen_(command) + 1));
  pid = malloc(sizeof(int) * (tablen_(command) + 1));
  if (!pid || !pipefd)
    return ;
  check_exit_pipe(command, pipefd, pid, shell);
  pipe_end(shell, pipefd, pid, tablen_(command) - 1);
  free(pipefd);
  free(pid);
  free_tab(command);
}
