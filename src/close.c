/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:23:34 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/22 21:33:45 by vzayas-s         ###   ########.fr       */
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

void	close_win(t_all *all)
{
	mlx_hook(all->data.win, 17, 1L << 17, ft_close_x, &all->data.mlx);
	mlx_hook(all->data.win, 2, 1L << 0, ft_close_esc, &all->data.mlx);
}
