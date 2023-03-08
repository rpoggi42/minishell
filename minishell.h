/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:30:17 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/28 23:30:02 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct env_var {
    char* name;
    char* value;
} env_var_t;

typedef struct env_list {
    env_var_t* var;
    struct env_list* next;
} env_list_t;

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
int     ft_cd(char *args);
int     ft_echo(char *args, int i, int j);
char    *check_echo(char *args, int i, int j, char *tmp);
void    ft_pwd(void);
int     ft_execution(char **input, char *bin, char **envp);
int ft_export(char **input, char **envp);
void    print_env(void);
char    **ft_path(char *pathvar);
void    path_abs(char *input, char **envp);
int     ft_builtin(char **input, char *arg, char **envp);
char* get_env_var(char* var_name) ;
void  set_env_var(const char *var_name, const char *value);
char **envp_cop(char **envp, int envp_size, int i);
void    free_matrix(char **matrix);
char **ft_add_envp(char **envp, char **input);
char  *ft_analyzer_input(char **input, char **envp);
#endif