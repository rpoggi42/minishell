/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:25:00 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/08 10:04:39 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    init_prompt(void)
{
    char    cwd[1024];
    char    *username = getenv("USER");
    char    computername[1024];
    
    if (username != NULL)
        printf("\033[0;31m%s@\033[0m", username);
    if (gethostname(computername, 1024) == 0)
        printf("\033[0;31m%s\033[0m:", computername);
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("\033[0;33m~%s\033[0m", &cwd[12]);   
    return ; 
}

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
    clear_and_history(input, tmp);
    return ;
}