/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:04:28 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/16 19:25:14 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

//LIBFT//
int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);

//SO_LONG//
int		check_map(const char *map);

#endif