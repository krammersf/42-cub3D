/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:43 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/27 21:45:55 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// gets the size of the map (map->line_nbr), map->m_start and map->m_end
void	get_map_size(t_map *map)
{
	map->get_line = get_next_line(map->fd);
	//printf("get_line_1: %s\n", map->get_line);
	while (map->get_line && ft_strcmp(map->get_line, "\n") == 0)
	{
		map->line_nbr++;
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
		//printf("get_line_2: %s", map->get_line);
	}
	map->map_start = map->line_nbr;
	//printf("m_start: %d\n", map->map_start);
	while (map->get_line && (ft_strcmp(map->get_line, "\n") != 0))
	{
		map->line_nbr++;
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
		//printf("get_line_3: %s", map->get_line);
	}
	map->map_end = map->line_nbr;
	//printf("m_end: %d\n", map->map_end);
	map->world_map = ft_calloc(map->map_end - map->map_start, sizeof(char *));
	if (!map->world_map)
		return ;
	free(map->get_line);
	close(map->fd);
}
