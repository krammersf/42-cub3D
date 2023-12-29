/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:50:21 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/29 19:01:40 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// draw the bottom half of the screen with the specified color (floor)
static void	draw_floor(t_mlx *mini, int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ft_pixel_put(mini, x, y, color);
			x++;
		}
		y++;
	}
}

// draw the upper half of the screen with the specified color (ceiling)
static void	draw_ceiling(t_mlx *mini, int color)
{
	int		x;
	int		y;

	y = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ft_pixel_put(mini, x, y, color);
			x++;
		}
		y++;
	}
}

// get the RGB colors in bites
int	get_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

// fill all the window with the specified colors
void	background(t_mlx mini, int floor_color, int ceiling_color)
{
	draw_floor(&mini, floor_color);

	draw_ceiling(&mini, ceiling_color);
	//printf("ceiling_color: %d\n", ceiling_color);
	//printf("floor_color: %d\n", floor_color);
	mlx_put_image_to_window(mini.mlx, mini.mlx_win, mini.img, 0, 0);
}
