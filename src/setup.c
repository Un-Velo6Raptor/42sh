/*
** setup.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Sat Apr  8 16:45:26 2017 Sahel Lucas--Saoudi
** Last update Fri Apr 28 14:14:40 2017 Sahel Lucas--Saoudi
*/

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "basic.h"
#include "main.h"

void		reset01(int status)
{
  static int	fd0;
  static int	fd1;

  if (status == 0)
    {
      fd0 = dup(0);
      fd1 = dup(1);
    }
  else
    {
      dup2(fd1, 1);
      dup2(fd0, 0);
      close(fd0);
      close(fd1);
    }
}

void	setup_redir(char *buffer, int *fd, char **file_name)
{
  int	pipefd[2];
  int	i;

  if (buffer)
    {
      if (pipe(pipefd) == -1)
	return ;
      dup2(pipefd[0], 0);
      putstr_(buffer, pipefd[1]);
      free_(buffer);
      close(pipefd[1]);
    }
  i = 0;
  while (i < tablen_(file_name))
    {
      if (fd[i] != -1)
	{
	  if (file_name[i][0] == '>')
	    dup2(fd[i], 1);
	  if (!match(file_name[i], "<<*") && file_name[i][0] == '<')
	    dup2(fd[i], 0);
	}
      i++;
    }
}