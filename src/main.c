/*
** main.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed Apr  5 20:16:13 2017 Sahel Lucas--Saoudi
** Last update Mon Apr 24 16:08:09 2017 Sahel Lucas--Saoudi
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "main.h"
#include "basic.h"

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
  shell->env = create_env(env);
  shell->oldpwd = getvar(shell->env, "OLDPWD=*");
  shell->pwd = getvar(shell->env, "PWD=*");
  shell->home = getvar(shell->env, "HOME=*");
  return (shell);
}

void		free_shell(t_shell *shell)
{
  free_tab(shell->env);
  free_(shell->pwd);
  free_(shell->oldpwd);
  free_(shell->home);
}

int		main(int __attribute__ ((unused)) ac,
		     char __attribute__ ((unused)) **av, char **env)
{
  t_shell	*shell;
  char		*tmp;

  if (isatty(0) == 1)
    write(1, "$$$ >", 5);
  shell = set_shell(env);
  signal(2, catch);
  while ((shell->command = getnextline_(0)))
    {
      shell->status = 0;
      tmp = getvar(shell->env, "PATH=*");
      shell->path = parse_(tmp, ':');
      free_(tmp);
      if (shell->command && *(shell->command) && !check_flexibility(shell))
	manage_command(shell);
      free_tab(shell->path);
      free_(shell->command);
      prompt(shell->status % 255);
    }
  free_shell(shell);
  if (isatty(0) == 1)
    write(1, "\n", 1);
  return (shell->status % 255);
}
