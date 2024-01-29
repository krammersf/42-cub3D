/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:43 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 13:33:16 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// checks if the map has a empty line in it
void	check_empty_line(t_map *map)
{
	while (map->get_line)
	{
		if ((ft_strchr(map->get_line, '1')
				|| ft_strchr(map->get_line, '0')) != 0)
		{
			close(map->fd);
			free(map->get_line);
			error_close("Invalid map configuration. Empty line in map.", map);
		}
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
}

// also gets the max width of the map (map->map_width)
void	map_get_line(t_map *map)
{
	while (map->get_line)
	{
		if ((ft_strchr(map->get_line, '1')
				|| ft_strchr(map->get_line, '0')) == 0)
			break ;
		if ((int)ft_strlen(map->get_line) > map->map_width)
			map->map_width = ft_strlen(map->get_line);
		map->line_nbr++;
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
}

// gets the size of the map (map->line_nbr), map->map_start and map->map_end
void	get_map_size(t_map *map)
{
	map->get_line = get_next_line(map->fd);
	while (map->get_line)
	{
		if ((ft_strchr(map->get_line, '1')
				|| ft_strchr(map->get_line, '0')) != 0)
			break ;
		map->line_nbr++;
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	map->map_start = map->line_nbr;
	map_get_line(map);
	map->map_end = map->line_nbr;
	map->world_map = ft_calloc(map->map_end - map->map_start, sizeof(char *));
	if (!map->world_map)
		return ;
	check_empty_line(map);
	free(map->get_line);
	close(map->fd);
}
