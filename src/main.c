/*
** main.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed Apr  5 20:16:13 2017 Sahel Lucas--Saoudi
<<<<<<< HEAD
** Last update Tue May 16 13:54:46 2017 Sahel Lucas--Saoudi
=======
** Last update Tue May 16 11:12:37 2017 Benoit Hoffman
>>>>>>> e7cba7e900b7b974f7191f7db8ee869bfc45f0b9
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "main.h"
#include "basic.h"
#include "globing.h"
#include "alias.h"
#include "history.h"

static void	prompt(int nb)
{
  if (isatty(0) == 1)
    {
      putnbr_(nb);
      write(1, " >", 2);
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
    exit (84);
  shell->alias = NULL;
  shell->path = NULL;
  shell->status = 0;
  shell->sh = getcwd(NULL, 0);
  shell->env = create_env(env);
  shell->oldpwd = getvar(shell->env, "OLDPWD=*");
  shell->pwd = getvar(shell->env, "PWD=*");
  shell->home = getvar(shell->env, "HOME=*");
  return (shell);
}

int		free_shell(t_shell *shell)
{
  int		return_value;

  return_value = shell->status % 255;
  free_tab(shell->env);
  free_tab(shell->alias);
  free_tab(shell->path);
  free(shell->pwd);
  free(shell->oldpwd);
  free(shell->home);
  free(shell->sh);
  free(shell);
  return (return_value);
}

int		main(int __attribute__ ((unused)) ac,
		     __attribute__ ((unused)) char **av, char **env)
{
  t_shell	*shell;

  if (isatty(0) == 1)
    write(1, "$$$ >", 5);
  shell = set_shell(env);
  signal(2, catch);
  shell->command = getnextline_(0);
  while (shell->command)
    {
      shell->command = globing(shell->command, shell);
      shell->status = 0;
      if (put_minimalist(shell) != 0)
	return (84);
      if (shell->command && *(shell->command) && !check_flexibility(shell))
	manage_command(shell);
      add_to_history(shell->command, shell);
      free_(shell->command);
      prompt(shell->status % 255);
      shell->command = getnextline_(0);
    }
  if (isatty(0) == 1)
    write(1, "\n", 1);
  return (free_shell(shell));
}
