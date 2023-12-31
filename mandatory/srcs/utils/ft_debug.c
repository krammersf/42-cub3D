/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:21:58 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/31 12:34:57 by fde-carv         ###   ########.fr       */
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

void	ft_print_t_map(t_map *m)
{
	printf("map->north_texture: %s\n", m->north_texture);
	printf("map->south_texture: %s\n", m->south_texture);
	printf("map->east_texture: %s\n", m->east_texture);
	printf("map->west_texture: %s\n", m->west_texture);
	printf("map->ceiling_texture: %s\n", m->ceiling_texture);
	printf("map->floor_texture: %s\n", m->floor_texture);
	printf("map->get_line: %s\n", m->get_line);
	printf("map->world_map: %s\n", m->world_map);
	printf("map->width: %d\n", m->width);
	printf("map->height: %d\n", m->height);
	printf("map->ceiling_color: %d\n", m->ceiling_color);
	printf("map->floor_color: %d\n", m->floor_color);
	printf("map->player_x: %d\n", m->player_x);
	printf("map->player_y: %d\n", m->player_y);
	printf("map->player_dir: %c\n", m->player_dir);
	printf("map->player_plane: %c\n", m->player_plane);
	printf("map->player_start: %c\n", m->player_start);
	printf("map->player_end: %c\n", m-> player_end);
}
