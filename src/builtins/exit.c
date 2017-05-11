/*
** exit.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Wed Apr  5 16:48:26 2017 Sahel Lucas--Saoudi
** Last update Wed Apr  5 20:02:20 2017 Sahel Lucas--Saoudi
*/

#include <unistd.h>
#include <stdlib.h>
#include "basic.h"
#include "main.h"

int	call_exit(char **argv, t_shell *shell)
{
  if (tablen_(argv) != 1)
    shell->status = getnbr_(argv[1]);
  else
    shell->status = 0;
  exit(shell->status % 255);
}

void	check_exit_pipe(char **command, int **pipefd, int *pid, t_shell *shell)
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
      pipefd[i] = command_loop(pid, command, i, shell);
    i++;
  }
}
