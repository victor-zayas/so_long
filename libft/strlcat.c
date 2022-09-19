/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:06:14 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/19 10:07:25 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

size_t	ft_strlcat(char *dest, const char *src, size_t	size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	count;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	count = 0;
	if (size < 1 || size <= dest_len)
		return (src_len + size);
	while (count < (size - dest_len - 1) && src[count])
	{
		dest[dest_len + count] = src[count];
		count++;
	}
	dest[dest_len + count] = '\0';
	return (dest_len + src_len);
}
