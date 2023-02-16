/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:42:52 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/16 03:03:26 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *init_prompt(char *username, char *str)
{
    char    cwd[1024];
    char    computername[1024];

    if (username != NULL)
    {
        str = ft_strcat(str, "\033[0;31m");
        str = ft_strcat(str, username);
        str = ft_strcat(str, "@\033[0m");
    }
    if (gethostname(computername, 1024) == 0)
    {
        str = ft_strcat(str, "\033[0;31m");
        str = ft_strcat(str, computername);
        str = ft_strcat(str, "\033[0m:");
    }
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        str = ft_strcat(str,"\033[0;33m~");
        str = ft_strcat(str, &cwd[12]);
        str = ft_strcat(str, "\033[0m$: ");
    }
    return (str); 
}

int main(void)
{
    char    *prompt;
    char    *input;

    input = malloc(sizeof(char *) * 1024);
    prompt = malloc(sizeof(char *) * 1024);
    prompt = init_prompt(getenv("USER"), prompt);
    while (1)
    {
        input = readline(prompt);
        if (ft_strlen(input) == 0)
        {
            free(input);
            continue;
        }
        else
            display_prompt(0, input);
    }
    return 0;
}
