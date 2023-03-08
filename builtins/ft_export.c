/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:23:48 by rpoggi            #+#    #+#             */
/*   Updated: 2023/03/01 03:21:28 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_analyzer_input(char **input, char **envp)
{
  int i;
  char **new_input;
  char *variable_name;

  i = 0;
  new_input = ft_split(input[1], '=');
  variable_name = new_input[0];

  while (envp[i])
  {
    if (variable_name[ft_strlen(variable_name + 1)] == '+' &&
      ft_strncmp(ft_split(envp[i], '=')[0], variable_name, ft_strlen(ft_split(envp[i], '=')[0])) == 0)
    {
      printf("sono nell'if del +\n");
      envp[i] = ft_strcat(envp[i], new_input[1]);
      return (NULL);
    }
    else if (ft_strcmp(variable_name, ft_split(envp[i], '=')[0]) == 0)
    {
      if (!new_input[1] || ft_strlen(new_input[1]) == 0)
      {
        free(envp[i]);
        envp[i] = ft_strjoin(variable_name, "=");
        return (NULL);
      }
      free(envp[i]);
      envp[i] = ft_strjoin(variable_name, "=");
      envp[i] = ft_strjoin(envp[i], new_input[1]);
      return (NULL);
    }
    i++;
  }
  if (!new_input[1])
    return (ft_strjoin(variable_name, "=\'\'"));
  variable_name = ft_strjoin(variable_name, "=");
  return (ft_strjoin(variable_name, new_input[1]));
}

char **envp_cop(char **envp, int envp_size, int i)
{
  char **envp_copy;

  envp_copy = NULL;
  while (envp[envp_size] != NULL)
      envp_size++;
  envp_copy = malloc(((envp_size) * sizeof(char *)));
  if (envp_copy == NULL)
    printf("Errore nell'allocazione della memoria del'env\n");
  while (i < envp_size)
  {
      envp_copy[i] = ft_strdup(envp[i]);
      if (envp_copy[i] == NULL)
        printf("Errore copia elemento\n");
      i++;
  }
  envp_copy[envp_size + 1] = NULL;
  return (envp_copy);
}

char **ft_add_envp(char **envp, char **input)
{
  int envp_size;

  envp_size = 0;
  while (envp[envp_size])
    envp_size++;
  envp[envp_size] = ft_analyzer_input(input, envp);
  envp[envp_size + 1] = NULL;
  return (envp);
}