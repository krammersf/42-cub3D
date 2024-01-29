/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_keys_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:30:18 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/08 18:42:31 by fde-carv         ###   ########.fr       */
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
