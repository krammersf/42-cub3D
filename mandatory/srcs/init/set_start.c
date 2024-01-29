/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:47 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/08 18:53:27 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// player start position if is N or S
void	set_start_position(char c, t_game *game)
{
	if (c == 'N')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	if (c == 'S')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
}

// player start position if is N or S or W or E
void	set_start(double x, double y, char c, t_map *map)
{
	t_game	*game;

	game = map->game_ptr;
	game->pos_x = x + 0.49;
	game->pos_y = y + 0.49;
	set_start_position(c, game);
	if (c == 'W')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
	if (c == 'E')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
}
