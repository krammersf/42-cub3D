/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_integrity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:47 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/02 14:33:27 by fde-carv         ###   ########.fr       */
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

// find first '0' in 2d array
int	find_first_zero(t_map *map, char **map_copy)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->map_copy_x = 0;
	map->map_copy_y = 0;
	while (x < (map->map_end - map->map_start))
	{
		while (map_copy[x][y])
		{
			if (map_copy[x][y] == '0')
			{
				//printf("Encontrou: \n");//	
				map->map_copy_x = x;
				map->map_copy_y = y;
				//printf("map_copy_x: %d\n", map->map_copy_x);//
				//printf("map_copy_y: %d\n", map->map_copy_y);//
				return (0);
			}
			y++;
		}
		x++;
		y = 0;
	}
	return (1);
}

// checks flood fill algorithm recursively
void	check_flood_fill(t_map *map, char **array, int y, int x)
{
	if (y < (map->map_start - map->map_start)
		|| y >= (map->map_end - map->map_start - 0)
		|| x < ft_begin_strlen(array[y])
		|| x >= (int)ft_strlen(array[y])
		|| array[y][x] != '0')
	{
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

// chekcs if the map is surrounded by walls and there is a valid
// path for the player
void	check_map_integrity(t_map *map)
{
	char	**map_copy;

	map->inside_checked = 0;
	map_copy = to_copy_map(map);
	while (map->inside_checked == 0)
	{
		if (find_first_zero(map, map_copy) == 1)
			break ;
		check_flood_fill(map, map_copy, map->map_copy_x, map->map_copy_y);
	}
	free_arr(map_copy, map);
	if (map->inside_checked == 1)
		perror_close("Map integrity fail.", map);//OK
}
