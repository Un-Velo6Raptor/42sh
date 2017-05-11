/*
** lexer.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed Apr  5 20:17:58 2017 Sahel Lucas--Saoudi
** Last update Thu May 11 12:47:08 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>
#include "main.h"
#include "basic.h"
#include "alias.h"

void	exec_manage(char **tab, t_shell *shell)
{
  int	*fd;
  char	**file_name;
  char	**av;
  char	*buffer;

  file_name = take_redir(tab, 1);
  if (check_filename(file_name))
    {
      shell->status = 1;
      return ;
    }
  av = take_redir(tab, 0);
  av = alias(av, shell);
  if (!av || !*av)
    {
      putstr_("Invalid null command.\n", 2);
      shell->status = 1;
      return ;
    }
  reset01(0);
  buffer = NULL;
  fd = get_fd(file_name, &buffer);
  setup_redir(buffer, fd, file_name);
  exec_manager(av, shell);
  end_manage(fd, file_name, av, tab);
}

static void	send_to_exec(char **argv, int argv_i, t_shell *shell)
{
  if (*argv[argv_i] && howmany_(argv[argv_i], ' ') +
		       howmany_(argv[argv_i], '\t') !=
		       strlen_(argv[argv_i]))
  {
    if (sp_len_(argv[argv_i], '|') != strlen_(argv[argv_i]))
      exec_pipe_manager(argv, argv_i, shell);
    else
      exec_manage(parse__redir(argv[argv_i]), shell);
  }
}

void	lexer(char **argv, t_shell *shell)
{
  int	argv_i;
  char	**new;
  int	new_i;

  argv_i = 0;
  while (argv[argv_i])
  {
    new_i = 0;
    new = parse_and_or(argv[argv_i]);
    send_to_exec(new, new_i, shell);
    new_i = 1;
    while (check_next(shell->status, new[new_i]))
    {
      new_i += 1;
      send_to_exec(new, new_i, shell);
      new_i += 1;
    }
    free_tab(new);
    argv_i++;
  }
}
