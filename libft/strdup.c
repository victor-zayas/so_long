/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:10:37 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/19 10:10:51 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

char	*ft_strdup(const char *s)
{
	char	*p;

	p = malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (p);
	ft_strlcpy(p, s, ft_strlen(s) + 1);
	return (p);
}
