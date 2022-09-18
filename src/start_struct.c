/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:10:30 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/17 19:33:41 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	start_strt(t_control *control)
{
	control->width = 0;
	control->height = 0;
	control->error = 0;
	control->p = 0;
	control->c = 0;
	control->e = 0;
	return (0);
}
