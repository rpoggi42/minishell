/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:25:00 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/16 03:03:41 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    protection(char *input, char **tmp)
{
    if (!input || !tmp)
    {
        free(input);
        free(tmp);
        return (1);
    }
    return (0);
}

void    clear_and_history(char *input, char **tmp)
{
    add_history(input);
    free(tmp);
    free(input);
    return ;
}

void    ft_ls(void) 
{
    pid_t   pid;
    char cwd[1024];
    char *args[] = {"ls", cwd, NULL};

    pid = fork();
    if (pid == 0)
    {   
        if (getcwd(cwd, sizeof(cwd)) == NULL)
            exit(1);
        if (execve("/bin/ls", args, NULL) == -1)
            exit(1);
    }
    else
    {
        if (wait(NULL) == -1)
            exit(1);
    }
    return ;
}


void    display_prompt(int i, char *input)
{
    char    **tmp;
    
    tmp = ft_split(input, ' ');
    if (protection(input, tmp) == 1)
        return ;
    if (ft_strcmp(input, "clear") == 0)
        system("clear");
    else if (ft_strcmp(tmp[0], "cd") == 0)
        ft_cd(tmp[1]);
    else if (ft_strcmp(tmp[0], "echo") == 0)
    {
        while (tmp[++i])
        {
            ft_echo_one(tmp[i], -1, 0, 100);
            printf("%c", ' ');
        }
        printf("%c", '\n');
    }
    else if (ft_strcmp(input, "pwd") == 0)
        ft_pwd();
    else if (ft_strcmp(input, "ls") == 0)
        ft_ls();
    else if (ft_strcmp(tmp[0], "export") == 0)
        ft_export(tmp);
    clear_and_history(input, tmp);
    return ;
}