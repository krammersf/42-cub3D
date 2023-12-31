/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:26 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/31 11:25:48 by fde-carv         ###   ########.fr       */
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
/*
The function uses the `ft_strrchr` function to find the last occurrence of the
'/' character in the filename. This is typically used to isolate the filename
from the rest of the path. If a '/' is found, the pointer `s` is incremented to
point to the character after the '/'. The function then checks if the length of
the string from this point is less or equal to 4. If it is, the function returns
`false`, as the filename (excluding the path) is too short to have a ".cub"
extension.
*/
