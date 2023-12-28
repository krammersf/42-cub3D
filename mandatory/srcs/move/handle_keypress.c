/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:56:22 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/28 23:03:53 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_p_slide_left(t_mlx *mini)
{
	if (mini->game_ptr->map_ptr->world_map \
		[(int)(mini->game_ptr->pos_x - mini->game_ptr->plane_x * \
			mini->game_ptr->move_margin)][(int)(mini->game_ptr->pos_y)] == '0')
		mini->game_ptr->pos_x -= mini->game_ptr->plane_x \
			* mini->game_ptr->move_speed;
	if (mini->game_ptr->map_ptr->world_map \
		[(int)(mini->game_ptr->pos_x)][(int)(mini->game_ptr->pos_y \
			- mini->game_ptr->plane_y * mini->game_ptr->move_margin)] == '0')
		mini->game_ptr->pos_y -= mini->game_ptr->plane_y \
			* mini->game_ptr->move_speed;
}

void	move_p_slide_right(t_mlx *mini)
{
	if (mini->game_ptr->map_ptr->world_map \
		[(int)(mini->game_ptr->pos_x + mini->game_ptr->plane_x * \
			mini->game_ptr->move_margin)][(int)(mini->game_ptr->pos_y)] == '0')
		mini->game_ptr->pos_x += mini->game_ptr->plane_x \
			* mini->game_ptr->move_speed;
	if (mini->game_ptr->map_ptr->world_map \
		[(int)(mini->game_ptr->pos_x)][(int)(mini->game_ptr->pos_y \
			+ mini->game_ptr->plane_y * mini->game_ptr->move_margin)] == '0')
		mini->game_ptr->pos_y += mini->game_ptr->plane_y \
			* mini->game_ptr->move_speed;
}

int	handle_keypress(int keysym, t_mlx *mini)
{
	if (keysym == XK_W || keysym == XK_w)
		mini->game_ptr->move_up = 1;
	if (keysym == XK_S || keysym == XK_s)
		mini->game_ptr->move_down = 1;
	if (keysym == XK_A || keysym == XK_a)
		mini->game_ptr->slide_left = 1;
	if (keysym == XK_D || keysym == XK_d)
		mini->game_ptr->slide_right = 1;
	if (keysym == XK_Left)
		mini->game_ptr->move_left = 1;
	if (keysym == XK_Right)
		mini->game_ptr->move_right = 1;
	if (keysym == XK_Escape)
		close_window(mini->game_ptr);
	return (0);
}

int	handle_keyrelease(int keysym, t_mlx *mini)
{
	if (keysym == XK_W || keysym == XK_w)
		mini->game_ptr->move_up = 0;
	if (keysym == XK_S || keysym == XK_s)
		mini->game_ptr->move_down = 0;
	if (keysym == XK_A || keysym == XK_a)
		mini->game_ptr->slide_left = 0;
	if (keysym == XK_D || keysym == XK_d)
		mini->game_ptr->slide_right = 0;
	if (keysym == XK_Right)
		mini->game_ptr->move_right = 0;
	if (keysym == XK_Left)
		mini->game_ptr->move_left = 0;
	return (0);
}
