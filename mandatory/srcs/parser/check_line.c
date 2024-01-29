/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:49:45 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 13:38:07 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// checks if the map elements are correct
int	check_elem_file(char *line)
{
	if (ft_strcmp("NO", line) == 0
		|| ft_strcmp("SO", line) == 0
		|| ft_strcmp("WE", line) == 0
		|| ft_strcmp("EA", line) == 0
		|| ft_strcmp("F", line) == 0 || ft_strcmp("C", line) == 0)
		return (1);
	return (0);
}

// checks if the map elements are correct, if not print error and closes window
void	check_elem_file_is_ok(char *line, char **arr, t_map *map)
{
	if (!check_elem_file(line))
	{
		free_arr1(arr);
		free(map->get_line);
		error_close_fd("Check map elements. Possible wrong element name.", \
			map, map->fd);
	}
}
