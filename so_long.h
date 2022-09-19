/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:04:28 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/19 20:26:25 by vzaya-s          ###   ########.fr       */
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
	char	*name;
	int		width;
	int		height;
	int		error;
	int		fd;
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
//char	**split_map(t_control *control);
void	check_map(t_control *control);
void	check_error(t_control *control);
void	type_error(t_control *s_control);
void	check_fd(int fd);

#endif