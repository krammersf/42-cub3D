/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:53:33 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/24 21:00:00 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// frees de array and closes the program
void	close_free(char *msg, char **arr, t_map *map)
{
	free_arr1(arr);
	perror_close(msg, map);
}

// reads the cub file and calls the functions to get the elements
void	read_cub_file(t_map *map)
{
	get_ttl_nbr_lines(map);
	map->fd = open(map->map_path, O_RDONLY);
	map->get_line = get_next_line(map->fd);
	get_elements(map);
	check_ceiling_comma(map);
	check_elements(map, map->ceiling_texture, "C");
	check_floor_comma(map);
	check_elements(map, map->floor_texture, "F");
	get_map_size(map);
	get_map_to_array(map);
	check_map_integrity(map);
}
