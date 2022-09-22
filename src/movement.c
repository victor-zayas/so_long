/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:22:05 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/22 18:30:55 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

int	check_cllt(t_all *all)
{
	if (all->count.c == all->control.c)
		return (1);
	return (0);
}

static	int	movement(t_all *all, int x, int y)
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

static	int	vertical_mv(int keycode, t_all *all, int x, int y)
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

static	int	horizontal_mv(int keycode, t_all *all, int x, int y)
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
