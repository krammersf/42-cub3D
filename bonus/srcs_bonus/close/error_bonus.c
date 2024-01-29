/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:08:33 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/27 13:32:18 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// prints eror msg and closes the window
void	error_close(char *msg, t_map *map)
{
	printf("\033[1;31mError!\n\033[1;33m%s\033[0m\n", msg);
	close_window(map->game_ptr);
}

// closes fd and prints eror msg and closes the window
void	error_close_fd(char *msg, t_map *map, int fd)
{
	close(fd);
	printf("\033[1;31mError!\n\033[1;33m%s\033[0m\n", msg);
	close_window(map->game_ptr);
}
