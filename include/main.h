/*
** main.h for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Fri Mar 24 10:58:31 2017 Sahel Lucas--Saoudi
** Last update Fri Apr 28 17:04:10 2017 Sahel Lucas--Saoudi
*/

#ifndef MAIN_H_
# define MAIN_H_

typedef struct	s_shell
{
  char		**env;
  char		**path;
  char		*command;
  char		*oldpwd;
  char		*pwd;
  char		*home;
  int		fd0;
  int		status;
}		t_shell;

char		**parse_(char *, char);
char		**set_var(char *, char *);
char		**create_env(char **);
char		**c_dico(int, ...);
char		**take_redir(char **, int);
char		**parse__redir(char *);
char		*getvar(char **, char *);
char		*epur(char *);
char		*add_str(char *, int, char *);
char		*add_char(char *, int, char *);
char		*add_and_free(char *, int, char *);
char		*getnextline_(int);
char		*without_before_(char *, char);
char		*only_before(char *, char);
char		*double_redir(char *);
char		*stralloc_(char *, char *);
int		set_path(char **, t_shell *);
int		validity(char **);
int		setnenv(char **, t_shell *);
int		call_cd(char **, t_shell *);
int		call_setenv(char **, t_shell *);
int		call_exit(char **, t_shell *);
int		call_env(char **, t_shell *);
int		call_unsetenv(char **, t_shell *);
int		is_valid(char *);
int		check_filename(char **);
int		howmany_(char *, char);
int		check_flexibility(t_shell *);
int		good_filename(char *, int *, int *);
int		good_file(char *);
void		free_tab(char **);
void		manage_command(t_shell *);
void		lexer(char **, t_shell *);
void		exec_manager(char **, t_shell *);
void		error_handling(int);
void		showtab_(char **);
void		exec_manage(char **, t_shell *);
void		exec_pipe_manager(char **, int, t_shell *);
void		setup_redir(char *, int *, char **);
void		reset01(int);
void		close_(int);
void		end_manage(int *, char **, char **, char **);
int		check_file(char *, char);

#endif /* !MAIN_H_ */