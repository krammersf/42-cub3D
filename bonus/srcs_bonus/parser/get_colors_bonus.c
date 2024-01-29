/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:08:54 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 13:18:00 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
  converts the string to a number and fills the t_rgb struct with RGB values
  and checks if RGB lenght is valid
*/
int	fill_t_rgb_ckeck_rgb_size(t_rgb *rgb, char *red, char *green, char *blue)
{
	if (ft_strlen(red) <= 3 && ft_strlen(green) <= 3 && ft_strlen(blue) <= 3)
	{
		rgb->red = ft_atoi(red);
		rgb->green = ft_atoi(green);
		rgb->blue = ft_atoi(blue);
		return (0);
	}
	else
		return (1);
}

// define celing and floor colors
void	define_rgb_colors(t_map *map, char **rgb, char *str)
{
	if (ft_strncmp(str, "C", 1) == 0)
	{
		if (fill_t_rgb_ckeck_rgb_size(&map->ceiling_colors, rgb[1], \
			rgb[2], rgb[3]))
			close_free("Invalid lenght in RGB ceiling colors.", rgb, map);
		if (!is_valid_colors(&map->ceiling_colors))
			close_free("Invalid ceiling colors.", rgb, map);
	}
	else if (ft_strncmp(str, "F", 1) == 0)
	{
		if (fill_t_rgb_ckeck_rgb_size(&map->floor_colors, rgb[1], \
			rgb[2], rgb[3]))
			close_free("Invalid lenght in RGB floor colors.", rgb, map);
		if (!is_valid_colors(&map->floor_colors))
			close_free("Invalid floor color", rgb, map);
	}
}

// checks if there is a space after the comma in floor_texture
void	check_floor_comma(t_map *map)
{
	int		i;
	char	*str;
	char	*msg1;
	char	*msg2;

	i = 0;
	str = map->floor_texture;
	msg1 = "Problem with floor colors. Space(s) or tab(s) after \",\"";
	msg2 = "Problem with floor colors. Space(s) or tab(s) before \",\"";
	while (str[i])
	{
		if (str[i] == ',' && isspace(str[i + 1]))
			error_close_fd(msg1, map, map->fd);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (isspace(str[i]) && str[i + 1] == ',')
			error_close_fd(msg2, map, map->fd);
		i++;
	}
}

// checks if there is a space after the comma in ceiling_texture
void	check_ceiling_comma(t_map *map)
{
	int		i;
	char	*str;
	char	*msg1;
	char	*msg2;

	i = 0;
	str = map->ceiling_texture;
	msg1 = "Problem with ceiling colors. Space(s) or tab(s) after \",\"";
	msg2 = "Problem with ceiling colors. Space(s) or tab(s) before \",\"";
	while (str[i])
	{
		if (str[i] == ',' && isspace(str[i + 1]))
			error_close_fd(msg1, map, map->fd);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (isspace(str[i]) && str[i + 1] == ',')
			error_close_fd(msg2, map, map->fd);
		i++;
	}
}

// checks if the elements are valid (digits and size of 3)
void	check_elements(t_map *map, char *texture, char *c)
{
	int		x;
	int		y;
	char	**array;

	x = 1;
	y = 0;
	array = ft_split_set(texture, "\n, \t");
	if (get_arr_size(array) != 4)
		close_free("Invalid color feed. Has to have 3 elements \"RGB\".", \
			array, map);
	while (array[x])
	{
		y = 0;
		while (array[x][y] && array[x][y] != '\n')
			if (!ft_isdigit(array[x][y++]))
				close_free("Invalid character in color definition.", \
					array, map);
		x++;
	}
	define_rgb_colors(map, array, c);
	free_arr1(array);
}
