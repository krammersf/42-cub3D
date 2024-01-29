/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_file_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:23:18 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/29 12:21:25 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// returns the fd of the map file when is open
int	access_file(t_map *map)
{
	if (map->map_path)
		map->fd = open(map->map_path, O_RDONLY);
	if (map->fd < 0)
		exit(0);
	return (map->fd);
}

// checks if the path of the wall textures
void	access_path(t_map *map, char *texture)
{
	int	fd;
	int	len;

	if (texture == NULL)
		error_close_fd("Null texture in the map.", map, map->fd);
	else
	{
		fd = open(texture, O_RDONLY);
		if (fd < 0)
			error_close_fd("Wrong texture path in map.", map, map->fd);
		close(fd);
		len = ft_strlen(texture);
		if (len < 4 || !ft_strnstr(texture + len - 4, ".xpm", 4))
			error_close_fd("Texture not a .xpm file.", map, map->fd);
	}
}

// chekcs ac elements, the map extension and the path 
int	check_input(int ac, char *path_str, t_map *map)
{
	int		temp_fd;

	if (ac != 2)
	{
		printf("\033[1;31mError!\n\033[1;33mUsage: \
			./cube3d <map_path>\033[0m\n");
		exit(EXIT_FAILURE);
	}
	map->map_path = path_str;
	if (!check_map_extension(map, path_str))
	{
		printf("\033[1;31mError!\n\033[1;33mWrong file extension.\033[0m\n");
		exit(EXIT_FAILURE);
	}
	temp_fd = open(map->map_path, O_RDONLY);
	if (temp_fd == -1)
	{
		printf("\033[1;31mError!\n\033[1;33mCannot open file.\033[0m\n");
		exit(EXIT_FAILURE);
	}
	close(temp_fd);
	return (1);
}
