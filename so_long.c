/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:57:19 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/22 11:35:55 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	file_size(char *path)
{
	int		rd;
	int		fd;
	int		i;
	char	c;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0 || fd == 2)
		return (0);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
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
	int		i;

	i = 0;
	aux = malloc(sizeof(char) * file_size(control->name));
	read(control->fd, aux, file_size(control->name));
	aux[file_size(control->name) - 1] = '\0';
	while (aux[i])
	{
		if (aux[i] == '\n')
		{
			if (aux[i + 1] && aux[i + 1] == '\n')
			{
				ft_putstr_fd("Error: emptyline in map\n", 2);
				exit(1);
			}
		}
		i++;
	}
	control->map = ft_split(aux, '\n');
	close(control->fd);
	return (free(aux), control->map);
}

int	main(int argc, char **argv)
{
	t_all		all;

	if (argc == 2)
	{
		ft_memset(&all, 0, sizeof(all));
		all.control.fd = open(argv[1], O_RDONLY);
		all.control.name = argv[1];
		check_fd(all.control.fd);
		check_map_format(&all.control);
		split_map(&all.control);
		check_map(&all.control);
		all.data.mlx = mlx_init();
		all.data.win = mlx_new_window(all.data.mlx,
				all.control.width * 64, all.control.height * 64, "so_long");
		save_image(&all);
		sprites(&all);
		mlx_key_hook(all.data.win, key_hook, &all);
		close_win(&all);
		mlx_loop(all.data.mlx);
	}
	else
	{
		ft_putstr_fd("Error: invalid number of arguments\n", 2);
		exit(1);
	}
}
