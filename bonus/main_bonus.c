/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:33:20 by ialves-m          #+#    #+#             */
/*   Updated: 2023/12/27 16:34:58 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	main(int ac, char **av)
{
	t_mlx	m;
	t_game	data;
	t_map	map;

	check_input(ac, av[1], &map);
	init_t_map(&map, &data);
	init_data(&data, &map, &m);
	init_bonus(&map, &data);
	init_mlx(&m);
	m.data_ptr = &data;
	read_cub_file(&map);
	open_window(&m, SCREEN_WIDTH, SCREEN_HEIGHT, "Cube3d Bonus");
	init_textures_img(&data);
	mlx_hook(m.mlx_win, 2, 1L << 0, &handle_keypress, &m);
	mlx_hook(m.mlx_win, 3, 1L << 1, &handle_keyrelease, &m);
	mlx_hook(m.mlx_win, 17, 0, close_window, &data);
	mlx_mouse_hook(m.mlx_win, &handle_mouse_fire, &data);
	mlx_hook(m.mlx_win, 06, 1L << 6, &handle_mouse, &data);
	mlx_loop_hook(m.mlx, render_frames_total, &data);
	mlx_loop(m.mlx);
	return (0);
}
