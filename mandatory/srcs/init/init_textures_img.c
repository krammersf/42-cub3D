/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:21:33 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/27 22:13:25 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// function to initialize the textures images from walls
void	init_textures_img(t_game *game)
{
	game->txt_ptr[south].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->south_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	game->txt_ptr[south].addr = mlx_get_data_addr(game->txt_ptr[south].img,
	 		&game->txt_ptr[south].bits_per_pixel,
	 		&game->txt_ptr[south].line_length, &game->txt_ptr[south].endian);
	game->txt_ptr[north].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->north_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	game->txt_ptr[north].addr = mlx_get_data_addr(game->txt_ptr[north].img,
	 		&game->txt_ptr[north].bits_per_pixel,
	 		&game->txt_ptr[north].line_length, &game->txt_ptr[north].endian);
	game->txt_ptr[east].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->east_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	game->txt_ptr[east].addr = mlx_get_data_addr(game->txt_ptr[east].img,
			&game->txt_ptr[east].bits_per_pixel,
			&game->txt_ptr[east].line_length, &game->txt_ptr[east].endian);
	game->txt_ptr[west].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->west_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	game->txt_ptr[west].addr = mlx_get_data_addr(game->txt_ptr[west].img,
			&game->txt_ptr[west].bits_per_pixel,
			&game->txt_ptr[west].line_length, &game->txt_ptr[west].endian);
}
