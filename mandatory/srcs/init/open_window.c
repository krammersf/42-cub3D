/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:53:33 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/27 14:51:46 by fde-carv         ###   ########.fr       */
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

/*
This function is used to initialize a new window using the MiniLibX library.
The function takes five parameters: a pointer to a `t_mlx` structure, the width
and height of the screen, and a string for the window description.

The function starts by initializing the MiniLibX library with the `mlx_init`
function. The returned pointer is stored in the `mlx` field of the `map`
structure.

Next, the function creates a new window with the `mlx_new_window` function.
The parameters for this function are the pointer to the MiniLibX library, the
width and height of the window, and the window description. The returned pointer
is stored in the `mlx_win` field of the `map` structure.

After creating the window, the function creates a new image with the
`mlx_new_image` function. The parameters for this function are the pointer to
the MiniLibX library and the width and height of the image. The returned pointer
is stored in the `img` field of the `map` structure.

Finally, the function gets the game address of the image with the
`mlx_get_game_addr` function. The parameters for this function are the pointer
to the image and pointers to the bits per pixel, line length, and endian of the
image. The returned pointer is stored in the `addr` field of the `map` structure,
and the bits per pixel, line length, and endian are stored in their respective
fields of the `map` structure.
*/
