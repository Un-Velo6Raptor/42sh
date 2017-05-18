/*
** globing.h for PSU_2016_42sh in /home/sahel/rendu/PSU/PSU_2016_42sh
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Wed May 10 11:44:32 2017 Sahel Lucas--Saoudi
** Last update Wed May 17 13:45:38 2017 Benoit Hoffman
*/

#ifndef			GLOBING_H_
# define		GLOBING_H_

# include		"main.h"

typedef struct		s_globing
{
  char			*new_command;
  char			*var;
  char			*varname;
  char			ret_value[10];
}			t_globing;

int			init_globing(char *command, t_globing *globings,
				     int *idx, int *nidx);
void			modif_command_globing(t_globing *globings,
					      int *nidx, char *command,
					      int *idx);
char			*globing(char *, t_shell *);
char			*file_globing(char *);

#endif			/* !GLOBING_H_ */
