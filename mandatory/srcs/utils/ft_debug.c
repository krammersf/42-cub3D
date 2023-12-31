/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:21:58 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/31 12:48:03 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_print_array(char **arr, int nb_lines)
{
	int	i;

	i = 0;
	while (i < nb_lines)
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

void	ft_print_t_map(t_map *map)
{
	printf("map->north_texture: %s\n", map->north_texture);
	printf("map->south_texture: %s\n", map->south_texture);
	printf("map->east_texture: %s\n", map->east_texture);
	printf("map->west_texture: %s\n", map->west_texture);
	printf("map->ceiling_texture: %s\n", map->ceiling_texture);
	printf("map->floor_texture: %s\n", map->floor_texture);
	printf("map->get_line: %s\n", map->get_line);
	printf("map->width: %f\n", map->wall_x);
	printf("map->height: %f\n", map->step);
	printf("map->height: %f\n", map->tex_pos);
	printf("map->ceiling_color: %d\n", map->c_color_bites);
	printf("map->floor_color: %d\n", map->f_color_bites);
	printf("map->player_x: %d\n", map->map_copy_x);
	printf("map->player_y: %d\n", map->map_copy_y);
	printf("map->player_start: %d\n", map->map_start);
	printf("map->player_end: %d\n", map-> map_end);
}
