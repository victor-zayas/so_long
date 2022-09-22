/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:15:42 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/22 12:01:08 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	check_map_wall(t_control *control)
{
	int		i;
	int		j;

	i = 0;
	while (control->map[i])
	{
		j = 0;
		while (control->map[i][j])
		{
			if (control->map[i][0] != '1')
			{
				ft_putstr_fd("Error: the map must be surrounded by walls\n", 2);
				exit(1);
			}
			if (control->map[i][control->width - 1] != '1')
			{
				ft_putstr_fd("Error: the map must be surrounded by walls\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static	void	check_map_frm(t_control *control)
{
	int	i;
	int	j;

	i = 0;
	while (control->map[i])
	{
		j = 0;
		while (control->map[i][j])
			j++;
		i++;
	}
	control->height = i;
	control->width = j;
	empty(control);
	if (control->height == control->width)
	{
		ft_putstr_fd("Error: map isn't rectangular\n", 2);
		exit(1);
	}
}

static	void	check_map_atrb(t_control *control)
{
	int		i;
	int		j;

	i = 0;
	while (control->map[i])
	{
		j = 0;
		while (control->map[i][j])
		{
			if (control->map[i][j] == 'P')
				control->p++;
			if (control->map[i][j] == 'C')
				control->c++;
			if (control->map[i][j] == 'E')
				control->e++;
			j++;
		}
		i++;
	}
}

void	check_map_format(t_control *control)
{
	int		i;

	i = ft_strlen(control->name);
	if (control->name[i - 4] != '.' || control->name[i - 3] != 'b'
		|| control->name[i - 2] != 'e' || control->name[i - 1] != 'r')
	{
		ft_putstr_fd("Error: invalid map format\n", 2);
		exit(1);
	}
}

void	check_map(t_control *control)
{
	int	i;
	int	j;

	check_map_frm(control);
	check_map_wall(control);
	check_map_atrb(control);
	type_error(control);
	i = 0;
	while (control->map[i])
	{
		j = 0;
		while (control->map[i][j])
		{
			if (control->map[i][j] != 'P' && control->map[i][j] != 'C'
			&& control->map[i][j] != 'E' && control->map[i][j] != '0'
			&& control->map[i][j] != '1' && control->map[i][j] != '\n')
			{
				ft_putstr_fd("Error: Invalid character in map\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
