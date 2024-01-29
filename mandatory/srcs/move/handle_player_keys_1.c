/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_keys_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:11:05 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 13:49:50 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_walkable(char c)
{
	return (c == '0');
}

/*
  moves the player in the direction they are facing, but only if the position
  they would move to is walkable according to the `world_map`. The distance
  they move is determined by `move_speed`, and the direction is determined by
  `dir_x` and `dir_y`.
*/
void	move_p_forward(t_game *game)
{
	if ((int)(game->pos_x + game->dir_x * game->move_margin) >= 0
		&& (int)(game->pos_y) >= 0)
	{
		if (is_walkable(game->map_ptr->world_map[(int)(game->pos_x + \
			game->dir_x * game->move_margin)][(int)(game->pos_y)]))
			game->pos_x += game->dir_x * game->move_speed;
	}
	if ((int)(game->pos_x) >= 0 && (int)(game->pos_y + game->dir_y *
				game->move_margin) >= 0)
	{
		if (is_walkable(game->map_ptr->world_map[(int)(game->pos_x)] \
			[(int)(game->pos_y + game->dir_y * game->move_margin)]))
			game->pos_y += game->dir_y * game->move_speed;
	}
}

/*
  moves the player in the oposite direction they are facing, but only if the
  position they would move to is walkable according to the `world_map`. The
  distance they move is determined by `move_speed`, and the direction is
  determined by `dir_x` and `dir_y`.
*/
void	move_p_backward(t_game *game)
{
	if ((int)(game->pos_x - game->dir_x * game->move_margin) >= 0
		&& (int)(game->pos_y) >= 0)
	{
		if (is_walkable(game->map_ptr->world_map[(int)(game->pos_x - \
			game->dir_x * game->move_margin)][(int)(game->pos_y)]))
			game->pos_x -= game->dir_x * game->move_speed;
	}
	if ((int)(game->pos_x) >= 0 && (int)(game->pos_y - game->dir_y *
				game->move_margin) >= 0)
	{
		if (is_walkable(game->map_ptr->world_map[(int)(game->pos_x)] \
			[(int)(game->pos_y - game->dir_y * game->move_margin)]))
			game->pos_y -= game->dir_y * game->move_speed;
	}
}

/*
  checks if the positions to the left of the player in the x and y directions
  are walkable, and if they are, it moves the player to those positions.
  this allows the player to slide to the left.
*/
void	move_p_slide_left(t_game *game)
{
	if ((int)(game->pos_x - game->plane_x * game->move_margin) >= 0
		&& (int)(game->pos_y) >= 0)
	{
		if (is_walkable(game->map_ptr->world_map \
		[(int)(game->pos_x - game->plane_x * \
			game->move_margin)][(int)(game->pos_y)]))
			game->pos_x -= game->plane_x * game->move_speed;
	}
	if ((int)(game->pos_x) >= 0 && (int)(game->pos_y - game->plane_y * \
		game->move_margin) >= 0)
	{
		if (is_walkable(game->map_ptr->world_map \
		[(int)(game->pos_x)][(int)(game->pos_y - \
			game->plane_y * game->move_margin)]))
			game->pos_y -= game->plane_y * game->move_speed;
	}
}

/*
  checks if the positions to the right of the player in the x and y directions
  are walkable, and if they are, it moves the player to those positions.
  this allows the player to slide to the right.
*/
void	move_p_slide_right(t_game *game)
{
	if ((int)(game->pos_x + game->plane_x * \
		game->move_margin) >= 0 && (int)(game->pos_y) >= 0)
	{
		if (is_walkable(game->map_ptr->world_map \
		[(int)(game->pos_x + game->plane_x * \
			game->move_margin)][(int)(game->pos_y)]))
			game->pos_x += game->plane_x * game->move_speed;
	}
	if ((int)(game->pos_x) >= 0 && (int)(game->pos_y + game->plane_y * \
		game->move_margin) >= 0)
	{
		if (is_walkable(game->map_ptr->world_map \
		[(int)(game->pos_x)][(int)(game->pos_y \
			+ game->plane_y * game->move_margin)]))
			game->pos_y += game->plane_y * game->move_speed;
	}
}
