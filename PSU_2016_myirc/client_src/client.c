/*
** client.c for client in /home/guillaume2.roux/rendu/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri May 26 15:16:34 2017 Guillaume Roux
** Last update Fri Jun  2 11:27:04 2017 Guillaume Roux
*/

#include "../include/client.h"

void	init_fct(fd_set *fd_read, fd_set *fd_write, int fd)
{
  FD_ZERO(fd_read);
  FD_ZERO(fd_write);
  FD_SET(0, fd_read);
  FD_SET(1, fd_write);
  FD_SET(fd, fd_read);
  FD_SET(fd, fd_write);
}

t_client	*init_client(t_client *client)
{
  client = malloc(sizeof(t_client));
  client->nickname = NULL;
  client->channel = NULL;
  client->to_server = NULL;
  client->to_client = NULL;
  client->fd = 0;
  return (client);
}

void	check_isset(fd_set *fd_read, fd_set *fd_write, int fd, t_client *client)
{
  if (FD_ISSET(0, fd_read))
    read_input(client);
  if (FD_ISSET(fd, fd_read))
    read_server(fd, client);
  if (FD_ISSET(1, fd_write))
    write_client(client);
  if (FD_ISSET(fd, fd_write))
    write_server(fd, client);
}
