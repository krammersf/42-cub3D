/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:37:24 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/25 20:24:26 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// chekcs ac elements, the map extension and the path 
int	check_input(int ac, char *path_str, t_map *map)
{
	int		temp_fd;

	if (ac != 2)
	{
		printf("\033[1;31mError!\n\033[1;33mUsage: \
			./cube3d <map_path>\033[0m\n");//OK
		exit(EXIT_FAILURE);
	}
	map->map_path = path_str;
	if (!check_map_extension(map, path_str))
	{
		printf("\033[1;31mError!\n\033[1;33mWrong file extension.\033[0m\n");//OK
		exit(EXIT_FAILURE);
	}
	temp_fd = open(map->map_path, O_RDONLY);
	if (temp_fd == -1)
	{
		printf("\033[1;31mError!\n\033[1;33mCannot open file.\033[0m\n");//OK
		exit(EXIT_FAILURE);
	}
	close(temp_fd);
	return (1);
}
