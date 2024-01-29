/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_walls3..c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:34:06 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/28 21:35:48 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_pixel_aaa(t_game *game, int *x, int y, int tex_y)
{
	ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
		ft_pixel_get(&game->txt_ptr[aaa], game->texture_x, tex_y));
}

void	draw_pixel_bbb(t_game *game, int *x, int y, int tex_y)
{
	ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
		ft_pixel_get(&game->txt_ptr[bbb], game->texture_x, tex_y));
}

void	draw_pixel_south(t_game *game, int *x, int y, int tex_y)
{
	ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
		ft_pixel_get(&game->txt_ptr[south], game->texture_x, tex_y));
}

void	draw_pixel_north(t_game *game, int *x, int y, int tex_y)
{
	ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
		ft_pixel_get(&game->txt_ptr[north], game->texture_x, tex_y));
}

void	draw_pixel_east(t_game *game, int *x, int y, int tex_y)
{
	ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
		ft_pixel_get(&game->txt_ptr[east], game->texture_x, tex_y));
}
