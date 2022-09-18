/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:57:19 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/18 22:47:29 by vzaya-s          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_control	control;

	if (argc == 2)
	{
	start_strt(&control);
	open(argv[1], O_RDONLY);
	check_fd(control.fd);
	check_map_frm(&control);
	check_map_atrb(&control);
	check_error(&control);
	print_struct(&control);		
	}
	else
	{
		printf("Adios\n");
		exit(0);
	}
}