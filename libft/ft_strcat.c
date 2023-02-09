/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:40:36 by rpoggi            #+#    #+#             */
/*   Updated: 2021/10/12 09:40:50 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)

{
	int	is;
	int	id;

	is = 0;
	id = 0;
	while (dest[id] != '\0')
	{
		id++;
	}
	while (src[is] != '\0')
	{
		dest[id] = src[is];
		is++;
		id++;
	}
	dest[id] = '\0';
	return (dest);
}