/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:25:00 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/22 17:31:15 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void    display_prompt(char *input, char **envp)
{
    char    **tmp;
    int i;

    i = 0;    
    tmp = ft_split(input, ' ');
    if (ft_execution(tmp, "/bin/", envp) == 0)
        ;
    else if (ft_execution(tmp, "/usr/bin/", envp) == 0)
        ;
    else if (ft_execution(tmp,"/usr/local/bin/", envp) == 0)
        ;
    else    
        printf("STO ESEGUENDO UNA BUILTIN\n");
    while (tmp[i])
    {
        free(tmp[i]);
        i++;
    }
    free(tmp);
    return ;
}