/*
** repeat.c for 42sh in /home/angevil124/prog/PSU/PSU_2016_42sh
** 
** Made by Benoit Hoffman
** Login   <benoit.hoffman@epitech.eu>
** 
** Started on  Mon May 15 12:46:54 2017 Benoit Hoffman
** Last update Fri May 19 09:22:11 2017 Benoit Hoffman
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
  char		**tab;
  char		*arg;
  int		i;
  int		len;


  //printf("cmd is %s\n", shell->command);
  len = 0;
  i = 0;
  while (cmd[i])
    {
      printf(":%s:\n", cmd[i]);
      i += 1;
    }
  fflush(stdout);
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
  i = 0;
  printf("UI\n");
  while (tab[i])
    {
      printf(":::%s:::\n", tab[i]);
      len += strlen_(tab[i]) + 1;
      i += 1;
    }
  tab[i] = NULL;
  free(shell->command);
  shell->command = malloc(sizeof(char) * (len + 1));
  if (!shell->command)
    return (1);
  i = 0;
  while (tab[i])
    {
      strcat(shell->command, tab[i]);
      strcat(shell->command, " ");
      i += 1;
    }
  printf("je vais envoyer :%s:\n", shell->command);
  i = 0;
  while (loop > i)
    {
      manage_command(shell);
      //exec_manager(tab, shell); //ls -l /dev a manage command au fait
      i += 1;
    }
  free_tab(tab);
  return (shell->status);
}
