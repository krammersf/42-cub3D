/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:23:18 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/27 14:44:20 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		perror_close("Invalid map.ff", map);//percebo a logica nao consigo reproduzir o erro
	else
	{
		fd = open(texture, O_RDONLY);
		if (fd < 0)
			perror_close("Wrong texture path in map.", map);//OK
		close(fd);
		len = ft_strlen(texture);
		if (len < 4 || !ft_strnstr(texture + len - 4, ".xpm", 4))
			perror_close("Texture not a .xpm file.", map);//OK
	}
}

// prints eror msg and closes the window
void	perror_close(char *msg, t_map *map)
{
	printf("\033[1;31mError!\n\033[1;33m%s\033[0m\n", msg);//OK
	close_window(map->game_ptr);
}

// closes fd and prints eror msg and closes the window
void	perror_close_fd(char *msg, t_map *map, int fd)
{
	close(fd);
	printf("\033[1;31mError!\n\033[1;33m%s\033[0m\n", msg);//OK
	close_window(map->game_ptr);
}
