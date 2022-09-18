/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:50:21 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/18 17:04:48 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	print_struct(t_control *control)
{
	printf("Player:(%d), Collectable:(%d), Exit:(%d)\n", control->p, control->c, control->e);
	printf("mapa:\n %s", *control->map);
	return (0);
}
