/*
** main.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed Apr  5 20:16:13 2017 Sahel Lucas--Saoudi
** Last update Fri May 19 13:17:09 2017 Sahel Lucas--Saoudi
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<signal.h>
#include	<sys/ioctl.h>
#include	<termios.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<curses.h>
#include	<term.h>
#include	"edit.h"
#include	"main.h"
#include	"basic.h"
#include	"globing.h"
#include	"alias.h"
#include	"history.h"

void		prompt(int nb)
{
  if (isatty(0) == 1)
    {
      printf("%03i >", nb);
      fflush(stdout);
    }
}

void		catch(int signal)
{
  write(1, "\n", 1);
  prompt(signal + 128);
  return ;
}

t_shell		*set_shell(char **env)
{
  t_shell	*shell;

  shell = malloc(sizeof(t_shell));
  if (!shell)
    exit(84);
  shell->alias = NULL;
  shell->path = NULL;
  shell->history = NULL;
  shell->status = 0;
  shell->sh = getcwd(NULL, 0);
  shell->env = create_env(env);
  shell->oldpwd = getvar(shell->env, "OLDPWD=*");
  shell->pwd = getvar(shell->env, "PWD=*");
  shell->home = getvar(shell->env, "HOME=*");
  shell->id_command = 0;
  shell->idmax = 0;
  shell->exit = 0;
  return (shell);
}

int		free_shell(t_shell *shell)
{
  int		return_value;

  return_value = shell->status % 255;
  free_tab(shell->env);
  free_tab(shell->alias);
  free_tab(shell->path);
  free_tab(shell->history);
  free(shell->pwd);
  free(shell->oldpwd);
  free(shell->home);
  free(shell->sh);
  free(shell);
  return (return_value);
}

int			main(int __attribute__ ((unused)) ac,
			     __attribute__ ((unused)) char **av, char **env)
{
  t_shell		*shell;
  struct termios	new;
  struct termios	save;
  t_key			keys;
  int			pos;

  shell = set_shell(env);
  pos = found_term(env);
  if (isatty(0) == 1 && pos == -1)
    {
      dprintf(2, "No variable term set.\n");
      return (1);
    }
  if (isatty(0) == 1 && (tgetent(NULL, &env[pos][5]) < 0 || tcgetattr(0, &new) < 0 || tcgetattr(0, &save) < 0))
    {
      dprintf(2, "Cannot set new Term.\n");
      return (1);
    }
  new.c_lflag &= ~(ICANON | ECHO);
  if (isatty(0) == 1 && tcsetattr(0, TCSANOW, &new) == -1)
    {
      dprintf(2, "Cannot set new attribute.\n");
      return (1);
    }
  if (isatty(0) == 1 && ini_keys(&keys, &env[pos][5]) == 84)
    {
      dprintf(2, "Cannot get keys.\n");
      return (1);
    }
  signal(2, catch);
  keys.shell = shell;
  if (isatty(0) == 1)
    shell->command = loop_read(&keys);
  else
    shell->command = getnextline_(0);
  while (shell->command && shell->exit == 0)
    {
      shell->command = globing(shell->command, shell);
      shell->status = 0;
      if (put_minimalist(shell) != 0)
	return (84);
      if (shell->command && *(shell->command) && !check_flexibility(shell))
      {
	tcsetattr(0, TCSANOW, &save);
	manage_command(shell);
	tcsetattr(0, TCSANOW, &new);
      }
	if (shell->exit == 0)
	{
	  if (add_to_history(shell->command, shell))
	  {
	    tcsetattr(0, TCSANOW, &save);
	    return (free_shell(shell));
	  }
	  free(shell->command);
	  if (isatty(0) == 1)
	    shell->command = loop_read(&keys);
	  else
	    shell->command = getnextline_(0);
	}
    }
  if (isatty(0) == 1 && shell->exit == 0)
    write(1, "\n", 1);
  tcsetattr(0, TCSANOW, &save);
  return (free_shell(shell));
}
