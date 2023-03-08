/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:25:00 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/28 23:28:37 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **ft_path(char *pathvar)
{
    char    **matrix;
    int i;
    int j;

    i = 0;

    matrix = ft_split(pathvar, ':');
    while (matrix[i])
    {
        j = ft_strlen(matrix[i]);
        matrix[i][j] = '/';
        matrix[i][j + 1] = '\0';
        i++;
    }

    return (matrix);
}

int    ft_execution(char **input, char *bin, char **envp) 
{
    pid_t   pid;
    char    *path;

    path = malloc(ft_strlen(bin) + ft_strlen(input[0]) + 1);
    ft_strcpy(path, bin);
    ft_strcat(path, input[0]);
    
    pid = fork();
    if (pid == 0)
    {
        if (execve(path, input, envp) != 0)
            return (1);
    }
    else
    {
        if (wait(NULL) == -1)
            exit(1);
    }
    free(path);
    return (0);   
}


void    path_abs(char *input, char **envp)
{
    pid_t   pid;
    char    **tmp;
    int i;

    i = 0;
    tmp = ft_split(input, ' ');
    while (tmp[i])
        i++;
    tmp[i] = NULL;
    pid = fork();
    if (pid == 0)
    {
        if (execve(tmp[0], tmp, envp) != 0)
            return ;
    }
    else
    {
        if (wait(NULL) == -1)
            exit(1);
    }
    return ;
}

int ft_builtin(char **input, char *arg, char **envp)
{
    int i;

    i = 0;
    while (envp[i])
        i++;
    if (ft_strcmp(input[0], "cd") == 0)        
        return (ft_cd(arg));
    else if (ft_strcmp(input[0], "echo") == 0)
        return (ft_echo(arg, -1, 0));
    else if (ft_strcmp(input[0], "export") == 0)
    {
        if (input[1])
        {
            /*ft_analyzer_input(input, char **envp)

            if (ft_strcmp(envp[i - 1], input[1]) == 0)
                return (1);*/
            ft_add_envp(envp, input);
        }
        else
            path_abs("/bin/env", envp);
        return (1);
    }
    else
        printf("altre robe\n");
    return (0);
}

void    display_prompt(char *input, char **envp)
{
    char    **tmp;
    int i;
    char    **path;
    int j;

    i = 0;
    j = 0;
    tmp = ft_split(input, ' ');
    path = ft_path(getenv("PATH"));
    if (!ft_builtin(tmp, tmp[1], envp))
    {
        while (path[j])
        {
            if (ft_execution(tmp, path[j], envp) == 0)
                break;
            j++;
        }
        if (input[0] == '/')
            return (path_abs(input, envp));
    }
    while (tmp[i])
    {
        free(tmp[i]);
        i++;
    }
    free(tmp);
    return ;
}