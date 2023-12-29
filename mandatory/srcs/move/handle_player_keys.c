/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:11:05 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/29 17:59:11 by fde-carv         ###   ########.fr       */
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

// rotates the player to the right by a certain angle, determined by `rot_speed`
void	rotate_p_right(t_game *game)
{
	game->old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(-game->rot_speed) \
			- game->dir_y * sin(-game->rot_speed);
	game->dir_y = game->old_dir_x * sin(-game->rot_speed) \
			+ game->dir_y * cos(-game->rot_speed);
	game->old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(-game->rot_speed) \
		- game->plane_y * sin(-game->rot_speed);
	game->plane_y = game->old_plane_x * \
		sin(-game->rot_speed) + game->plane_y * \
		cos(-game->rot_speed);
}
/*
The function first stores the current direction of the player (dir_x) in
old_dir_x. Then it updates dir_x and dir_y to rotate the player's direction to
the right by rot_speed radians. This is done using the rotation matrix formula
for 2D space, which involves the cos and sin of the rotation angle. The negative
sign in -game->rot_speed indicates a clockwise rotation, which corresponds to a
right turn.

The function then does a similar operation on plane_x and plane_y, which
represent the player's field of view or the direction the camera is pointing.
This ensures that when the player turns, their view of the game world turns with
them.

In summary, this function rotates the player and their view to the right by an
angle of rot_speed radians. The rotation is done using the standard rotation
matrix formula for 2D space, which involves the cos and sin of the rotation angle
*/

// rotates the player to the left by a certain angle, determined by `rot_speed`
void	rotate_p_left(t_game *game)
{
	game->old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(game->rot_speed) \
		- game->dir_y * sin(game->rot_speed);
	game-> dir_y = game->old_dir_x * \
		sin(game->rot_speed) + game->dir_y * \
		cos(game->rot_speed);
	game->old_plane_x = game->plane_x;
	game-> plane_x = game->plane_x * \
		cos(game->rot_speed) - game->plane_y * \
		sin(game->rot_speed);
	game->plane_y = game->old_plane_x * \
		sin(game->rot_speed) + game->plane_y * \
		cos(game->rot_speed);
}
/*
The selected code is a function written in C, named rotate_p_left. This function is designed to handle the rotation of a player in a game to the left. It takes a single parameter: a pointer game to a t_game structure that holds the game state.

The function first stores the current direction of the player (dir_x) in old_dir_x. Then it updates dir_x and dir_y to rotate the player's direction to the left by rot_speed radians. This is done using the rotation matrix formula for 2D space, which involves the cosine and sine of the rotation angle. The absence of a negative sign in game->rot_speed indicates a counterclockwise rotation, which corresponds to a left turn.

The function then does a similar operation on plane_x and plane_y, which presumably represent the player's field of view or the direction the camera is pointing. This ensures that when the player turns, their view of the game world turns with them.

In summary, this function rotates the player and their view to the left by an angle of rot_speed radians. The rotation is done using the standard rotation matrix formula for 2D space, which involves the cosine and sine of the rotation angle.
*/
