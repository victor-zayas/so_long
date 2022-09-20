/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:09:04 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/20 12:15:16 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	check_fd(int fd)
{
	if (fd < 0 || fd == 2)
	{
		printf("%d\n", fd);
		close(fd);
		ft_putstr_fd("Error: Invalid fd\n", 2);
		exit(0);
	}
}

static	void	check_error(t_control *control)
{
	if (control->error == 1)
	{
		ft_putstr_fd("Error: there must be only 1 player\n", 2);
		exit(0);
	}
	if (control->error == 2)
	{
		ft_putstr_fd("Error: there must be at least 1 collectable\n", 2);
		exit(0);
	}
	if (control->error == 3)
	{
		ft_putstr_fd("Error: there must be at least 1 exit\n", 2);
		exit(0);
	}
	if (control->error == 4)
	{
		ft_putstr_fd("Error: invalid map\n", 2);
		exit(0);
	}
}

void	type_error(t_control *control)
{
	if (control->p != 1)
	{
		control->error = 1;
		check_error(control);
	}
	if (control->c < 1)
	{
		control->error = 2;
		check_error(control);
	}
	if (control->e < 1)
	{
		control->error = 3;
		check_error(control);
	}
	if (control->p != 1 && control->c < 1 && control->e < 1)
	{
		control->error = 4;
		check_error(control);
	}
}
