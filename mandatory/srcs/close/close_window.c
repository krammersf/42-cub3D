/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:59:10 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/29 14:20:44 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// function to free the map struct
void	free_t_map(t_map *map)
{
	if (map->north_texture)
		free(map->north_texture);
	if (map->south_texture)
		free(map->south_texture);
	if (map->east_texture)
		free(map->east_texture);
	if (map->west_texture)
		free(map->west_texture);
	if (map->ceiling_texture)
		free(map->ceiling_texture);
	if (map->floor_texture)
		free(map->floor_texture);
	if (map->world_map)
		free_arr(map->world_map, map);
}

// function to close the window and free the memory using mlx functions
int	close_window(t_game *game)
{
	int		i;

	i = -1;
	if (game->mini_ptr->mlx)
		mlx_clear_window(game->mini_ptr->mlx, game->mini_ptr->mlx_win);
	if (game->mini_ptr->mlx)
		mlx_destroy_window(game->mini_ptr->mlx, game->mini_ptr->mlx_win);
	if (game->mini_ptr->mlx)
		mlx_destroy_image(game->mini_ptr->mlx, game->mini_ptr->img);
	while (++i < 4)
	{
		if (game->mini_ptr->mlx && game->txt_ptr[i].img)
			mlx_destroy_image(game->mini_ptr->mlx, game->txt_ptr[i].img);
	}
	if (game->mini_ptr->mlx_win)
		mlx_destroy_display(game->mini_ptr->mlx);
	if (game->txt_ptr)
		free(game->txt_ptr);
	free_t_map(game->map_ptr);
	if (game->mini_ptr->mlx)
		free(game->mini_ptr->mlx);
	exit(0);
	return (0);
}
