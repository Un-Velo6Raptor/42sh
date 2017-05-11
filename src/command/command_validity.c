/*
** command_validity.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Thu Apr 20 22:27:34 2017 Sahel Lucas--Saoudi
** Last update Wed May 10 14:56:27 2017 Sahel Lucas--Saoudi
*/

#include "basic.h"
#include "main.h"

static int	is_separator(char c)
{
  if (c == '|' || c == ';')
    return (1);
  return (0);
}

static int	check_one_pipe(char *command, int i)
{
  int		j;

  j = i;
  i++;
  j--;
  while (command && command[i] && (command[i] == ' ' || command[i] == '\t'))
    i++;
  while (command && j >= 0 && command[j] && (command[j] == ' ' ||
					     command[j] == '\t'))
    j--;
  if (j < 0 || !command[i] || is_separator(command[i]) ||
      is_separator(command[j]))
    return (1);
  return (0);
}

static int	pipe_validity(char *command)
{
  int		i;

  i = 0;
  while (command && command[i])
    {
      if (!match(&command[i], "||*") &&
	command[i] == '|' && check_one_pipe(command, i))
	return (1);
      if (match(&command[i], "||*"))
	i++;
      i++;
    }
  return (0);
}

static int	 check_flex_redir(char *command)
{
  if (match(command, "*<<<*") || match(command, "*>>>*"))
    return (1);
  return (0);
}

int	check_flexibility(t_shell *shell)
{
  if (pipe_validity(shell->command) || check_flex_redir(shell->command))
    {
      putstr_("Invalid null command.\n", 2);
      shell->status = 1;
      return (1);
    }
  return (0);
}
