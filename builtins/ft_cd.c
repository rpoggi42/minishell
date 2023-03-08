/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:08:19 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/24 18:47:17 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_cd(char *args)
{
	char	*env_path;
	int		cd_ret;

	if (!args || (ft_strcmp(args, "~") == 0))
		env_path = getenv("HOME");
	else if (ft_strcmp(args, "-") == 0)
		env_path = getenv("OLDPWD");
	else
		env_path = args;
	cd_ret = chdir(env_path);
	if (!env_path || cd_ret < 0)
	{
		printf("minishell: cd: %s: No such file or directory\n", args);
		return (0);
	}
	return (1);
}