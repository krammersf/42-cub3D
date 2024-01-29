/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_walls4_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:37:32 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/29 17:35:24 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_pixel_west(t_game *game, int *x, int y, int tex_y)
{
	ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
		ft_pixel_get(&game->txt_ptr[west], game->texture_x, tex_y));
}

void	draw_pixel_ccc(t_game *game, int *x, int y, int tex_y)
{
	ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
		ft_pixel_get(&game->txt_ptr[ccc], game->texture_x, tex_y));
}

void	draw_pixel_ddd(t_game *game, int *x, int y, int tex_y)
{
	ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
		ft_pixel_get(&game->txt_ptr[ddd], game->texture_x, tex_y));
}

void	time_change(t_game *game, int *x, int y, int tex_y)
{
	game->map_ptr->current_time = get_actual_time();
	if (game->map_ptr->current_time - game->map_ptr->start_time_change >= 0)
		draw_pixel_aaa(game, x, y, tex_y);
	if (game->map_ptr->current_time
		- game->map_ptr->start_time_change > 1500)
		draw_pixel_bbb(game, x, y, tex_y);
	if (game->map_ptr->current_time
		- game->map_ptr->start_time_change >= 3000)
		game->map_ptr->start_time_change = get_actual_time();
}

void	wall_change(t_game *game, int *x, int y, int tex_y)
{
	if (game->press_l == 0)
		draw_pixel_aaa(game, x, y, tex_y);
	if (game->press_l == 1)
		draw_pixel_ccc(game, x, y, tex_y);
	if (game->press_l == 2)
		draw_pixel_ddd(game, x, y, tex_y);
}
