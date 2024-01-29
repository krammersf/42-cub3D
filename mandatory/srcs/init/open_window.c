/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:53:33 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/08 18:38:44 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// creats a window using mlx functions
void	open_window(t_mlx *map, int screen_width,
				int screen_height, char *window_description)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, screen_width,
			screen_height, window_description);
	map->img = mlx_new_image(map->mlx, screen_width, screen_height);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel,
			&map->line_length, &map->endian);
}
