/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:00:46 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/16 19:06:11 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*result;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (start > ft_strlen(s))
	{
		*result = '\0';
		return (result);
	}
	while (len > 0 && start < ft_strlen(s))
	{
		result[i] = s[start];
		i++;
		start++;
		len--;
	}
	result[i] = '\0';
	return (result);
}
