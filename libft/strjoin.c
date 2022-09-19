/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:04:58 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/19 10:07:29 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, (ft_strlen(s1) + 1));
	ft_strlcat(result, s2, (ft_strlen(s2) + ft_strlen(s1) + 1));
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (result);
}
