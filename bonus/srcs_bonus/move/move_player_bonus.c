/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:53:33 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 12:35:58 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
  moves the player forward and simultaneously checks rotation to left and
  slide_left or rotation to right and slide_right
*/
void	move_player_forward(t_game *game)
{
	move_p_forward(game);
	if (game->key[ROTATE_LEFT] == 1)
	{
		rotate_p_left(game);
		if (game->key[SLIDE_LEFT] == 1)
			move_p_slide_left(game);
	}
	else if (game->key[ROTATE_RIGHT] == 1)
	{
		rotate_p_right(game);
		if (game->key[SLIDE_RIGHT] == 1)
			move_p_slide_right(game);
	}
	else if (game->key[SLIDE_LEFT] == 1)
		move_p_slide_left(game);
	else if (game->key[SLIDE_RIGHT] == 1)
		move_p_slide_right(game);
}

/*
  moves the player backward and simultaneously checks rotation to left and
  slide_left or rotation to right and slide_right
*/
void	move_player_backward(t_game *game)
{
	move_p_backward(game);
	if (game->key[ROTATE_LEFT] == 1)
	{
		rotate_p_left(game);
		if (game->key[SLIDE_LEFT] == 1)
			move_p_slide_left(game);
	}
	else if (game->key[ROTATE_RIGHT] == 1)
	{
		rotate_p_right(game);
		if (game->key[SLIDE_RIGHT] == 1)
			move_p_slide_right(game);
	}
	else if (game->key[SLIDE_LEFT] == 1)
		move_p_slide_left(game);
	else if (game->key[SLIDE_RIGHT] == 1)
		move_p_slide_right(game);
}

//  checks if key flag is toucted and calls the corresponding function	
void	move_player(t_game *game)
{
	if (game->key[MOVE_FORWARD] == 1)
		move_player_forward(game);
	else if (game->key[MOVE_BACKWARD] == 1)
		move_player_backward(game);
	else if (game->key[ROTATE_LEFT] == 1)
		rotate_p_left(game);
	else if (game->key[ROTATE_RIGHT] == 1)
		rotate_p_right(game);
	else if (game->key[SLIDE_LEFT] == 1)
		move_p_slide_left(game);
	else if (game->key[SLIDE_RIGHT] == 1)
		move_p_slide_right(game);
	if (game->mouse_lock && game->mouse_x != game->mouse_lock_x_pos)
	{
		rotate_p_mouse(game, -(game->mouse_x - game->mouse_lock_x_pos) \
			* game->frame_time * 0.1);
		mlx_mouse_move(game->mini_ptr->mlx, game->mini_ptr->mlx_win, \
			game->mouse_lock_x_pos, game->mouse_lock_y_pos);
	}
}
