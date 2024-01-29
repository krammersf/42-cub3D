/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littlemap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:23:57 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 12:31:53 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// initializes the struct of the little map
void	init_littlemap_struct(t_littlemap *littlemap, t_game *game)
{
	littlemap->start_x = game->pos_x;
	littlemap->end_x = game->pos_x + 10 + 10;
	littlemap->start_y = game->pos_y;
	littlemap->end_y = game->pos_y + 5 + 5;
	littlemap->x = ((double)SCREEN_HEIGHT * 0.010);
	littlemap->little_map = ft_calloc((game->map_ptr->map_end - \
		game->map_ptr->map_start + 10), sizeof(char *));
	littlemap->x_center = (int)((SCREEN_WIDTH * 0.891800 \
		+ SCREEN_WIDTH * 0.90125) / 2);
	littlemap->y_center = (int)((SCREEN_HEIGHT * 0.07300 \
		+ SCREEN_HEIGHT * 0.0720) / 2);
	littlemap->line_length = SCREEN_HEIGHT * 0.03;
	littlemap->dx = 0;
	littlemap->dy = 0;
	littlemap->sx = 0;
	littlemap->sy = 0;
	littlemap->err = 0;
	littlemap->e2 = 0;
	littlemap->x2 = 0;
	littlemap->y2 = 0;
}

// draws the little map in the game window
void	draw_littlemap_complete(t_game *game)
{
	t_littlemap	l_map;
	int			total;

	game->littlemap_ptr = &l_map;
	init_littlemap_struct(&l_map, game);
	get_littlemap(game);
	draw_little_player(game);
	total = (game->map_ptr->map_end - game->map_ptr->map_start + 10);
	free_arr2(game->littlemap_ptr->little_map, total);
}
