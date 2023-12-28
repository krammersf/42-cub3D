/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:11:05 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/27 14:44:12 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_p_up(t_mlx *m)
{
	if (m->game_ptr->map_ptr->world_map[(int)(m->game_ptr->pos_x + \
			m->game_ptr->dir_x * m->game_ptr->move_margin)]
			[(int)(m->game_ptr->pos_y)] == '0')
		m->game_ptr->pos_x += m->game_ptr->dir_x * m->game_ptr->move_speed;
	if (m->game_ptr->map_ptr->world_map[(int)(m->game_ptr->pos_x)] \
			[(int)(m->game_ptr->pos_y + m->game_ptr->dir_y *
			m->game_ptr->move_margin)] == '0')
		m->game_ptr->pos_y += m->game_ptr->dir_y * m->game_ptr->move_speed;
}

void	move_p_down(t_mlx *m)
{
	if (m->game_ptr->map_ptr->world_map[(int)(m->game_ptr->pos_x - \
			m->game_ptr->dir_x * m->game_ptr->move_margin)]
			[(int)(m->game_ptr->pos_y)] == '0')
		m->game_ptr->pos_x -= m->game_ptr->dir_x * m->game_ptr->move_speed;
	if (m->game_ptr->map_ptr->world_map[(int)(m->game_ptr->pos_x)] \
			[(int)(m->game_ptr->pos_y - m->game_ptr->dir_y *
			m->game_ptr->move_margin)] == '0')
		m->game_ptr->pos_y -= m->game_ptr->dir_y * m->game_ptr->move_speed;
}

void	move_p_right(t_mlx *m)
{
	m->game_ptr->old_dir_x = m->game_ptr->dir_x;
	m->game_ptr->dir_x = m->game_ptr->dir_x * cos(-m->game_ptr->rot_speed) \
			- m->game_ptr->dir_y * sin(-m->game_ptr->rot_speed);
	m->game_ptr->dir_y = m->game_ptr->old_dir_x * sin(-m->game_ptr->rot_speed) \
			+ m->game_ptr->dir_y * cos(-m->game_ptr->rot_speed);
	m->game_ptr->old_plane_x = m->game_ptr->plane_x;
	m->game_ptr->plane_x = m->game_ptr->plane_x * cos(-m->game_ptr->rot_speed) \
		- m->game_ptr->plane_y * sin(-m->game_ptr->rot_speed);
	m->game_ptr->plane_y = m->game_ptr->old_plane_x * \
		sin(-m->game_ptr->rot_speed) + m->game_ptr->plane_y * \
		cos(-m->game_ptr->rot_speed);
}

void	move_p_left(t_mlx *m)
{
	m->game_ptr->old_dir_x = m->game_ptr->dir_x;
	m->game_ptr->dir_x = m->game_ptr->dir_x * cos(m->game_ptr->rot_speed) \
		- m->game_ptr->dir_y * sin(m->game_ptr->rot_speed);
	m->game_ptr-> dir_y = m->game_ptr->old_dir_x * \
		sin(m->game_ptr->rot_speed) + m->game_ptr->dir_y * \
			cos(m->game_ptr->rot_speed);
	m->game_ptr->old_plane_x = m->game_ptr->plane_x;
	m->game_ptr-> plane_x = m->game_ptr->plane_x * \
		cos(m->game_ptr->rot_speed) - m->game_ptr->plane_y * \
			sin(m->game_ptr->rot_speed);
	m->game_ptr->plane_y = m->game_ptr->old_plane_x * \
		sin(m->game_ptr->rot_speed) + m->game_ptr->plane_y * \
			cos(m->game_ptr->rot_speed);
}
