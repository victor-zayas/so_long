/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:57:19 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/19 17:47:18 by vzayas-s         ###   ########.fr       */
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
	int		fd;

	aux = malloc(sizeof(char) * file_size("map.ber"));
	fd = open("map.ber", O_RDONLY);
	read(fd, aux, file_size("map.ber"));
	close(fd);
	aux[file_size("map.ber") - 1] = '\0';
	control->map = ft_split(aux, '\n');
	return (control->map);
}

int	main(int argc, char **argv)
{
	t_control	control;

	if (argc == 1)
	{
		start_strt(&control);
		open(argv[1], O_RDONLY);
		check_fd(control.fd);
		split_map(&control);
		check_map(&control);
		type_error(&control);
		check_error(&control);
		print_struct(&control);
	}
	else
	{
		printf("Adios\n");
		exit(0);
	}
}
