/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_to_array2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:04:49 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 13:05:19 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	gnl_and_free(t_map *map)
{
	free(map->get_line);
	map->get_line = get_next_line(map->fd);
}

// get the map to an array
void	get_map_to_array(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	map->fd = access_file(map);
	map->get_line = get_next_line(map->fd);
	while (++i < map->map_start)
		gnl_and_free(map);
	i = -1;
	while (map->get_line && ++i < map->map_end - map->map_start)
	{
		map->world_map[i] = ft_calloc((ft_strlen(map->get_line)
					+ 1), sizeof(char));
		j = 0;
		get_map_to_array_cheks_player_char(map, i, j);
		pad_line_width(map->world_map, i, map->map_width);
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	free(map->get_line);
	close(map->fd);
	if (map->has_player == 0)
		error_close("No player found.", map);
}
