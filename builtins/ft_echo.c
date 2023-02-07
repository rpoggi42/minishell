/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:16:40 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/06 18:12:59 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_echo(char **args)
{
    int i;
    int n_option;

    n_option = 0;
    i = 1;
    while (args[i++] && ft_strcmp(args[--i], "-n") == 0)
        n_option = 1;
    while (args[i])
    {
        if (ft_strchr(args[i], 34) != NULL)
        {
            printf("trovato");
            printf("%s", (ft_noquote(args[i])));
        }
        if (args[i] == NULL)
            break;
        ft_putstr_fd(args[i], 1);
        if (args[i + 1])
            ft_putchar_fd(' ', 1);
        i++;
    }
    if (!n_option)
        ft_putchar_fd('\n', 1);
    return (0);
}

char    *ft_noquote(char *strquoted)
{
    int i;
    int j;
    char    *strnoquoted;

    i = 0;
    j = 0;
    strnoquoted = malloc(sizeof(strquoted));
    while (strquoted[i])
    {
        if (strquoted[i] == 34)
            i++;
        else
            strnoquoted[j] = strquoted[i];
        j++;
        i++;
    }
    strnoquoted[j] = strquoted[i];
    return (strnoquoted);

}