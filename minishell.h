/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:30:17 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/22 17:20:10 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>
# include <stddef.h>

void    display_prompt(char *input, char **envp);
char    *init_prompt(char *username, char *str);
int		ft_cd(char *args);
void    ft_echo_one(char *args, int i, int j, int size);
int    protection(char *input, char **tmp);
void    clear_and_history(char *input, char **tmp);
char    *check_echo(char *args, int i, int j, char *tmp);
void    ft_pwd(void);
int    ft_execution(char **input, char *bin, char **envp);
void    ft_export(char **args);
void    print_env(void);
#endif