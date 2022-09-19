/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:07:05 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/19 10:07:18 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	while (src[count] != '\0')
	{
		count++;
	}
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (count);
}
