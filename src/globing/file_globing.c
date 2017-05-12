/*
** file_globing.c for PSU_2016_42sh in /home/sahel/rendu/PSU/PSU_2016_42sh
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Fri May 12 12:54:13 2017 Sahel Lucas--Saoudi
** Last update Fri May 12 12:54:13 2017 Sahel Lucas--Saoudi
*/

#include <string.h>
#include <stdio.h>
#include <regex.h>
#include "globing.h"

char	*file_globing(char *path)
{
  char	**dir;
  const char	*glob_ope = "(\\?|\\*|\\[|\\])+";
  int	i;
  regex_t	ope_reg;

  regcomp(&ope_reg, glob_ope, REG_NOSUB | REG_EXTENDED);
  i = 0;
  dir = parse_(path, '/');
  while (dir[i])
  {
    if (!regexec(&ope_reg, dir[i], 0, NULL, 0))
    {
      printf("%s\n", dir[i]);
      printf("NEED to be changed\n");
    }
    i++;
  }
  return (path);
}
