/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:40:00 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 12:41:50 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
  checks the validity of a specific door
  first if look for walls horizontally
  second if look for walls vertically
*/
int	valid_door(t_map *map, int x, int y)
{
	if (map->world_map[y][x - 1] == '1' && map->world_map[y][x + 1] == '1' )
		return (1);
	if (map->world_map[y - 1][x] == '1' && map->world_map[y + 1][x] == '1' )
		return (1);
	return (0);
}

// checks the whole map for doors in bad spots
int	check_doors(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map_end - map->map_start)
	{
		x = 0;
		while (x < map->map_width)
		{
			if (map->world_map[y][x] == 'D' && !valid_door(map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

/*
  chekcs if the map is surrounded by walls and there is a valid
  path for the player
  also checks if doors are in valid spots
*/
void	check_map_integrity(t_map *map)
{
	char	**map_copy;

	map->inside_checked = 0;
	map_copy = to_copy_map(map);
	while (map->inside_checked == 0)
	{
		if (find_first_zero(map, map_copy) == 1)
			break ;
		check_flood_fill(map, map_copy, map->map_copy_y, map->map_copy_x);
	}
	free_arr(map_copy, map);
	if (map->inside_checked == 1)
	{
		printf("\033[1;31mError!\n\033[1;33mMap integrity failed. ");
		printf("The map is not surrounded by walls.\n");
		close_window(map->game_ptr);
	}
	else if (check_doors(map))
	{
		printf("\033[1;31mError!\n\033[1;33mMap integrity failed. ");
		printf("Bad door placement.\n");
		close_window(map->game_ptr);
	}
}
