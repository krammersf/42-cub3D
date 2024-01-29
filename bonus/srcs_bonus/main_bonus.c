/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:33:20 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/28 17:47:52 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_game	game;
	t_map	map;

	mlx = (t_mlx){0};
	game = (t_game){0};
	map = (t_map){0};
	check_input(ac, av[1], &map);
	init_t_map(&map, &game);
	init_game(&game, &map, &mlx);
	init_new_textures_bonus(&map, &game);
	init_mlx(&mlx);
	mlx.game_ptr = &game;
	read_cub_file(&map);
	open_window(&mlx, SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
	init_textures_img(&game);
	img_hands(&game);
	mlx_hook(mlx.mlx_win, 2, 1L << 0, &handle_keypress, &game);
	mlx_hook(mlx.mlx_win, 3, 1L << 1, &handle_keyrelease, &game);
	mlx_hook(mlx.mlx_win, 17, 0, &close_window, &game);
	mlx_hook(mlx.mlx_win, 6, 1L << 6, &handle_mouse_movement, &mlx);
	mlx_hook(mlx.mlx_win, 4, 1L << 2, &handle_mouse_click_down, &mlx);
	mlx_loop_hook(mlx.mlx, render_frames_total, &game);
	mlx_loop(mlx.mlx);
	return (0);
}
