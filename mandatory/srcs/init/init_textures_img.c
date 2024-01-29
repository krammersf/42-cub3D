/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:21:33 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/29 18:16:59 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_validate_xpm(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->txt_ptr[i].img == NULL)
			error_close("bad xpm file convertion", game->map_ptr);
		i++;
	}
}

// function to initialize the textures images from walls
void	init_textures_img(t_game *game)
{
	game->txt_ptr[south].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->south_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	game->txt_ptr[north].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->north_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	game->txt_ptr[east].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->east_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	game->txt_ptr[west].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->west_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	check_validate_xpm(game);
	game->txt_ptr[south].addr = mlx_get_data_addr(game->txt_ptr[south].img,
			&game->txt_ptr[south].bits_per_pixel,
			&game->txt_ptr[south].line_length, &game->txt_ptr[south].endian);
	game->txt_ptr[north].addr = mlx_get_data_addr(game->txt_ptr[north].img,
			&game->txt_ptr[north].bits_per_pixel,
			&game->txt_ptr[north].line_length, &game->txt_ptr[north].endian);
	game->txt_ptr[east].addr = mlx_get_data_addr(game->txt_ptr[east].img,
			&game->txt_ptr[east].bits_per_pixel,
			&game->txt_ptr[east].line_length, &game->txt_ptr[east].endian);
	game->txt_ptr[west].addr = mlx_get_data_addr(game->txt_ptr[west].img,
			&game->txt_ptr[west].bits_per_pixel,
			&game->txt_ptr[west].line_length, &game->txt_ptr[west].endian);
}
