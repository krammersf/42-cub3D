/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_keys_2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernacar <fernacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:30:18 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/16 13:01:27 by fernacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

void	rotate_p_mouse(t_game *game, double amount)
{
	game->old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(amount) \
		- game->dir_y * sin(amount);
	game->dir_y = game->old_dir_x * sin(amount) \
			+ game->dir_y * cos(amount);
	game->old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(amount) \
		- game->plane_y * sin(amount);
	game->plane_y = game->old_plane_x * \
		sin(amount) + game->plane_y * \
		cos(amount);
}
