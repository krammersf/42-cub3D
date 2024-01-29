/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:09:49 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/29 11:21:24 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	door_toggle(char *tile)
{
	if (*tile == 'D')
		*tile = 'U';
	else if (*tile == 'U')
		*tile = 'D';
}

void	interact(t_game *game)
{
	game->key[INTERACT] = 0;
	if (fabs(game->dir_x) > fabs(game->dir_y) && game->dir_x > 0)
		door_toggle(&game->map_ptr->world_map[(int)game->pos_x + 1] \
			[(int)game->pos_y]);
	else if (fabs(game->dir_x) > fabs(game->dir_y) && game->dir_x < 0)
		door_toggle(&game->map_ptr->world_map[(int)game->pos_x - 1] \
			[(int)game->pos_y]);
	else if (fabs(game->dir_y) > fabs(game->dir_x) && game->dir_y > 0)
		door_toggle(&game->map_ptr->world_map[(int)game->pos_x] \
			[(int)game->pos_y + 1]);
	else if (fabs(game->dir_y) > fabs(game->dir_x) && game->dir_y < 0)
		door_toggle(&game->map_ptr->world_map[(int)game->pos_x] \
			[(int)game->pos_y - 1]);
}

void	render_frames_total2(t_game *game)
{
	draw_hands(game);
	draw_littlemap_complete(game);
	fps(game);
	game->move_speed = game->frame_time * 3;
	if (game->key[SLIDE_LEFT] == 1 || game->key[SLIDE_RIGHT] == 1)
		game->rot_speed = game->frame_time * 3.0;
	else
		game->rot_speed = game->frame_time * 1;
	game->move_margin = 0.5;
	if (game->key[INTERACT])
		interact(game);
	move_player(game);
}

/*
  Main function that compiles many 3D important functions. Draws background,
  walls, set move and rotation speed, margin and player movement.
*/
int	render_frames_total(void *arg)
{
	t_game		*game;
	int			x;

	game = arg;
	get_bite_floor_color(game->map_ptr);
	get_bite_ceiling_color(game->map_ptr);
	background(*game->mini_ptr, game->map_ptr->c_color_bites,
		game->map_ptr->f_color_bites);
	mlx_put_image_to_window(game->mini_ptr->mlx, game->mini_ptr->mlx_win, \
		game->mini_ptr->img, 0, 0);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		render_frames_1(game, &x);
		render_frames_2(game, &x);
		x++;
	}
	render_frames_total2(game);
	return (0);
}
