/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:56:22 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/29 14:49:26 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

// checks the key press event and sets the corresponding flag
int	handle_keypress(int keycode_mlx, t_game *game)
{
	if (keycode_mlx == XK_W || keycode_mlx == XK_w)
		game->key[MOVE_FORWARD] = 1;
	if (keycode_mlx == XK_S || keycode_mlx == XK_s)
		game->key[MOVE_BACKWARD] = 1;
	if (keycode_mlx == XK_A || keycode_mlx == XK_a)
		game->key[SLIDE_LEFT] = 1;
	if (keycode_mlx == XK_D || keycode_mlx == XK_d)
		game->key[SLIDE_RIGHT] = 1;
	if (keycode_mlx == XK_Left)
		game->key[ROTATE_LEFT] = 1;
	if (keycode_mlx == XK_Right)
		game->key[ROTATE_RIGHT] = 1;
	if (keycode_mlx == XK_Escape)
		close_window(game);
	return (0);
}
/*
This function is designed to handle keypress events in a game. 
It takes two parameters: an integer keycode_mlx that represents the key pressed
by the user, and a pointer mini to a t_mlx structure that presumably holds the
game state.

The function checks if the keycode_mlx matches certain predefined constants,
each representing a specific key on the keyboard. These constants
(like XK_W, XK_S, XK_A, XK_D, XK_Left, XK_Right, and XK_Escape) are likely
defined in an included library. The keys W, S, A, D, Left, Right, and Escape
are commonly used in games for movement and game control.

If the keycode_mlx matches one of the movement keys (W, S, A, D, Left, Right),
the corresponding movement flag in the game_ptr structure is set to 1,
indicating that movement in that direction should occur. For example, if the
keycode_mlx matches XK_W or XK_w (upper or lower case 'w'), the move_forward
flag is set to 1.

If the keycode_mlx matches the Escape key, the close_window function is called
with game_ptr as the argument, presumably to close the game window and end
the game.

Function must be a int, it as to have return value.
*/

// checks the key release event and sets the corresponding flag
int	handle_keyrelease(int keycode_mlx, t_game *game)
{
	if (keycode_mlx == XK_W || keycode_mlx == XK_w)
		game->key[MOVE_FORWARD] = 0;
	if (keycode_mlx == XK_S || keycode_mlx == XK_s)
		game->key[MOVE_BACKWARD] = 0;
	if (keycode_mlx == XK_A || keycode_mlx == XK_a)
		game->key[SLIDE_LEFT] = 0;
	if (keycode_mlx == XK_D || keycode_mlx == XK_d)
		game->key[SLIDE_RIGHT] = 0;
	if (keycode_mlx == XK_Left)
		game->key[ROTATE_LEFT] = 0;
	if (keycode_mlx == XK_Right)
		game->key[ROTATE_RIGHT] = 0;
	return (0);
}
