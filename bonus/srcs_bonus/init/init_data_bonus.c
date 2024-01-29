/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:42:45 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/29 14:39:54 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// initializes the game struct part 3
void	init_game3(t_game *game)
{
	game->side_dist_x = 0.0;
	game->side_dist_y = 0.0;
	game->delta_dist_x = 0.0;
	game->delta_dist_y = 0.0;
	game->perp_wall_dist = 0.0;
}

// initializes the game struct part 2
void	init_game2(t_game *game, struct s_map *map_ptr, t_mlx *m)
{
	game->step_x = 0;
	game->step_y = 0;
	game->hit = 0;
	game->side = 0;
	game->line_height = 0;
	game->draw_start = 0;
	game->draw_end = 0;
	game->old_dir_x = 0.0;
	game->old_plane_x = 0.0;
	game->frame_time = 0.0;
	game->fps = 0;
	game->tps = 0.0;
	game->texture_x = 0;
	game->txt_ptr = ft_calloc(9, sizeof(t_texture));
	if (!game->txt_ptr)
		exit(EXIT_FAILURE);
	game->map_ptr = map_ptr;
	game->mini_ptr = m;
	game->press_e = 0;
	game->press_k = 0;
	game->press_l = 0;
	game->map_ptr->start_time_change = get_actual_time();
	init_game3(game);
}

// initializes the game struct part 1
void	init_game(t_game *game, struct s_map *map_ptr, t_mlx *m)
{
	int	i;

	i = -1;
	while (++i < 6)
		game->key[i] = 0;
	game->pos_x = 0.0;
	game->pos_y = 0.0;
	game->dir_x = 0.0;
	game->dir_y = 0.0;
	game->plane_x = 0.0;
	game->plane_y = 0.0;
	game->move_speed = 0.0;
	game->rot_speed = 0.0;
	game->move_margin = 0.0;
	game->time = 0.0;
	game->old_time = 0.0;
	game->camera_x = 0.0;
	game->ray_dir_x = 0.0;
	game->ray_dir_y = 0.0;
	game->map_x = 0;
	game->map_y = 0;
	game->txt_hands = NULL;
	init_game2(game, map_ptr, m);
	init_change_color(game);
}

// initializes the map struct
void	init_t_map(t_map *map, t_game *game)
{
	map->fd = 0;
	map->total_nbr_lines = 0;
	map->extension = NULL;
	map->get_line = NULL;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor_texture = NULL;
	map->ceiling_texture = NULL;
	map->door_texture = NULL;
	map->world_map = NULL;
	map->wall_x = 0.0;
	map->step = 0.0;
	map->tex_pos = 0.0;
	map->tex_y = 0;
	map->game_ptr = game;
	map->map_start = 0;
	map->map_end = 0;
	map->line_nbr = 0;
	map->has_player = 0;
	map->f_color_bites = 0;
	map->c_color_bites = 0;
	map->larger_line = 0;
	map->start_time_hand = 0;
}

// initializes the mlx pointers to NULL
void	init_mlx(t_mlx *map)
{
	map->mlx = NULL;
	map->mlx_win = NULL;
}
