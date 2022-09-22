/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:29:10 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/22 18:25:51 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	save_image(t_all *all)
{
	all->floor.img = mlx_xpm_file_to_image(all->data.mlx,
			"sprites/xpm/mesh3.xpm", &all->floor.width, &all->floor.height);
	all->wall.img = mlx_xpm_file_to_image(all->data.mlx,
			"sprites/xpm/crystal_wall01.xpm",
			&all->wall.width, &all->wall.height);
	all->plyr.img = mlx_xpm_file_to_image(all->data.mlx,
			"sprites/xpm/merfolk_impaler_water.xpm",
			&all->plyr.width, &all->plyr.height);
	all->cllt.img = mlx_xpm_file_to_image(all->data.mlx,
			"sprites/xpm/scroll.xpm", &all->cllt.width, &all->cllt.height);
	all->exit.img = mlx_xpm_file_to_image(all->data.mlx,
			"sprites/xpm/closed_door.xpm", &all->exit.width, &all->exit.height);
}

void	sprites(t_all *all)
{
	int		y;
	int		x;

	y = 0;
	while (all->control.map[y])
	{
		x = 0;
		while (all->control.map[y][x])
		{
			mlx_put_image_to_window(all->data.mlx, all->data.win,
				all->floor.img, x * 64, y * 64);
			if (all->control.map[y][x] == '1')
				mlx_put_image_to_window(all->data.mlx, all->data.win,
					all->wall.img, x * 64, y * 64);
			else if (all->control.map[y][x] == 'P')
			{
				all->hook.p_x = x;
				all->hook.p_y = y;
				mlx_put_image_to_window(all->data.mlx, all->data.win,
					all->plyr.img, x * 64, y * 64);
			}
			else if (all->control.map[y][x] == 'C')
				mlx_put_image_to_window(all->data.mlx, all->data.win,
					all->cllt.img, x * 64, y * 64);
			else if (all->control.map[y][x] == 'E')
				mlx_put_image_to_window(all->data.mlx, all->data.win,
					all->exit.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
