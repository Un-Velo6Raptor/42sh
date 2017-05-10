/*
** globing.c for PSU_2016_42sh in /home/sahel/rendu/PSU/PSU_2016_42sh
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 10 11:26:04 2017 Sahel Lucas--Saoudi
** Last update Wed May 10 14:07:37 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

char	*take_word(char *str)
{
  char	*word;
  int	i;

  i = 0;
  word = malloc(strlen(str) + 1);
  while (str && str[i] && str[i] != ' ')
  {
    word[i] = str[i];
    i++;
  }
  word[i] = '\0';
  return (word);
}

int	is_inhib(char *str, int i)
{
  if (i > 0 && str[i - 1] == '\\')
    return (1);
  return (0);
}

char	*globing(char *command, t_shell *shell)
{
  char	*new_command;
  int	idx;
  int	nidx;
  char	*var;
  char	*varname;
  char	ret_value[10];

  idx = 0;
  nidx = 0;
  sprintf(ret_value, "%d", shell->status);
  new_command = malloc(strlen(command) + 1);
  if (!new_command || !command)
    return (command);
  while (command[idx])
  {
    if (command[idx] == '\\')
      idx++;
    else if (!is_inhib(command, idx) && command[idx] == '$')
      {
	varname = take_word(&command[idx + 1]);
	    varname = add_char(varname, 2, "=*");
	    var = getvar(shell->env, varname);
	    if (var)
	      {
		new_command[nidx] = '\0';
		new_command = realloc(new_command, strlen(new_command) + strlen(var) + 1);
		strcat(new_command, var);
		idx += strlen(varname) - 2;
		nidx += strlen(var);
	      }
	    else
	      {
		if (command[idx + 1] && command[idx + 1] == '?')
		  {
		    new_command[nidx] = '\0';
		    new_command = add_char(new_command, strlen(ret_value), ret_value);
		    nidx += strlen(ret_value);
		    idx++;
		  }
		else
		  new_command[nidx++] = '$';
	      }
      }
    else
      new_command[nidx++] = command[idx];
    idx++;
  }
  new_command[nidx] = '\0';
  return (new_command);
}
