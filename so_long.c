/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:57:19 by vzayas-s          #+#    #+#             */
/*   Updated: 2022/09/18 17:05:40 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_control	control;

	start_strt(&control);
	check_map_frm(&control);
	check_map_atrb(&control);
	check_error(&control);
	print_struct(&control);
}
