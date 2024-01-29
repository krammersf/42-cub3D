/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:56:22 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/28 21:52:46 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	handle_keypress2(int keycode_mlx, t_game *game)
{
	if (keycode_mlx == XK_k)
		game->press_k = 1;
	if (keycode_mlx == XK_l)
	{
		game->press_l += 1;
		if (game->press_l == 3)
			game->press_l = 0;
	}
	return (0);
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
	if (keycode_mlx == XK_space)
		game->key[INTERACT] = 1;
	if (keycode_mlx == XK_e)
		game->press_e = 1;
	handle_keypress2(keycode_mlx, game);
	if (keycode_mlx == XK_Escape)
	{
		if (!game->mouse_lock)
			close_window(game);
		else
			game->mouse_lock = 0;
	}
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
	if (keycode_mlx == XK_k)
		game->press_k = 0;
	return (0);
}

int	handle_mouse_movement(int x, int y, t_mlx *mlx)
{
	if (mlx->game_ptr->mouse_lock)
	{
		mlx->game_ptr->mouse_x = x;
		mlx->game_ptr->mouse_y = y;
	}
	return (0);
}

int	handle_mouse_click_down(int button, int x, int y, t_mlx *mlx)
{
	if (button == 1)
	{
		mlx->game_ptr->mouse_lock = 1;
		mlx->game_ptr->mouse_lock_x_pos = x;
		mlx->game_ptr->mouse_lock_y_pos = y;
		mlx->game_ptr->mouse_x = x;
		mlx->game_ptr->mouse_y = y;
	}
	return (0);
}
