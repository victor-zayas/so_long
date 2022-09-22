/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:04:28 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/22 05:17:03 by vzayas-s         ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct s_hook
{
	t_data	data;
	void	*mlx;
	void	*win;
	int		p_y;
	int		p_x;
}	t_hook;

typedef struct s_wall
{
	void	*img;
	int		height;
	int		width;
}	t_wall;

typedef struct s_floor
{
	void	*img;
	int		height;
	int		width;
}	t_floor;

typedef struct s_cllt
{
	void	*img;
	int		height;
	int		width;
}	t_cllt;

typedef struct s_plyr
{
	void	*img;
	int		height;
	int		width;
}	t_plyr;

typedef struct s_exit
{
	void	*img;
	int		height;
	int		width;
}	t_exit;

typedef struct s_all
{
	t_control	control;
	t_data		data;
	t_hook		hook;
	t_floor		floor;
	t_wall		wall;
	t_cllt		cllt;
	t_plyr		plyr;
	t_exit		exit;
}	t_all;

//LIBFT//
int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *str, int c, size_t len);

//SO_LONG//
void	check_map_format(t_control *control);
void	check_fd(int fd);
void	check_map(t_control *control);
void	type_error(t_control *s_control);
int		print_struct(t_control *map);

//MLX//
int		window(t_all *all);
int		key_hook(int keycode, t_all *all);

#endif