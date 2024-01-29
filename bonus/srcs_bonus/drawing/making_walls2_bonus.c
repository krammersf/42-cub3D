/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_walls2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:18:52 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/29 17:34:11 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
  Calculates the properties of each vertical strip of the screen that needs
  to be drawn, including the height of the line, the start and end points
  for drawing the line, the texture coordinates, and the step size for moving
  through the texture.
*/
void	calculate_walls(t_game *game)
{
	game->line_height = (int)(SCREEN_HEIGHT / game->perp_wall_dist);
	game->draw_start = -game->line_height / 2 + SCREEN_HEIGHT / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + SCREEN_HEIGHT / 2;
	if (game->draw_end >= SCREEN_HEIGHT)
		game->draw_end = SCREEN_HEIGHT - 1;
	if (game->side == '0')
		game->map_ptr->wall_x = game->pos_y + \
			game->perp_wall_dist * game->ray_dir_y;
	else
		game->map_ptr->wall_x = game->pos_x + \
			game->perp_wall_dist * game->ray_dir_x;
	game->map_ptr->wall_x -= floor((game->map_ptr->wall_x));
	game->texture_x = (int)(game->map_ptr->wall_x * (double)TEX_WIDTH);
	if (game->side == '0' && game->ray_dir_x > 0)
		game->texture_x = TEX_WIDTH - game->texture_x - 1;
	if (game->side == '1' && game->ray_dir_y < 0)
		game->texture_x = TEX_WIDTH - game->texture_x - 1;
	game->map_ptr->step = 1.0 * TEX_HEIGHT / game->line_height;
	game->map_ptr->tex_pos = (game->draw_start - \
		(double)SCREEN_HEIGHT / 2 + (double)game->line_height / 2) * \
			game->map_ptr->step;
}

/*
  Draws a vertical strip of the screen by looping through each pixel in
  the line on the screen, determining which texture to use based on the
  direction of the ray and the side of the wall that was hit, getting the
  color of the appropriate pixel from the texture, and drawing the pixel on
  the screen.
*/
void	draw_walls(t_game *game, int *x)
{
	int	y;
	int	tex_y;

	y = game->draw_start;
	while (y <= game->draw_end)
	{
		tex_y = (int)game->map_ptr->tex_pos & (TEX_HEIGHT - 1);
		game->map_ptr->tex_pos += game->map_ptr->step;
		if (game->hit == 'D')
			ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
				ft_pixel_get(&game->txt_ptr[door], game->texture_x, tex_y));
		else if (game->hit == 'f' && game->ray_dir_x > 0)
			wall_change(game, x, y, tex_y);
		else if (game->hit == 'b')
			time_change(game, x, y, tex_y);
		else if (game->side == '0' && game->ray_dir_x > 0)
			draw_pixel_south(game, x, y, tex_y);
		else if (game->side == '0' && game->ray_dir_x < 0)
			draw_pixel_north(game, x, y, tex_y);
		else if (game->side == '1' && game->ray_dir_y > 0)
			draw_pixel_east(game, x, y, tex_y);
		else if (game->side == '1' && game->ray_dir_y < 0)
			draw_pixel_west(game, x, y, tex_y);
		y++;
	}
}

void	draw_walls3(t_game *game, int *x)
{
	int	y;
	int	tex_y;

	y = game->draw_start;
	if (game->hit == 'f')
	{
		while (y <= game->draw_end)
		{
			tex_y = (int)game->map_ptr->tex_pos & (TEX_HEIGHT - 1);
			game->map_ptr->tex_pos += game->map_ptr->step;
			if (game->side == '0' && game->ray_dir_x > 0)
				wall_change(game, x, y, tex_y);
			else if (game->side == '0' && game->ray_dir_x < 0)
				wall_change(game, x, y, tex_y);
			else if (game->side == '1' && game->ray_dir_y > 0)
				wall_change(game, x, y, tex_y);
			else if (game->side == '1' && game->ray_dir_y < 0)
				wall_change(game, x, y, tex_y);
			y++;
		}
	}
}

void	draw_walls4(t_game *game, int *x)
{
	int	y;
	int	tex_y;

	y = game->draw_start;
	if (game->hit == 'b')
	{
		while (y <= game->draw_end)
		{
			tex_y = (int)game->map_ptr->tex_pos & (TEX_HEIGHT - 1);
			game->map_ptr->tex_pos += game->map_ptr->step;
			if (game->side == '0' && game->ray_dir_x > 0)
				time_change(game, x, y, tex_y);
			else if (game->side == '0' && game->ray_dir_x < 0)
				time_change(game, x, y, tex_y);
			else if (game->side == '1' && game->ray_dir_y > 0)
				time_change(game, x, y, tex_y);
			else if (game->side == '1' && game->ray_dir_y < 0)
				time_change(game, x, y, tex_y);
			y++;
		}
	}
}
