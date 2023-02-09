/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:23:48 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/09 13:25:47 by rpoggi           ###   ########.fr       */
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
/*
void ft_export(char **args)
{
    char    *value;
    char    *env_string;
    size_t  env_string_len;

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
            ft_strcat(env_string, "=")            ;
            ft_strcat(env_string, value);
        }
    }
    if (!args[1])
        print_env();
    return ;
}*/
void ft_export(char **args)
{
    char *value = NULL;
    extern  char **environ;
    if (args[1] != NULL)
    {
        value = strchr(args[1], '=');
        if (value)
        {
            *value = '\0';
            value++;
            char *env_var = args[1];
            char *env_value = value;

            char **envp = environ;
            int found = 0;
            int env_var_len = strlen(env_var);
            int env_value_len = strlen(env_value);
            int env_len = env_var_len + env_value_len + 1;
            while (*envp != NULL)
            {
                if (strncmp(*envp, env_var, env_var_len) == 0 && (*envp)[env_var_len] == '=')
                {
                    found = 1;
                    break;
                }
                envp++;
            }
            if (!found)
            {
                int env_count = envp - environ + 1;
                char **new_envp = malloc((env_count + 1) * sizeof(char *));
                memcpy(new_envp, environ, env_count * sizeof(char *));
                char *new_env = malloc(env_len + 1);
                strcpy(new_env, env_var);
                strcat(new_env, "=");
                strcat(new_env, env_value);
                new_envp[env_count - 1] = new_env;
                new_envp[env_count] = NULL;
                environ = new_envp;
            }
            else
            {
                int env_len = strlen(*envp);
                char *new_env = malloc(env_len - env_var_len + env_value_len + 1);
                strcpy(new_env, env_var);
                strcat(new_env, "=");
                strcat(new_env, env_value);
                *envp = new_env;
            }
        }
    }
    if (!args[1])
        print_env();
    return ;
}
