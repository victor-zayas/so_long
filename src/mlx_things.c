/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:29:10 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/22 17:01:05 by vzayas-s         ###   ########.fr       */
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

void	save_image(t_all *all)
{
	all->floor.img = mlx_xpm_file_to_image(all->data.mlx, "sprites/xpm/mesh3.xpm", &all->floor.width, &all->floor.height);
	all->wall.img = mlx_xpm_file_to_image(all->data.mlx, "sprites/xpm/crystal_wall01.xpm", &all->wall.width, &all->wall.height);
	all->plyr.img = mlx_xpm_file_to_image(all->data.mlx, "sprites/xpm/merfolk_impaler_water.xpm", &all->plyr.width, &all->plyr.height);
	all->cllt.img = mlx_xpm_file_to_image(all->data.mlx, "sprites/xpm/scroll.xpm", &all->cllt.width, &all->cllt.height);
	all->exit.img = mlx_xpm_file_to_image(all->data.mlx, "sprites/xpm/closed_door.xpm", &all->exit.width, &all->exit.height);
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
			mlx_put_image_to_window(all->data.mlx, all->data.win, all->floor.img, x * 64, y * 64);
			if (all->control.map[y][x] == '1')
				mlx_put_image_to_window(all->data.mlx, all->data.win, all->wall.img, x * 64, y * 64);
			else if (all->control.map[y][x] == 'P')
			{
				all->hook.p_x = x;
				all->hook.p_y = y;
				mlx_put_image_to_window(all->data.mlx, all->data.win, all->plyr.img, x * 64, y * 64);
			}
			else if (all->control.map[y][x] == 'C')
				mlx_put_image_to_window(all->data.mlx, all->data.win, all->cllt.img, x * 64, y * 64);
			else if (all->control.map[y][x] == 'E')
				mlx_put_image_to_window(all->data.mlx, all->data.win, all->exit.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	key_hook(int keycode, t_all *all)
{
	int	i;
	int	y;
	int	x;

	y = 0;
	x = 0;
	i = 0;
	if (keycode == 0)
		i = horizontal_mv(keycode, all, x, y);
	if (keycode == 1)
		i = vertical_mv(keycode, all, x, y);
	if (keycode == 2)
		i = horizontal_mv(keycode, all, x, y);
	if (keycode == 13)
		i = vertical_mv(keycode, all, x, y);
	if (i == 1)
		sprites(all);
		all->count.p_p++;
	return (1);
}

void	its_finished(t_all *all)
{
	int	i;

	i = 0;
	mlx_destroy_window(all->data.mlx, all->data.win);
	free(all->data.mlx);
	while (all->control.map[i])
	{
		free(all->control.map[i]);
		i++;
	}
	free(all->control.map);
	exit (0);
}

int	check_cllt(t_all *all)
{
	printf("Count.c : (%d), Count.map.c : (%d)\n", all->count.c, all->control.c);
	if (all->count.c == all->control.c)
		return (1);
	return (0);
}

int	movement(t_all *all, int x, int y)
{
	if (all->control.map[y][x] == 'C')
	{
		all->control.map[y][x] = '0';
		all->count.c++;
	}
	if (all->control.map[y][x] == '0' || all->control.map[y][x] == 'C')
		all->control.map[y][x] = 'P';
	if (all->control.map[y][x] == 'E' && check_cllt(all) == 1)
		its_finished(all);
	return (1);
}

int	vertical_mv(int	keycode, t_all *all, int x, int y)
{
	x = all->hook.p_x;
	y = all->hook.p_y;
	if (keycode == 1)
	{
		if (all->control.map[y + 1][x] == '1')
			return (0);
		if (all->control.map[y + 1][x] == 'E' && check_cllt(all) == 0)
			return (0);
		y++;
		movement(all, x, y);
		all->control.map[y - 1][x] = '0';
	}
	if (keycode == 13)
	{
		if (all->control.map[y - 1][x] == '1')
			return (0);
		if (all->control.map[y - 1][x] == 'E' && check_cllt(all) == 0)
			return (0);
		y--;
		movement(all, x, y);
		all->control.map[y + 1][x] = '0';
	}
	return (1);
}

int	horizontal_mv(int	keycode, t_all *all, int x, int y)
{
	x = all->hook.p_x;
	y = all->hook.p_y;
	if (keycode == 0)
	{
		if (all->control.map[y][x - 1] == '1')
			return (0);
		if (all->control.map[y][x - 1] == 'E' && check_cllt(all) == 0)
			return (0);
		x--;
		movement(all, x, y);
		all->control.map[y][x + 1] = '0';
	}
	if (keycode == 2)
	{
		if (all->control.map[y][x + 1] == '1')
			return (0);
		if (all->control.map[y][x + 1] == 'E' && check_cllt(all) == 0)
			return (0);
		x++;
		movement(all, x, y);
		all->control.map[y][x - 1] = '0';
	}
	return (1);
}

void	close_win(t_all *all)
{
	mlx_hook(all->data.win, 17, 1L << 17, ft_close_x, &all->data.mlx);
	mlx_hook(all->data.win, 2, 1L << 0, ft_close_esc, &all->data.mlx);
}
