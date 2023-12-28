/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:53:33 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/27 22:13:25 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_player_up(t_game *game)
{
	move_p_up(game->mini_ptr);
	if (game->move_left == 1)
	{
		move_p_left(game->mini_ptr);
		if (game->slide_left == 1)
			move_p_slide_left(game->mini_ptr);
	}
	else if (game->move_right == 1)
	{
		move_p_right(game->mini_ptr);
		if (game->slide_right == 1)
			move_p_slide_right(game->mini_ptr);
	}
	else if (game->slide_left == 1)
		move_p_slide_left(game->mini_ptr);
	else if (game->slide_right == 1)
		move_p_slide_right(game->mini_ptr);
}

void	move_player_down(t_game *game)
{
	move_p_down(game->mini_ptr);
	if (game->move_left == 1)
	{
		move_p_left(game->mini_ptr);
		if (game->slide_left == 1)
			move_p_slide_left(game->mini_ptr);
	}
	else if (game->move_right == 1)
	{
		move_p_right(game->mini_ptr);
		if (game->slide_right == 1)
			move_p_slide_right(game->mini_ptr);
	}
	else if (game->slide_left == 1)
		move_p_slide_left(game->mini_ptr);
	else if (game->slide_right == 1)
		move_p_slide_right(game->mini_ptr);
}

void	move_player(t_game *game)
{
	if (game->move_up == 1)
		move_player_up(game);
	else if (game->move_down == 1)
		move_player_down(game);
	else if (game->move_left == 1)
		move_p_left(game->mini_ptr);
	else if (game->move_right == 1)
		move_p_right(game->mini_ptr);
	else if (game->slide_left == 1)
		move_p_slide_left(game->mini_ptr);
	else if (game->slide_right == 1)
		move_p_slide_right(game->mini_ptr);
}
