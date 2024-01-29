/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:53:33 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/13 12:44:35 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// frees de array and closes the program
void	close_free(char *msg, char **arr, t_map *map)
{
	free_arr1(arr);
	error_close_fd(msg, map, map->fd);
}

// reads the cub file and calls the functions to get the elements
void	read_cub_file(t_map *map)
{
	get_total_nbr_lines(map);
	map->fd = open(map->map_path, O_RDONLY);
	get_elements(map);
	check_ceiling_comma(map);
	check_elements(map, map->ceiling_texture, "C");
	check_floor_comma(map);
	check_elements(map, map->floor_texture, "F");
	get_map_size(map);
	get_map_to_array(map);
	check_map_integrity(map);
}
