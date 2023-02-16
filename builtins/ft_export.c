/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:23:48 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/16 02:36:37 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_env(void) 
{
  extern char **environ;
  int i;

  i = 0;
  while (environ[i] != NULL)
  {
    printf("%s\n ", environ[i]);
    i++;
  }
  return ;
}

void ft_export(char **args)
{
    char    *value;
    char    *env_string;

    value = NULL;
    if (args[1] != NULL)
    {
        value = ft_strchr(args[1], '=');
        if (value)
        {
            *value = '\0';
            value++;
            env_string = malloc(ft_strlen(args[1]) + ft_strlen(value) + 2);
            ft_strcpy(env_string, args[1]);
            ft_strcat(env_string, "=");
            ft_strcat(env_string, value);
        }
    }
    if (!args[1])
        print_env();
    return ;
}