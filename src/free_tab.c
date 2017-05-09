/*
** free_tab.c for minishell2 in /home/sahel/rendu/PSU/PSU_2016_minishell2
** 
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
** 
** Started on  Wed Apr  5 20:26:32 2017 Sahel Lucas--Saoudi
** Last update Wed Apr  5 20:26:44 2017 Sahel Lucas--Saoudi
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	tab_i;

  tab_i = 0;
  while (tab && tab[tab_i])
    free(tab[tab_i++]);
  if (tab)
    free(tab);
}
