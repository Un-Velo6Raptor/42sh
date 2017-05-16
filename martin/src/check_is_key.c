/*
** check_is_key.c for  in /home/januar_m/delivery/PSU/PSU_2016_42sh/martin
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed May 10 17:10:11 2017 Martin Januario
** Last update Fri May 12 17:15:12 2017 Martin Januario
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my.h"

int		check_is_key(t_key *keys, char *rd, int idx)
{
  if (rd[0] == 127 || rd[0] == 8)
    return (1);
  if (strncmp(&keys->key_r[idx], rd, 1) == 0)
    return (1);
  if (strncmp(&keys->key_l[idx], rd, 1) == 0)
    return (1);
  if (strncmp(&keys->key_sup[idx], rd, 1) == 0)
    return (1);
  return (0);
}

int		same_key(t_key *keys, char *str, int *tmp)
{
  int		idx;

  idx = 0;
  if (my_strlen(str) == 1 && (str[0] == 127 || str[0] == 8))
    return ((*tmp != 0) ? 3 : 0);
  if (strcmp(keys->key_l, str) == 0)
    return (-1);
  if (strcmp(keys->key_r, str) == 0)
    return (1);
  if (strcmp(keys->key_sup, str) == 0)
    return ((*tmp != keys->width) ? 2 : 0);
  while (str[idx] != '\0')
    {
      if (strncmp(&keys->key_l[idx], &str[idx], 1) != 0 &&
	  strncmp(&keys->key_r[idx], &str[idx], 1) != 0 &&
	  strncmp(&keys->key_sup[idx], &str[idx], 1) != 0)
	return (0);
      idx++;
    }
  return (-42);
}
