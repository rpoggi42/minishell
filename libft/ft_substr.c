/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:09:28 by rpoggi            #+#    #+#             */
/*   Updated: 2023/02/08 10:53:44 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if ((int)start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((int)len > ft_strlen(s))
		len = ft_strlen(s);
	sub = (char *) malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (0);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start && j < len)
			sub[j++] = s[i];
	}
	sub[j] = 0;
	return (sub);
}
