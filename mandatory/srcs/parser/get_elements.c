/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:39 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/02 17:35:29 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// alocates memory to the line and return a pointer to the copy
char	*get_texture(char *line)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	size = ft_strlen(line);
	i = 0;
	j = 0;
	while (i < size - 1 && (line[i] == ' '))// || line[i] == '\t'))
		i++;
	if (line[i + 1] == '\n' || line[i + 1] == '\0')
		return (NULL);
	str = malloc((sizeof(char) * ft_strlen(line) + 1));
	if (!str)
		return (NULL);
	while (line[i] && line[i] != '\n')
		str[j++] = line[i++];
	str[j] = '\0';
	return (str);
}

// gets "C" and "F" elements and duplicates it to the map struct
void	get_elements_colors_textures(t_map *map, char **line_arr)
{
	if (!map->ceiling_texture)
		if (!ft_strncmp("C", line_arr[0], 2))
			map->ceiling_texture = ft_strdup(map->get_line);
	if (!map->floor_texture)
		if (!ft_strncmp("F", line_arr[0], 2))
			map->floor_texture = ft_strdup(map->get_line);
}

void	check_textures_paths(t_map *map)
{
	access_path(map, map->north_texture);
	access_path(map, map->south_texture);
	access_path(map, map->west_texture);
	access_path(map, map->east_texture);
}

// gets the textures and the c and f colours of the map
void	get_elements(t_map *map)
{
	char	**line_arr;

	map->get_line = get_next_line(map->fd);
	while (map->get_line != NULL)
	{
		map->line_nbr++;
		//printf("line_nbr: %d\n", map->line_nbr);//DEBUG
		//printf("map->get_line_FIRTS: %s", map->get_line);//DEBUG
		line_arr = ft_split_set(map->get_line, " \t");
		if (ft_strncmp("\n", line_arr[0], 1) != 0)
		{
			printf("line_arr[0]: %s\n", line_arr[0]);//DEBUG
			check_elem_file_is_ok(line_arr[0], line_arr, map);
			get_elements_textures(map, line_arr);//modificado
			get_elements_colors_textures(map, line_arr);
			if (map->north_texture && map->south_texture && map->west_texture
				&& map->east_texture && map->ceiling_texture
				&& map->floor_texture != NULL)
			{
				free_arr1(line_arr);
				break ;
			}
		}
		free_total(line_arr, map->get_line);
		//if(!map->get_line)
		//	free(map->get_line);
		map->get_line = get_next_line(map->fd);	
		//printf("map->get_line__LAST: %s\n", map->get_line);//DEBUG
	}
	//	free(map->get_line);//PROBLEM
	check_textures_paths(map);
	//if (!map->ceiling_texture || !map->floor_texture)
	//	perror_close("Problem reading colors in ceiling / floor.", map);//nao reproduzir este erro
}
