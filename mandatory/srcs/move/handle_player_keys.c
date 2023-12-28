/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:11:05 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/28 23:05:19 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_p_up(t_mlx *mini)
{
	if (mini->game_ptr->map_ptr->world_map[(int)(mini->game_ptr->pos_x + \
			mini->game_ptr->dir_x * mini->game_ptr->move_margin)]
			[(int)(mini->game_ptr->pos_y)] == '0')
		mini->game_ptr->pos_x += mini->game_ptr->dir_x * mini->game_ptr->move_speed;
	if (mini->game_ptr->map_ptr->world_map[(int)(mini->game_ptr->pos_x)] \
			[(int)(mini->game_ptr->pos_y + mini->game_ptr->dir_y *
			mini->game_ptr->move_margin)] == '0')
		mini->game_ptr->pos_y += mini->game_ptr->dir_y * mini->game_ptr->move_speed;
}

void	move_p_down(t_mlx *mini)
{
	if (mini->game_ptr->map_ptr->world_map[(int)(mini->game_ptr->pos_x - \
			mini->game_ptr->dir_x * mini->game_ptr->move_margin)]
			[(int)(mini->game_ptr->pos_y)] == '0')
		mini->game_ptr->pos_x -= mini->game_ptr->dir_x * mini->game_ptr->move_speed;
	if (mini->game_ptr->map_ptr->world_map[(int)(mini->game_ptr->pos_x)] \
			[(int)(mini->game_ptr->pos_y - mini->game_ptr->dir_y *
			mini->game_ptr->move_margin)] == '0')
		mini->game_ptr->pos_y -= mini->game_ptr->dir_y * mini->game_ptr->move_speed;
}

void	move_p_right(t_mlx *mini)
{
	mini->game_ptr->old_dir_x = mini->game_ptr->dir_x;
	mini->game_ptr->dir_x = mini->game_ptr->dir_x * cos(-mini->game_ptr->rot_speed) \
			- mini->game_ptr->dir_y * sin(-mini->game_ptr->rot_speed);
	mini->game_ptr->dir_y = mini->game_ptr->old_dir_x * sin(-mini->game_ptr->rot_speed) \
			+ mini->game_ptr->dir_y * cos(-mini->game_ptr->rot_speed);
	mini->game_ptr->old_plane_x = mini->game_ptr->plane_x;
	mini->game_ptr->plane_x = mini->game_ptr->plane_x * cos(-mini->game_ptr->rot_speed) \
		- mini->game_ptr->plane_y * sin(-mini->game_ptr->rot_speed);
	mini->game_ptr->plane_y = mini->game_ptr->old_plane_x * \
		sin(-mini->game_ptr->rot_speed) + mini->game_ptr->plane_y * \
		cos(-mini->game_ptr->rot_speed);
}

void	move_p_left(t_mlx *mini)
{
	mini->game_ptr->old_dir_x = mini->game_ptr->dir_x;
	mini->game_ptr->dir_x = mini->game_ptr->dir_x * cos(mini->game_ptr->rot_speed) \
		- mini->game_ptr->dir_y * sin(mini->game_ptr->rot_speed);
	mini->game_ptr-> dir_y = mini->game_ptr->old_dir_x * \
		sin(mini->game_ptr->rot_speed) + mini->game_ptr->dir_y * \
			cos(mini->game_ptr->rot_speed);
	mini->game_ptr->old_plane_x = mini->game_ptr->plane_x;
	mini->game_ptr-> plane_x = mini->game_ptr->plane_x * \
		cos(mini->game_ptr->rot_speed) - mini->game_ptr->plane_y * \
			sin(mini->game_ptr->rot_speed);
	mini->game_ptr->plane_y = mini->game_ptr->old_plane_x * \
		sin(mini->game_ptr->rot_speed) + mini->game_ptr->plane_y * \
			cos(mini->game_ptr->rot_speed);
}
