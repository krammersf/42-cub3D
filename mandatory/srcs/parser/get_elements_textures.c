/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:39 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/24 21:02:30 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// checks if the texture is already set and if the texture is repeated
void	check_texture(t_map *map, char **texture, char **dir, char **line_arr)
{
	if (!*texture && (!ft_strncmp(dir[0], line_arr[0], 2)))
		*texture = get_texture(line_arr[1]);
	else if (*texture && (!ft_strncmp(dir[0], line_arr[0], 2)))
	{
		free_arr1(line_arr);
		perror_close("Repeated Texture.", map);//OK
	}
}

// compares the first element of the line with the directions
void	get_elements_textures(t_map *map, char **line_arr)
{
	char	*n[1];
	char	*s[1];
	char	*w[1];
	char	*e[1];

	n[0] = "NO";
	s[0] = "SO";
	w[0] = "WE";
	e[0] = "EA";
	check_texture(map, &map->north_texture, n, line_arr);
	check_texture(map, &map->south_texture, s, line_arr);
	check_texture(map, &map->west_texture, w, line_arr);
	check_texture(map, &map->east_texture, e, line_arr);
}
