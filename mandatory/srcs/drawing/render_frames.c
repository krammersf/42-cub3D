/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:05:09 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 13:35:14 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		game->delta_dist_x = 1e20;
	else
		game->delta_dist_x = fabs(1.0 / game->ray_dir_x);
	if (game->ray_dir_y == 0)
		game->delta_dist_y = 1e20;
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
}

/*
  Main function that compiles many 3D important functions. Draws background,
  walls, set move and rotation speed, margin and player movement.
*/
int	render_frames_total(void *arg)
{
	t_game	*game;
	int		x;

	game = arg;
	get_bite_floor_color(game->map_ptr);
	get_bite_ceiling_color(game->map_ptr);
	background(*game->mini_ptr, game->map_ptr->c_color_bites,
		game->map_ptr->f_color_bites);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		render_frames_1(game, &x);
		render_frames_2(game, &x);
		x++;
	}
	fps(game);
	game->move_speed = game->frame_time * 2.5;
	game->rot_speed = game->frame_time * 1.1;
	game->move_margin = 0.5;
	move_player(game);
	return (0);
}
