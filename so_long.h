/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:04:28 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/17 19:33:33 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_control
{
	char	**map;
	int		width;
	int		height;
	int		error;
	int		p;
	int		c;
	int		e;
}	t_control;

//LIBFT//
int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
void	ft_putstr_fd(char *s, int fd);

//SO_LONG//
int		start_strt(t_control *init);
int		print_struct(t_control *map);
int		check_map_atrb(t_control *map);
int		check_map_frm(t_control *map);
int		check_error(t_control *map);

#endif