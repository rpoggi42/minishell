/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:16:40 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/07 16:14:16 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char    *check_echo(char *args, int i, int j, char *tmp)
{
    int quotes;
    int quote;

    quotes = 0;
    quote = 0;
    while (args[++i])
    {
        if(args[i] == '\"' && quote % 2 == 0)
            quotes++;
        else if(args[i] == '\'' && quotes % 2 == 0)
            quote++;
        else if((args[i] == '\"' && quote % 2 == 1) || 
                (args[i] == '\'' && quotes % 2 == 1))
                    tmp[j++] = args[i];
        else
            tmp[j++] = args[i];
    }
    return (tmp);
}

void ft_echo_one(char *args, int i, int j, int size)
{
    char *tmp;

    tmp = malloc(size * sizeof(char));
    if (!tmp)
        return;
    tmp[j] = '\0';
    printf("%s", check_echo(args, i, j, tmp));
    free(tmp);
    return ;
}