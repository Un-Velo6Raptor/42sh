/*
** test.c for  in /home/sahel/rendu/PSU/PSU_2016_42sh
**
** Made by Sahel Lucas--Saoudi
** Login   <sahel.lucas-saoudi@epitech.eu>
**
** Started on  Fri May 12 14:05:48 2017 Sahel Lucas--Saoudi
** Last update Fri May 12 14:11:57 2017 Sahel Lucas--Saoudi
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int	main(int ac, char **av)
{
  int	pid;

  pid = fork();
  if (pid == 0)
    {
      while (1)
	{
	  printf("Je suis en vie <3\n");
	  usleep(10000);
	}
    }
  else
    {
      printf("Je kill stop je fils\n");
      kill(pid, SIGSTOP);
      read(0, NULL, 1);
      printf("Je kill Cont le fils\n");
      kill(pid, SIGCONT);
      sleep(4);
      kill(pid, 1);
      wait(NULL);
    }
}
