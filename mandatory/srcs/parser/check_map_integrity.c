/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_integrity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:47 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 13:38:39 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// allocks dinamic memory to make a **map copy 
char	**to_copy_map(t_map *map)
{
	int		x;
	int		y;
	char	**copy;

	x = 0;
	y = 0;
	copy = malloc(sizeof(char *) * (map->map_end - map->map_start));
	if (!copy)
		return (NULL);
	while (x < (map->map_end - map->map_start))
	{
		copy[x] = malloc(sizeof(char) * ft_strlen(map->world_map[x]) + 1);
		if (!copy[x])
			return (NULL);
		while (y < (int)ft_strlen(map->world_map[x]))
		{
			copy[x][y] = map->world_map[x][y];
			y++;
		}
		copy[x][y] = '\0';
		y = 0;
		x++;
	}
	return (copy);
}

// count the number of leading whitespace characters in a string.
int	ft_begin_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	return (i);
}

//find first '0' in 2d array
int	find_first_zero(t_map *map, char **map_copy)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->map_copy_x = 0;
	map->map_copy_y = 0;
	while (y < (map->map_end - map->map_start))
	{
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == '0')
			{
				map->map_copy_x = x;
				map->map_copy_y = y;
				return (0);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}

// checks flood fill algorithm recursively
void	check_flood_fill(t_map *map, char **array, int y, int x)
{
	if (y < 0 || y >= (map->map_end - map->map_start)
		|| x < 0 || x >= (int)ft_strlen(array[y])
		|| array[y][x] != '0')
	{
		if (y < 0 || x < 0 || y >= (map->map_end - map->map_start))
		{
			map->inside_checked = 1;
			return ;
		}
		if (array[y][x] != '0' && array[y][x] != '1' && array[y][x] != 'X')
			map->inside_checked = 1;
		return ;
	}
	array[y][x] = 'X';
	check_flood_fill(map, array, y + 1, x);
	check_flood_fill(map, array, y - 1, x);
	check_flood_fill(map, array, y, x + 1);
	check_flood_fill(map, array, y, x - 1);
}

/*
  chekcs if the map is surrounded by walls and there is a valid
  path for the player
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
}
