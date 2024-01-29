/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:16:44 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 13:09:41 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	get_arr_size(char **arr)
{
	int		size;

	size = 0;
	while (arr[size] != NULL)
		size++;
	return (size);
}

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool	is_valid_colors(t_rgb *colors)
{
	if (colors->red < 0 || colors->green < 0 || colors->blue < 0)
		return (false);
	if (colors->red > 255 || colors->green > 255 || colors->blue > 255)
		return (false);
	return (true);
}

long long	get_actual_time(void)
{
	long long			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		return (0);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}
