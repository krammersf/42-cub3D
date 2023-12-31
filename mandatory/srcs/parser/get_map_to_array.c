/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:47 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/31 11:24:57 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// player start position if is N or S
void	set_start_ns(char c, t_game *game)
{
	if (c == 'N')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	if (c == 'S')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
}

// player start position if is N or S or W or E
void	set_start(double x, double y, char c, t_map *map)
{
	t_game	*game;

	game = map->game_ptr;
	game->pos_x = x + 0.49;
	game->pos_y = y + 0.49;
	set_start_ns(c, game);
	if (c == 'W')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
	if (c == 'E')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
}

// checks if the char is a valid char
bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || is_direction(c)
			|| c == '\n' || c == ' ' || c == '\t')
		return (true);
	return (false);
}

// get the map to an array line by line
void	get_map_to_array_while_get_line(t_map *map, int x, int y)
{
	while (map->get_line[y])
	{
		if (!is_valid_char(map->get_line[y]))
		{
			printf("\033[1;31mError!\n\033[1;33mInvalid char in map. ");//OK
			printf("The invalid char is: \'%c\'.\033[0m\n", map->get_line[y]);//OK
			close_window(map->game_ptr);
		}
		if (is_direction(map->get_line[y]))
		{
			if (map->has_player == 1)
				perror_close("More than one player.", map);//OK
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
		get_map_to_array_while_get_line(map, i, j);
		free(map->get_line);
		map->get_line = get_next_line(map->fd);
	}
	close(map->fd);
	if (map->has_player == 0)
		perror_close("No player found.", map);//OK
}
