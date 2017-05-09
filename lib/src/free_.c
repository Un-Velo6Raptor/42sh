/*
** free_.c for lib in /home/sahel/rendu/PSU/PSU_2016_minishell2/lib/src
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Sat Apr  8 17:16:49 2017 Sahel Lucas--Saoudi
** Last update Sat Apr  8 17:16:52 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>

void	free_(void *str)
{
  if (str)
    free(str);
}
