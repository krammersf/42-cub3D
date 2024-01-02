/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_keys_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:30:18 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/31 19:53:33 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	game->dir_y = game->old_dir_x * sin(game->rot_speed) \
			+ game->dir_y * cos(game->rot_speed);
	game->old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(game->rot_speed) \
		- game->plane_y * sin(game->rot_speed);
	game->plane_y = game->old_plane_x * \
		sin(game->rot_speed) + game->plane_y * \
		cos(game->rot_speed);
}
/*
The function first stores the current direction of the player (dir_x) in
old_dir_x. Then it updates dir_x and dir_y to rotate the player's direction to
the left by rot_speed radians. This is done using the rotation matrix formula
for 2D space, which involves the cos and sin of the rotation angle. The absence
of a negative sign in game->rot_speed indicates a counterclockwise rotation,
which corresponds to a left turn.

The function then does a similar operation on plane_x and plane_y, which
represent the player's field of view or the direction the camera is pointing.
This ensures that when the player turns, their view of the game world turns
with them.

In summary, this function rotates the player and their view to the left by an
angle of rot_speed radians. The rotation is done using the standard rotation
matrix formula for 2D space, which involves the cos and sin of the rotation angle
*/
