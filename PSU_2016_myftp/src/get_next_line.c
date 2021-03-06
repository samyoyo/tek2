/*
** get_line.c for get_next_line in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon May 15 10:47:14 2017 Guillaume Roux
** Last update Mon May 15 10:59:07 2017 Guillaume Roux
*/

#include "../include/my.h"

void	my_puterr(char *str)
{
  write(2, str, strlen(str));
}

char	*get_next_line(const int fd)
{
  char	*res;
  char	buffer;
  int	a;

  a = read(fd, &buffer, 1);
  if (a == 0 || a == -1)
    return (NULL);
  a = 0;
  res = malloc(sizeof(char) * 10000);
  res[a] = buffer;
  a++;
  while (buffer != '\n' && a < 10000)
    {
      read(fd, &buffer, 1);
      res[a] = buffer;
      a++;
    }
  if (a >= 10000)
    {
      my_puterr("Error in line\n");
      return (NULL);
    }
  res[a - 1] = '\0';
  return (res);
}
