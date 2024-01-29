/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:22:37 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/21 14:29:53 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// Aplies the Bresenham's line algorithm to draw the line of the player
void	draw_line_l_player(t_game *game, t_littlemap littlemap, int x2, int y2)
{
	if (littlemap.x_center < x2)
		littlemap.sx = 1;
	else
		littlemap.sx = -1;
	if (littlemap.y_center < y2)
		littlemap.sy = 1;
	else
		littlemap.sy = -1;
	while (littlemap.x_center != x2 || littlemap.y_center != y2)
	{
		littlemap.e2 = 2 * littlemap.err;
		if (littlemap.e2 > -littlemap.dy)
		{
			littlemap.err -= littlemap.dy;
			littlemap.x_center += littlemap.sx;
		}
		if (littlemap.e2 < littlemap.dx)
		{
			littlemap.err += littlemap.dx;
			littlemap.y_center += littlemap.sy;
		}
		ft_pixel_put(game->mini_ptr, littlemap.x_center + 1, \
			littlemap.y_center + 1, 0xFE1010);
	}
}

// draws the square of the little player in the little map
void	draw_square_little_player(t_mlx *mlx, int x, int y, int side_length)
{
	int	i;
	int	j;
	int	color;

	color = 0xFF0000;
	i = 0;
	while (i < side_length)
	{
		j = 0;
		while (j < side_length)
		{
			ft_pixel_put(mlx, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// draws the little player in the little map
void	draw_little_player(t_game *game)
{
	t_littlemap		mp;
	int				x2;
	int				y2;

	init_littlemap_struct(&mp, game);
	x2 = mp.x_center + (game->dir_y * mp.line_length);
	y2 = mp.y_center + (game->dir_x * mp.line_length);
	draw_square_little_player(game->mini_ptr, game->littlemap_ptr->x_center, \
		game->littlemap_ptr->y_center, SCREEN_HEIGHT * 0.00500);
	mp.dx = fabs(x2 - mp.x_center);
	mp.dy = fabs(y2 - mp.y_center);
	mp.err = mp.dx - mp.dy;
	draw_line_l_player(game, mp, x2, y2);
	free(mp.little_map);
}
