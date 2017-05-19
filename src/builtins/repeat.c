/*
** repeat.c for 42sh in /home/angevil124/prog/PSU/PSU_2016_42sh
**
** Made by Benoit Hoffman
** Login   <benoit.hoffman@epitech.eu>
**
** Started on  Mon May 15 12:46:54 2017 Benoit Hoffman
** Last update Fri May 19 13:14:26 2017 Sahel Lucas--Saoudi
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"basic.h"
#include        "main.h"

int		check_nb(char *nb, char *to_check)
{
  int		i;

  if (!nb || !to_check)
    {
      dprintf(2, "repeat: Too few arguments.\n");
      return (-1);
    }
  i = 0;
  while (nb[i])
    {
      if ((nb[i] < '0' || nb[i] > '9') && (nb[i] != '+' && nb[i] != '-'))
	{
	  dprintf(2, "repeat: Badly formed number.\n");
	  return (-1);
	}
      i += 1;
    }
  return (0);
}

int		call_repeat(char **cmd, t_shell *shell)
{
  int		loop;
  int		i;
  int		len;

  len = 0;
  if (check_nb(cmd[1], cmd[2]) == -1)
    return (1);
  loop = getnbr_(cmd[1]);
  i = 2;
  while (cmd[i])
    {
      len += strlen_(cmd[i]) + 1;
      i += 1;
    }
  free(shell->command);
  shell->command = malloc(sizeof(char) * (len + 1));
  if (!shell->command)
    return (1);
  memset(shell->command, 0, len + 1);
  i = 2;
  while (cmd[i])
    {
      strcat(shell->command, cmd[i]);
      strcat(shell->command, " ");
      i += 1;
    }
  i = 0;
  while (loop > i)
    {
      manage_command(shell);
      i += 1;
    }
  return (shell->status);
}
