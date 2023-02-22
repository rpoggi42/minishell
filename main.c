/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:42:52 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/22 15:00:04 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *init_prompt(char *username, char *str)
{
    char    *cwd;
    size_t  cwd_len;

    cwd = getcwd(NULL, 0);
    if (!cwd)
        return (NULL);
    cwd_len = ft_strlen(cwd);
    str = malloc(sizeof(char) * (ft_strlen(username) * cwd_len + 15));
    if (!str)
        return (NULL);
    if (username != NULL)
    {
        str = ft_strcat(str, "\033[0;31m");
        str = ft_strcat(str, username);
        str = ft_strcat(str, "@\033[0m");
    }
    str = ft_strcat(str, "\033[0;32m~");
    str = ft_strcat(str, &cwd[12]);
    str = ft_strcat(str, "\033[0m$: ");
    return (str); 
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
	(void)argv;
    char    *prompt;
    char    *input;
    char    *stringa;

    
    while (1)
    {
        prompt = NULL;
        stringa = init_prompt(getenv("LOGNAME"), prompt);
        input = malloc(sizeof(char) * 1024);
        input = readline(stringa);
            add_history(input);
        if (ft_strlen(input) == 0)
        {
            free(input);
            continue;
        }
        else
        {
            display_prompt(input, envp);
        }
        free(input);
        free(prompt);
    }
    return 0;
}
