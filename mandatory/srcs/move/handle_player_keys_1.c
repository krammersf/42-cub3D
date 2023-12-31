/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_keys_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:11:05 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/31 12:24:47 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// moves the player in the direction they are facing, but only if the position
// they would move to is walkable according to the `world_map`. The distance
// they move is determined by `move_speed`, and the direction is determined by
// `dir_x` and `dir_y`.
void	move_p_forward(t_game *game)
{
	if (game->map_ptr->world_map[(int)(game->pos_x + \
			game->dir_x * game->move_margin)]
			[(int)(game->pos_y)] == '0')
		game->pos_x += game->dir_x * game->move_speed;
	if (game->map_ptr->world_map[(int)(game->pos_x)] \
			[(int)(game->pos_y + game->dir_y *
			game->move_margin)] == '0')
		game->pos_y += game->dir_y * game->move_speed;
}
/*
The function checks two conditions before moving the player. Both conditions
involve checking the `world_map` array within the `map_ptr` structure of the
`game` object. The `world_map` is a 2D array representing the game world, where
each cell corresponds to a position in the game world and its value indicates
whether the position is walkable or not. In this case, a cell value of `'0'`
seems to indicate a walkable position.

The first condition checks the cell in the direction of the player's current
orientation (`dir_x`, `dir_y`) from their current position (`pos_x`, `pos_y`),
with a certain margin (`move_margin`). If the cell in that direction is walkable,
the player's `pos_x` is updated to move the player in the `dir_x` direction by a
distance of `move_speed`.

The second condition is similar to the first, but checks and updates the `pos_y`
coordinate instead of `pos_x`. This allows the player to move in both the x and
y directions.
*/

// moves the player in the oposite direction they are facing, but only if the
// position they would move to is walkable according to the `world_map`. The
// distance they move is determined by `move_speed`, and the direction is
// determined by `dir_x` and `dir_y`.
void	move_p_backward(t_game *game)
{
	if (game->map_ptr->world_map[(int)(game->pos_x - \
			game->dir_x * game->move_margin)]
			[(int)(game->pos_y)] == '0')
		game->pos_x -= game->dir_x * game->move_speed;
	if (game->map_ptr->world_map[(int)(game->pos_x)] \
			[(int)(game->pos_y - game->dir_y *
			game->move_margin)] == '0')
		game->pos_y -= game->dir_y * game->move_speed;
}

// checks if the positions to the left of the player in the x and y directions
// are walkable, and if they are, it moves the player to those positions.
// This allows the player to slide to the left.
void	move_p_slide_left(t_game *game)
{
	if (game->map_ptr->world_map \
		[(int)(game->pos_x - game->plane_x * \
			game->move_margin)][(int)(game->pos_y)] == '0')
		game->pos_x -= game->plane_x \
			* game->move_speed;
	if (game->map_ptr->world_map \
		[(int)(game->pos_x)][(int)(game->pos_y \
			- game->plane_y * game->move_margin)] == '0')
		game->pos_y -= game->plane_y \
			* game->move_speed;
}
/*
This function is part of a 3D game engine, specifically a part of the player
movement system that handles sliding to the left.

The function starts by checking if the position to the left of the player in
the x-direction is walkable. It does this by subtracting the product of
`game->plane_x` and `game->move_margin` from the player's
current x-position (`game->pos_x`), rounding down to the nearest
whole number, and checking if the corresponding cell in the `world_map` is '0'.
If it is, the function subtracts the product of `game->plane_x` and
`game->move_speed` from the player's current x-position. This moves
the player to the left in the x-direction.

The function then does a similar check for the position to the left of the
player in the y-direction. If the corresponding cell in the `world_map` is '0',
the function subtracts the product of `game->plane_y` and
`game->move_speed` from the player's current y-position
(`game->pos_y`). This moves the player to the left in the y-direction.

The `game->plane_x` and `game->plane_y` values represent
the direction of the plane perpendicular to the player's viewing direction, and
the `game->move_margin` and `game->move_speed` values
control the distance the player moves.
*/

// checks if the positions to the right of the player in the x and y directions
// are walkable, and if they are, it moves the player to those positions.
// This allows the player to slide to the right.
void	move_p_slide_right(t_game *game)
{
	if (game->map_ptr->world_map \
		[(int)(game->pos_x + game->plane_x * \
			game->move_margin)][(int)(game->pos_y)] == '0')
		game->pos_x += game->plane_x \
			* game->move_speed;
	if (game->map_ptr->world_map \
		[(int)(game->pos_x)][(int)(game->pos_y \
			+ game->plane_y * game->move_margin)] == '0')
		game->pos_y += game->plane_y \
			* game->move_speed;
}
