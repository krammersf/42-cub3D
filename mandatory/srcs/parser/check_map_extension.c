/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:26 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/12 16:40:05 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// checks if the map extension is .cub and is parameters  
bool	check_map_extension(t_map *map, char *filename)
{
	if (ft_strlen(filename) <= 4)
		return (false);
	map->extension = ".cub";
	if (!ft_strnstr((filename + ft_strlen(filename) - 4), map->extension, 4))
		return (false);
	return (true);
}
