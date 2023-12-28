/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ttl_nbr_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:54 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/24 21:03:23 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// checks if the map file is empty if not count the lines
void	get_ttl_nbr_lines(t_map *map)
{
	int		fd;
	int		has_content;
	char	*line;

	fd = 0;
	fd = open(map->map_path, O_RDONLY);
	has_content = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1)
			has_content = 1;
		map->ttl_nbr_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (has_content == 0)
		perror_close("Empty file.", map);//OK
}
