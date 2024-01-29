/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_walls_color_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:59:18 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 12:01:57 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_change_color(t_game *game)
{
	game->red = 55;
	game->green = 110;
	game->blue = 110;
}

void	change_color2(t_game *game)
{
	game->red += rand() % 11;
	if (game->red >= 256)
		game->red -= 255;
	game->green += rand() % 11;
	if (game->green >= 256)
		game->green -= 255;
	game->blue += rand() % 11;
	if (game->blue >= 256)
		game->blue -= 255;
}

void	change_color(t_game *game)
{
	if (game->press_k == 1)
		change_color2(game);
}

void	draw_walls2(t_game *game, int *x)
{
	int	y;

	y = game->draw_start;
	while (y <= game->draw_end)
	{
		if (game->hit == 'a')
		{
			change_color(game);
			if (game->side == '0' && game->ray_dir_x > 0)
				ft_pixel_put(game->mini_ptr, *x, y, \
					get_rgb(game->red, game->green, game->blue));
			else if (game->side == '0' && game->ray_dir_x < 0)
				ft_pixel_put(game->mini_ptr, *x, y, \
					get_rgb(game->red, game->green, game->blue));
			else if (game->side == '1' && game->ray_dir_y > 0)
				ft_pixel_put(game->mini_ptr, *x, y, \
					get_rgb(game->red, game->green, game->blue) * 0.995);
			else if (game->side == '1' && game->ray_dir_y < 0)
				ft_pixel_put(game->mini_ptr, *x, y, \
					get_rgb(game->red, game->green, game->blue) * 0.995);
		}
		y++;
	}
}
