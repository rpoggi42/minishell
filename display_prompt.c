/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:25:00 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/07 13:33:21 by rpoggi           ###   ########.fr       */
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

void    display_prompt(void)
{
    char *input;
    char    **tmp;
    int i;
    
    i = 1;
    init_prompt()  ;
    input = readline("$ ");
    tmp = ft_split(input, ' ');
    if (!input)
    {
        free(input);
        return ;
    }
    if (ft_strcmp(input, "clear") == 0)
        system("clear");
    else if (ft_strcmp(tmp[0], "cd") == 0)
        ft_cd(tmp[1]);
    else if (ft_strcmp(tmp[0], "echo") == 0)
    {
        while (tmp[i])
        {
            ft_echo(tmp[i], -1, 0);
            printf("%c", ' ');
            i++;
        }
        printf("%c", '\n');
    }
    add_history(input);
    free(input);
    return ;
}