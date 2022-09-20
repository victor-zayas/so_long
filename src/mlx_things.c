/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:29:10 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/20 19:47:48 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

static	int	ft_close_x(void)
{
	exit (0);
	return (0);
}

int	window(t_data *data, t_control *control)
{
	int		y;
	int		x;
	void	*mlx;
	void	*mlx_win;

	y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Tu super vieja");
	while (control->map[y])
	{
		x = 0;
		while (control->map[y][x])
		{
			if (control->map[y][x])
			{
				data->img = mlx_xpm_file_to_image(mlx, "sprites/mesh3.xpm", &data->width, &data->height);
				mlx_put_image_to_window(mlx, mlx_win, data->img, x * 64, y * 64);
			}
			if (control->map[y][x] == '1')
			{
				data->img = mlx_xpm_file_to_image(mlx, "sprites/crystal_wall01.xpm", &data->width, &data->height);
				mlx_put_image_to_window(mlx, mlx_win, data->img, x * 64, y * 64);
			}
			if (control->map[y][x] == 'P')
			{
				data->img = mlx_xpm_file_to_image(mlx, "sprites/merfolk_impaler_water.xpm", &data->width, &data->height);
				mlx_put_image_to_window(mlx, mlx_win, data->img, x * 64, y * 64);
			}
			if (control->map[y][x] == 'C')
			{
				data->img = mlx_xpm_file_to_image(mlx, "sprites/scroll.xpm", &data->width, &data->height);
				mlx_put_image_to_window(mlx, mlx_win, data->img, x * 64, y * 64);
			}
			if (control->map[y][x] == 'E')
			{
				data->img = mlx_xpm_file_to_image(mlx, "sprites/closed_door.xpm", &data->width, &data->height);
				mlx_put_image_to_window(mlx, mlx_win, data->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
	mlx_hook(mlx_win, 17, 1L << 17, ft_close_x, &mlx);
	mlx_loop(mlx);
	return (0);
}
