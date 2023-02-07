/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:30:17 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/06 17:50:51 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>

void    display_prompt(void);
void    init_prompt(void);
int		ft_cd(char *args);
int     ft_echo(char **args);
char    *ft_noquote(char *strquoted);
#endif