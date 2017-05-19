/*
** repeat.c for 42sh in /home/angevil124/prog/PSU/PSU_2016_42sh
**
** Made by Benoit Hoffman
** Login   <benoit.hoffman@epitech.eu>
**
** Started on  Mon May 15 12:46:54 2017 Benoit Hoffman
** Last update Fri May 19 11:36:16 2017 Benoit Hoffman
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"basic.h"
#include        "main.h"

static int	check_nb(char **tab)
{
  int		i;

  if (!tab[1] || !tab[2])
    {
      dprintf(2, "repeat: Too few arguments.\n");
      return (-1);
    }
  i = 0;
  while (tab[1][i])
    {
      if ((tab[1][i] < '0' || tab[1][i] > '9') && (tab[1][i] != '+' && tab[1][i] != '-'))
	{
	  dprintf(2, "repeat: Badly formed number.\n");
	  return (-1);
	}
      i += 1;
    }
  return (0);
}

static void	cat_cmd(t_shell *shell, char *cmd)
{
  strcat(shell->command, cmd);
  strcat(shell->command, " ");
}

int		call_repeat(char **cmd, t_shell *shell)
{
  int		i;
  int		len;

  len = 0;
  i = 2;
  
  if (check_nb(cmd) == -1)
    return (1);
  while (cmd[i])
    len += strlen_(cmd[i++]) + 1;
  free(shell->command);
  shell->command = malloc(sizeof(char) * (len + 1));
  memset(shell->command, 0, len + 1);
  if (!shell->command)
    return (1);
  len = getnbr_(cmd[1]);
  i = 1;
  while (cmd[++i])
    cat_cmd(shell, cmd[i]);
  i = 0;
  while (len > i)
    {
      manage_command(shell);
      i += 1;
    }
  return (shell->status);
}
