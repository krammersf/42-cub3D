/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:05:09 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/29 17:00:39 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// gets the color of the floor int bites and stores it in t_map
void	get_bite_floor_color(t_map *map)
{
	t_rgb	*floor;

	floor = &map->floor_colors;
	map->f_color_bites = get_rgb(floor->red, floor->green, floor->blue);
}

// gets the color of the ceiling int bites and stores it in t_map
void	get_bite_ceiling_color(t_map *map)
{
	t_rgb	*ceiling;

	ceiling = &map->ceiling_colors;
	map->c_color_bites = get_rgb(ceiling->red, ceiling->green, ceiling->blue);
}

// raycasting function to render the frames
void	render_frames_1(t_game *game, int *x)
{
	game->camera_x = 2 * *x / (double)SCREEN_WIDTH - 1;
	game->ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
	game->ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
	game->map_x = (int)game->pos_x;
	game->map_y = (int)game->pos_y;
	if (game->ray_dir_x == 0)
		game->delta_dist_x = 1e30;
	else
		game->delta_dist_x = fabs(1.0 / game->ray_dir_x);
	if (game->ray_dir_y == 0)
		game->delta_dist_y = 1e30;
	else
		game->delta_dist_y = fabs(1.0 / game->ray_dir_y);
	game->hit = '0';
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x - game->map_x) * game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->pos_x) * \
			game->delta_dist_x;
	}
}

/*
  It calculates the properties of each vertical strip of the screen that
  needs to be drawn, checks if the ray has hit a wall, calculates the
  properties of the wall that was hit and draws a vertical wall on the screen
*/
void	render_frames_2(t_game *game, int *x)
{
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->pos_y - game->map_y) * game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->pos_y) * \
			game->delta_dist_y;
	}
	if (game->map_x != 0 && game->map_y != 0)
		check_hit(game);
	calculate_walls(game);
	draw_walls(game, x);
	draw_walls2(game, x);
	draw_walls3(game, x);
	draw_walls4(game, x);
}
