/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:34:17 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 13:53:13 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
  joins colors from diferent textures and draws the recatngle
  with the little map
*/
void	draw_final_rectangle(char c, t_game *game, int x, int y)
{
	unsigned int	color;

	color = put_color(c);
	draw_rectangle(game, x, y, color);
}

// draws the little map in the correct cordinates in the game_window
void	get_littlemap(t_game *game)
{
	set_larger_line(game);
	add_spaces(game);
	while (game->littlemap_ptr->start_x <= game->pos_x + 10)
	{
		game->littlemap_ptr->start_y = game->pos_y;
		game->littlemap_ptr->y = SCREEN_WIDTH * 0.806;
		while (game->littlemap_ptr->start_y <= ceil(game->pos_y) + 20)
		{
			draw_final_rectangle(game->littlemap_ptr->little_map
			[(int)game->littlemap_ptr->start_x]
			[(int)game->littlemap_ptr->start_y],
				game, game->littlemap_ptr->x, game->littlemap_ptr->y);
			game->littlemap_ptr->start_y++;
			game->littlemap_ptr->y += SCREEN_WIDTH * 0.009375;
		}
		game->littlemap_ptr->start_x++;
		game->littlemap_ptr->x += (SCREEN_HEIGHT * 0.0125);
	}
}
