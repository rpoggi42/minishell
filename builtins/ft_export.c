/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:23:48 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/08 13:52:15 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_env(void) 
{
  extern char **environ;
  int i;

  i = 0;
  while (environ[i++] != NULL)
    printf("%s\n ", environ[i]);
}


void set_environment_variable(char *key, char *value)
{
    char buffer[100];
    int i;
    int j;

    i = 0;
    j = 0;
    if (key)
    {
        while (key[i++])
            buffer[i] = key[i];
        buffer[i] = '=';
        i++;
    }
    if (value)
    {
        while (value[i++])
            buffer[i] = value[j++];
    }
    buffer[i] = '\0';
    putenv(buffer);
    return ;
}

void ft_export(char **args)
{
    int i = 1;
    char *key, *value;
    
    while (args[i])
    {
        key = strtok(args[i], "=");
        value = strtok(NULL, "=");
        set_environment_variable(key, value);
        i++;
    }
    if (!args[1])
        print_env();
    return ;
}