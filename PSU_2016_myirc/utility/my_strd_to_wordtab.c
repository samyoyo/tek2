/*
** my_strd_to_wordtab.c for my_strd_to_wordtab in /home/guillaume2.roux/bootstrap/PSU_2016_myirc/utility/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun  1 11:41:06 2017 Guillaume Roux
** Last update Thu Jun  1 11:43:14 2017 Guillaume Roux
*/

#include "../include/utility.h"

int	find_chara(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}

int	my_countdword(char *str, char *delim)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      while (find_chara(delim, str[i]) == 1 && str[i] != '\0')
	i++;
      if (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	{
	  while (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	    i++;
	  j++;
	}
    }
  return (j);
}

char	**my_putstr_indtab(char *str, char **tab, char *delim)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (str[i] != '\0')
    {
      while (find_chara(delim, str[i]) == 1 && str[i] != '\0')
	i++;
      if (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	{
	  while (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	    {
	      tab[j][k] = str[i];
	      k++;
	      i++;
	    }
	  tab[j][k] = '\0';
	  k = 0;
	  j++;
	}
    }
  return (tab);
}

char	**my_countdchar(char *str, char **tab, char *delim)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (str[i] != '\0')
    {
      while (find_chara(delim, str[i]) == 1 && str[i] != '\0')
	i++;
      if (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	{
	  while (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	    {
	      i++;
	      k++;
	    }
	  tab[j] = malloc((k + 1) * sizeof(char));
	  k = 0;
	  j++;
	}
    }
  tab[j] = NULL;
  return (tab);
}

char	**my_strd_to_wordtab(char *str, char *delim)
{
  int	i;
  char	**tab;

  if (str == NULL || str[0] == '\0')
    return (NULL);
  i = my_countdword(str, delim);
  tab = malloc((i + 1) * sizeof(*tab));
  tab = my_countdchar(str, tab, delim);
  tab = my_putstr_indtab(str, tab, delim);
  return (tab);
}
