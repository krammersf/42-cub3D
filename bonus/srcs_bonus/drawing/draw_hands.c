/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:03:19 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/28 21:50:41 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	shooting(t_game *game)
{
	game->map_ptr->current_time = get_actual_time();
	if (game->press_e == 1)
	{
		if (game->map_ptr->current_time - game->map_ptr->start_time_hand > 100)
		{
			game->swap_hands++;
			if (game->swap_hands == 3)
			{
				game->swap_hands = 0;
				game->press_e = 0;
			}
			game->map_ptr->start_time_hand = get_actual_time();
		}
	}
}

//primeira escolha
void	draw_hands(t_game *game)
{
	t_hands	hands;

	hands.x = SCREEN_WIDTH * 0.320;
	hands.y = SCREEN_HEIGHT;
	hands.a = (510.0 / ((double)SCREEN_WIDTH / 0.45));
	hands.b = (510.0 / ((double)SCREEN_HEIGHT / 0.45));
	hands.begin_x = (SCREEN_WIDTH * 0.265);
	hands.begin_y = 0 + (SCREEN_HEIGHT \
		- (SCREEN_HEIGHT / 3.2 + SCREEN_HEIGHT / 4.0));
	shooting(game);
	while (hands.x < SCREEN_WIDTH * 0.76)
	{
		hands.y = 0 + SCREEN_HEIGHT \
			- (SCREEN_HEIGHT / 4.75 + SCREEN_HEIGHT / 3.75);
		while (hands.y < SCREEN_HEIGHT)
		{
			ft_pixel_put(game->mini_ptr, hands.x, hands.y,
				(unsigned int)ft_pixel_get(&game->txt_hands[game->swap_hands],
					(int)((hands.x - hands.begin_x) * hands.a), \
					(int)((hands.y - hands.begin_y) * hands.b)));
			hands.y++;
		}
		hands.x++;
	}
}

void	img_hands(t_game *game)
{
	game->map_ptr->start_time_hand = get_actual_time();
	game->swap_hands = 0;
	game->txt_hands = malloc(sizeof(t_texture) * 4);
	game->txt_hands[0].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->animated_hands[0], &game->txt_hands[0].txt_w,
			&game->txt_hands[0].txt_h);
	game->txt_hands[0].addr = mlx_get_data_addr(game->txt_hands[0].img,
			&game->txt_hands[0].bits_per_pixel, &game->txt_hands[0].line_length,
			&game->txt_hands[0].endian);
	game->txt_hands[1].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->animated_hands[1], &game->txt_hands[1].txt_w,
			&game->txt_hands[1].txt_h);
	game->txt_hands[1].addr = mlx_get_data_addr(game->txt_hands[1].img,
			&game->txt_hands[1].bits_per_pixel, &game->txt_hands[1].line_length,
			&game->txt_hands[1].endian);
	game->txt_hands[2].img = mlx_xpm_file_to_image(game->mini_ptr->mlx,
			game->map_ptr->animated_hands[2], &game->txt_hands[2].txt_w,
			&game->txt_hands[2].txt_h);
	game->txt_hands[2].addr = mlx_get_data_addr(game->txt_hands[2].img,
			&game->txt_hands[2].bits_per_pixel, &game->txt_hands[2].line_length,
			&game->txt_hands[2].endian);
}
