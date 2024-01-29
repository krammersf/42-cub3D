/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_walls1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:11:26 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/29 18:38:18 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// gets the fps of the game
void	fps(t_game *game)
{
	game->old_time = game->time;
	game->time = get_actual_time();
	game->frame_time = (game->time - game->old_time) / 1000.0;
	if (game->tps <= 1.0)
	{
		game->fps++;
		game->tps += game->frame_time;
	}
	else
	{
		game->fps = 0;
		game->tps = 0.0;
	}
}

void	door_adjustment2(t_game *game)
{
	game->side_dist_x -= game->delta_dist_x / 2;
	if (game->side_dist_x > game->side_dist_y)
	{
		game->side_dist_y += game->delta_dist_y;
		game->map_y += game->step_y;
		game->side = '1';
		game->hit = '1';
	}
	else if (game->hit == 'U')
	{
		game->hit = '0';
		game->side_dist_x -= game->delta_dist_x / 2;
	}
	game->side_dist_x += game->delta_dist_x;
}

// adjusts the hit information for when it hits a door
void	door_adjustment(t_game *game)
{
	game->hit = game->map_ptr->world_map[game->map_x][game->map_y];
	if (game->side == '0')
		door_adjustment2(game);
	else if (game->side == '1')
	{
		game->side_dist_y -= game->delta_dist_y / 2;
		if (game->side_dist_y > game->side_dist_x)
		{
			game->side_dist_x += game->delta_dist_x;
			game->map_x += game->step_x;
			game->side = '0';
			game->hit = '1';
		}
		else if (game->hit == 'U')
		{
			game->hit = '0';
			game->side_dist_y -= game->delta_dist_y / 2;
		}
		game->side_dist_y += game->delta_dist_y;
	}
}

void	check_hit_2(t_game *game)
{
	if (game->side_dist_x < game->side_dist_y)
	{
		game->side_dist_x += game->delta_dist_x;
		game->map_x += game->step_x;
		game->side = '0';
	}
	else
	{
		game->side_dist_y += game->delta_dist_y;
		game->map_y += game->step_y;
		game->side = '1';
	}
}

/* 
  Determines the next horizontal or vertical boundary that the ray intersects,
  checks if the ray has hit a wall, and calculates the distance to the wall.
  Performs a DDA algorithm.
*/
void	check_hit(t_game *game)
{
	while (game->hit == '0')
	{
		check_hit_2(game);
		if (game->map_ptr->world_map[game->map_x][game->map_y] == '1')
			game->hit = '1';
		else if (game->map_ptr->world_map[game->map_x][game->map_y] == 'D'
			|| game->map_ptr->world_map[game->map_x][game->map_y] == 'U')
			door_adjustment(game);
		else if (game->map_ptr->world_map[game->map_x][game->map_y] == 'a')
			game->hit = 'a';
		else if (game->map_ptr->world_map[game->map_x][game->map_y] == 'b')
			game->hit = 'b';
		else if (game->map_ptr->world_map[game->map_x][game->map_y] == 'f')
			game->hit = 'f';
	}
	if (game->side == '0')
		game->perp_wall_dist = (game->side_dist_x - game->delta_dist_x);
	else
		game->perp_wall_dist = (game->side_dist_y - game->delta_dist_y);
}
