/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_img_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:21:33 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/29 14:39:06 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	check_validate_xpm(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->txt_ptr[i].img == NULL)
			error_close("bad xpm file convertion", game->map_ptr);
		i++;
	}
}

void	init_textures_img3(t_game *game)
{
	game->txt_ptr[door].addr = mlx_get_data_addr(game->txt_ptr[door].img,
			&game->txt_ptr[door].bits_per_pixel,
			&game->txt_ptr[door].line_length, &game->txt_ptr[door].endian);
	game->txt_ptr[aaa].addr = mlx_get_data_addr(game->txt_ptr[aaa].img,
			&game->txt_ptr[aaa].bits_per_pixel,
			&game->txt_ptr[aaa].line_length, &game->txt_ptr[aaa].endian);
	game->txt_ptr[bbb].addr = mlx_get_data_addr(game->txt_ptr[bbb].img,
			&game->txt_ptr[bbb].bits_per_pixel,
			&game->txt_ptr[bbb].line_length, &game->txt_ptr[bbb].endian);
	game->txt_ptr[ccc].addr = mlx_get_data_addr(game->txt_ptr[ccc].img,
			&game->txt_ptr[ccc].bits_per_pixel,
			&game->txt_ptr[ccc].line_length, &game->txt_ptr[ccc].endian);
	game->txt_ptr[ddd].addr = mlx_get_data_addr(game->txt_ptr[ddd].img,
			&game->txt_ptr[ddd].bits_per_pixel,
			&game->txt_ptr[ddd].line_length, &game->txt_ptr[ddd].endian);
}

void	init_textures_img2(t_game *game)
{
	game->txt_ptr[ccc].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->ccc_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	game->txt_ptr[ddd].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->ddd_texture, &game->txt_ptr->txt_w,
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
	init_textures_img3(game);
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
	game->txt_ptr[door].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->door_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	game->txt_ptr[aaa].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->aaa_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	game->txt_ptr[bbb].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->bbb_texture, &game->txt_ptr->txt_w,
			&game->txt_ptr->txt_h);
	check_validate_xpm(game);
	init_textures_img2(game);
}

void	init_new_textures_bonus(t_map *map, t_game *game)
{
	(void)game;
	map->animated_hands = ft_calloc(3, sizeof(char *));
	map->animated_hands[0] = "./bonus/textures/handsgun00.xpm";
	map->animated_hands[1] = "./bonus/textures/handsgun01.xpm";
	map->animated_hands[2] = "./bonus/textures/handsgun02.xpm";
	map->aaa_texture = "./bonus/textures/aaa.xpm";
	map->bbb_texture = "./bonus/textures/bbb.xpm";
	map->ccc_texture = "./bonus/textures/eaglewall.xpm";
	map->ddd_texture = "./bonus/textures/flagwall.xpm";
}
