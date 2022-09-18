/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:15:42 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/18 17:06:17 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	file_size(char *path)
{
	int		rd;
	int		fd;
	int		i;
	char	*buffer;

	i = 0;
	buffer = malloc(0);
	fd = open(path, O_RDONLY);
	if (fd < 0 || fd == 2)
		return (0);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, 1);
		if (rd < 0)
			return (0);
		i++;
	}
	close(fd);
	return (i);
}

static	char	**split_map(t_control *control)
{
	char	*aux;
	int		fd;

	aux = malloc(file_size("map.ber"));
	fd = open("map.ber", O_RDONLY);
	read(fd, aux, file_size("map.ber"));
	close(fd);
	fd = open("map.ber", O_RDONLY);
	aux[file_size("map.ber") - 1] = 0;
	control->map = ft_split(aux, '\n');
	close(fd);
	return (control->map);
}

int	check_map_atrb(t_control *control)
{
	int		i;
	int		j;
	char	**aux;

	i = 0;
	aux = split_map(control);
	while (aux[i])
	{
		j = 0;
		while (aux[i][j])
		{
			if (aux[i][j] == 'P')
				control->p++;
			if (aux[i][j] == 'C')
				control->c++;
			if (aux[i][j] == 'E')
				control->e++;
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_frm(t_control *control)
{
	int		i;
	int		j;
	char	**aux;

	i = 0;
	aux = split_map(control);
	while (aux[i])
	{
		j = 0;
		while (aux[i][j])
		{
			if (aux[0][j] != '1')
			{
				ft_putstr_fd("Error: the map must be surrounded by walls\n", 2);
				exit(0);
			}
			j++;
			control->width = j;
		}
		i++;
		control->height = i;
	}
	printf("H: (%d) W: (%d)\n", control->height, control->width);
	if (control->height == control->width)
	{
		ft_putstr_fd("Error: map isn't rectangular\n", 2);
		exit(0);
	}
	return (0);
}

int	check_error(t_control *control)
{
	if (control->p != 1)
	{
		ft_putstr_fd("Error: there must be only 1 player\n", 2);
		exit(0);
	}
	if (control->c < 1)
	{
		ft_putstr_fd("Error: there must be at least 1 collectable\n", 2);
		exit(0);
	}
	if (control->e < 1)
	{
		ft_putstr_fd("Error: there must be at least 1 exit\n", 2);
		exit(0);
	}
	if (control->p != 1 && control->c < 1 && control->e < 1)
	{
		ft_putstr_fd("Error: invalid map\n", 2);
		exit(0);
	}
	return (0);
}
