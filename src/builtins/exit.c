/*
** exit.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Wed Apr  5 16:48:26 2017 Sahel Lucas--Saoudi
** Last update Thu May 18 08:12:23 2017 Benoit Hoffman
*/

#include <unistd.h>
#include <stdlib.h>
#include "basic.h"
#include "main.h"

int	call_exit(char **argv, t_shell *shell)
{
  int	i;

  i = 0;
  if (tablen_(argv) > 2)
    {
      putstr_("exit: Expression Syntax.\n", 2);
      return (1);
    }
  if (!argv[1])
    {
      shell->exit = 1;
      return (0);
    }
  if ((argv[1][0] > '9' || argv[1][0] < '0') && argv[1][i] != '-')
    {
      putstr_("exit: Expression Syntax.\n", 2);
      return (1);
    }
  while (argv[1][i] != '\0')
    {
      if ((argv[1][i] < '0' || argv[1][i] > '9') && argv[1][i] != '-')
	{
	  putstr_("exit: Badly formed number.\n", 2);
	  return (1);
	}
      i += 1;
    }
  shell->exit = 1;
  shell->status = atoi(argv[1]);
  return (shell->status % 255);
}

/*int	call_exit(char **argv, t_shell *shell)
{
  if (tablen_(argv) != 1)
    shell->status = getnbr_(argv[1]);
  else
    shell->status = 0;
  shell->exit = 1;
  return (0);
  }*/

int	check_exit_pipe(char **command, int **pipefd, int *pid, t_shell *shell)
{
  int i;

  i = 0;
  while (command[i])
    {
      if (match(command[i], "exit *"))
	{
	  pipefd[i] = (int[2]) {-1, -1};
	  pid[i] = -1;
	}
      else
	{
	  pipefd[i] = command_loop(pid, command, i, shell);
	  if (!pipefd[i])
	    return (84);
	}
      i++;
    }
  return (0);
}
