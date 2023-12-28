/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:50:21 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/27 18:42:16 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// draw the bottom half of the screen with the specified color (ceiling)
static void	draw_floor(t_mlx mini, int color)
{
	int		x;
	int		y;

	y = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ft_pixel_put(&mini, x, y, color);
			x++;
		}
		y++;
	}
}
/*
The function starts by initializing two integer variables, x and y. x is set
to 0, and y is set to half of the screen height (SCREEN_HEIGHT / 2). This
means that the drawing will start from the middle of the screen, which is a
common technique when rendering a scene with a horizon.

The function then enters a nested while loop. The outer loop iterates over
the y-coordinates from the middle of the screen to the bottom. The inner loop
iterates over the x-coordinates from the left to the right of the screen.

Inside the inner loop, the function calls ft_pixel_put to draw a pixel at
the current x and y coordinates with the specified color. It then
increments x. When x has reached the screen width (SCREEN_WIDTH), the inner
loop ends, y is incremented, and the next line of pixels is drawn.

This function effectively fills the lower half of the screen with the
specified color, creating the effect of a floor.

This function assumes that the t_mlx structure has been properly initialized
and that the ft_pixel_put function works as expected.
*/

// draw the upper half of the screen with the specified color (floor)
static void	draw_ceiling(t_mlx mini, int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ft_pixel_put(&mini, x, y, color);
			x++;
		}
		y++;
	}
}

// get the RGB colors in bites
int	get_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue << 0);
}

// fill all the window with the specified colors
void	background(t_mlx mini, int floor_color, int celing_color)
{
	draw_ceiling(mini, celing_color);
	draw_floor(mini, floor_color);
	mlx_put_image_to_window(mini.mlx, mini.mlx_win, mini.img, 0, 0);
}
