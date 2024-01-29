/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:56:22 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/08 18:39:17 by fde-carv         ###   ########.fr       */
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
