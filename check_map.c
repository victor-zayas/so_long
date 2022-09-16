/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:15:42 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/16 19:49:00 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int	file_size(char *path)
{
	int		rd;
	int		fd;
	int		i;
	char	*buffer;

	buffer = malloc(0);
	fd = open(path, O_RDONLY);
	rd = 1;
	i = 0;
	while (rd > 0)
	{
		rd = read(fd, buffer, 1);
		i++;
	}
	close(fd);
	return (free(buffer), i);
}

int	check_map(char *map)
{
	char	*aux;
	int		i;
	int		check;

	i = 0;
	aux = map;
	aux = malloc(file_size("map.ber"));
	read(open("map.ber", O_RDONLY), aux, file_size("map.ber"));
	ft_split(map, '\n');
	check = 0;
	while (aux[i])
	{
		if (aux[i] == 'P')
			check++;
		/*else
			perror("There is no PLAYER");*/
		if (aux[i] == 'C')
			check++;
		/*else
			perror("There is no COLLECTABLE");*/
		if (aux[i] == 'E')
		{
			resources->exit++;
			if (rexit > 1)
						
		}
		/*else
			perror("There is no EXIT");*/
		i++;
	}
	if (check < 3)
		printf("invalid");
	return (0);
}
