/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:39 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/02 17:22:29 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// checks if the texture is already set and if the texture is repeated
void	check_texture(t_map *map, char **texture, char **dir, char **line_arr)
{
	if (*texture == NULL)
	{
		if (!ft_strncmp(dir[0], line_arr[0], 3))
			*texture = get_texture(line_arr[1]);
	}
	else if (*texture
		&& (!ft_strncmp(dir[0], line_arr[0], 2)))
	{
		free_arr1(line_arr);
		perror_close_fd("Repeated elements.", map, map->fd);//OK
	}
}

// compares the first element of the line with the directions
void	get_elements_textures(t_map *map, char **line_arr)
{
	char	*no[1];
	char	*so[1];
	char	*we[1];
	char	*ea[1];

	no[0] = "NO";
	so[0] = "SO";
	we[0] = "WE";
	ea[0] = "EA";
	check_texture(map, &map->north_texture, no, line_arr);
	check_texture(map, &map->south_texture, so, line_arr);
	check_texture(map, &map->west_texture, we, line_arr);
	check_texture(map, &map->east_texture, ea, line_arr);
}
