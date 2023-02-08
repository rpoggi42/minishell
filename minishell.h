/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:30:17 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/08 10:04:25 by rpoggi           ###   ########.fr       */
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

void    display_prompt(int i, char *input);
void    init_prompt(void);
int		ft_cd(char *args);
void    ft_echo_one(char *args, int i, int j, int size);
int    protection(char *input, char **tmp);
void    clear_and_history(char *input, char **tmp);
char    *check_echo(char *args, int i, int j, char *tmp);
void    ft_pwd(void);
#endif