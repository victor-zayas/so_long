/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:29:10 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/22 05:33:09 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

static	int	ft_close_x(void)
{
	exit (0);
	return (0);
}

static	int	ft_close_esc(int keycode)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

int	window(t_all *all)
{
	int		y;
	int		x;

	y = 0;
	int igriega = 1;
	int equis = 1;
	igriega *= 64;
	igriega *= all->control.height;
	equis *= 64;
	equis *= all->control.width;
	all->data.mlx = mlx_init();
	all->data.win = mlx_new_window(all->data.mlx, equis, igriega, "Demasiado Largo: El Videojuego");
	while (all->control.map[y])
	{
		x = 0;
		while (all->control.map[y][x])
		{
			all->floor.img = mlx_xpm_file_to_image(all->data.mlx, "sprites/xpm/mesh3.xpm", &all->floor.width, &all->floor.height);
			mlx_put_image_to_window(all->data.mlx, all->data.win, all->floor.img, x * 64, y * 64);
			if (all->control.map[y][x] == '1')
			{
				all->wall.img = mlx_xpm_file_to_image(all->data.mlx, "sprites/xpm/crystal_wall01.xpm", &all->wall.width, &all->wall.height);
				mlx_put_image_to_window(all->data.mlx, all->data.win, all->wall.img, x * 64, y * 64);
			}
			else if (all->control.map[y][x] == 'P')
			{
				all->hook.p_x = x;
				all->hook.p_y = y;
				all->plyr.img = mlx_xpm_file_to_image(all->data.mlx, "sprites/xpm/merfolk_impaler_water.xpm", &all->plyr.width, &all->plyr.height);
				mlx_put_image_to_window(all->data.mlx, all->data.win, all->plyr.img, x * 64, y * 64);
			}
			else if (all->control.map[y][x] == 'C')
			{
				all->cllt.img = mlx_xpm_file_to_image(all->data.mlx, "sprites/xpm/scroll.xpm", &all->cllt.width, &all->cllt.height);
				mlx_put_image_to_window(all->data.mlx, all->data.win, all->cllt.img, x * 64, y * 64);
			}
			else if (all->control.map[y][x] == 'E')
			{
				all->exit.img = mlx_xpm_file_to_image(all->data.mlx, "sprites/xpm/closed_door.xpm", &all->exit.width, &all->exit.height);
				mlx_put_image_to_window(all->data.mlx, all->data.win, all->exit.img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
	mlx_key_hook(all->data.win, key_hook, &all);
	mlx_hook(all->data.win, 17, 1L << 17, ft_close_x, &all->data.mlx);
	mlx_hook(all->data.win, 2, 1L << 0, ft_close_esc, &all->data.mlx);
	mlx_loop(all->data.mlx);
	return (0);
}

int	key_hook(int keycode, t_all *all)
{
	if (keycode == 13)
	{
		mlx_clear_window(all->data.mlx, all->data.win);
		mlx_put_image_to_window(all->hook.data.mlx, all->hook.data.win, all->hook.data.img, (all->hook.p_x + 1) * 64, (all->hook.p_y + 1) * 64);
	}
	return (0);
}
