/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:04:28 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/20 19:46:57 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>	
# include "mlx/mlx.h"

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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

//LIBFT//
int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
void	ft_putstr_fd(char *s, int fd);

//SO_LONG//
int		start_strt(t_control *init);
void	check_map_format(t_control *control);
void	check_fd(int fd);
void	check_map(t_control *control);
void	type_error(t_control *s_control);
int		print_struct(t_control *map);
int		window(t_data *data, t_control *control);

#endif