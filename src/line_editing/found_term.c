/*
** found_term.c for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 10 14:57:49 2017 Martin Januario
** Last update Wed May 10 15:01:36 2017 Martin Januario
*/

#include	<unistd.h>
#include	<string.h>
#include	"my.h"

int		found_term(char **env)
{
  int		idx;

  idx = 0;
  while (env[idx] != NULL)
    {
      if (strncmp(env[idx], "TERM=", 5) == 0)
	return (idx);
      idx++;
    }
  return (-1);
}
