/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:50:21 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/22 21:34:26 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	print_struct(t_control *control)
{
	int	i;

	i = 0;
	while (control->map[i])
	{
		printf("%s\n", control->map[i]);
		i++;
	}
	printf("Player:(%d), Collectable:(%d), Exit:(%d)\n",
		control->p, control->c, control->e);
	return (0);
}
