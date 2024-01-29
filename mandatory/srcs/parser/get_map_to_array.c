/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:54 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 13:48:16 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// checks if the map file is empty if not count the lines
void	get_total_nbr_lines(t_map *map)
{
	int		fd;
	int		has_content;
	char	*line;

	fd = 0;
	fd = open(map->map_path, O_RDONLY);
	has_content = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1)
			has_content = 1;
		map->total_nbr_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (has_content == 0)
		error_close("Empty file.", map);
}

// checks if the char is a valid char
bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || is_player(c)
		|| c == '\n' || c == ' ')
		return (true);
	return (false);
}

void	check_invalid_char_error(t_map *map, int y)
{
	printf("\033[1;31mError!\n\033[1;33mInvalid char in map. ");
	printf("The invalid char is: \'%c\'.\033[0m\n", map->get_line[y]);
	free(map->get_line);
	close(map->fd);
	close_window(map->game_ptr);
}

/*
  get the map to an array line by line, sets the player position
  if it exists and checks if the map has invalid chars
*/
void	get_map_to_array_cheks_player_char(t_map *map, int x, int y)
{
	while (map->get_line[y])
	{
		if (!is_valid_char(map->get_line[y]))
			check_invalid_char_error(map, y);
		if (is_player(map->get_line[y]))
		{
			if (map->has_player == 1)
			{
				free(map->get_line);
				error_close_fd("More than one player.", map, map->fd);
			}
			map->world_map[x][y] = '0';
			set_start(x, y, map->get_line[y], map);
			map->has_player = 1;
		}
		else
			map->world_map[x][y] = map->get_line[y];
		y++;
	}
	map->world_map[x][y] = '\0';
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
	{
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	i = -1;
	while (map->get_line && ++i < map->map_end - map->map_start)
	{
		map->world_map[i] = ft_calloc((ft_strlen(map->get_line)
					+ 1), sizeof(char));
		j = 0;
		get_map_to_array_cheks_player_char(map, i, j);
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	free(map->get_line);
	close(map->fd);
	if (map->has_player == 0)
		error_close("No player found.", map);
}
