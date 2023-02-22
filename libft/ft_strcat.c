/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 17:42:38 by ybarbier          #+#    #+#             */
/*   Updated: 2023/02/21 22:33:02 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t src_len;
	size_t dest_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);

    if (dest == NULL || src == NULL)
        return (NULL);
    while (i < src_len)
	{
        dest[dest_len + i] = src[i];
		i++;
    }

    dest[dest_len + src_len] = '\0';

    return dest;
}

