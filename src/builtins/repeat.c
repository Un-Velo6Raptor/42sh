/*
** repeat.c for 42sh in /home/angevil124/prog/PSU/PSU_2016_42sh
** 
** Made by Benoit Hoffman
** Login   <benoit.hoffman@epitech.eu>
** 
** Started on  Mon May 15 12:46:54 2017 Benoit Hoffman
** Last update Mon May 15 13:06:25 2017 Benoit Hoffman
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"basic.h"
#include	"main.h"

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
	  dprintf(2, "Badly formed number.\n");
	  return (-1);
	}
      i += 1;
    }
  return (0);
}

int		call_repeat(char **cmd, t_shell *shell)
{
  int		loop;
  char		**tab;
  int		i;

  i = 0;
  if (check_nb(cmd[1], cmd[2]) == -1)
    return (1);
  loop = getnbr_(cmd[1]);
  tab = malloc(sizeof(char *) * (tablen_(cmd) - 1));
  if (!tab)
    return (1);
  while (cmd[i + 2])
    {
      tab[i] = strdup(cmd[i + 2]);
      i += 1;
    }
  tab[i] = NULL;
  i = 0;
  while (loop > i)
    {
      exec_manager(tab, shell);
      i += 1;
    }
  return (0);
}
