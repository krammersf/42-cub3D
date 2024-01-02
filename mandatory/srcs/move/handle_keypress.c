/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:56:22 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/02 11:25:20 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
