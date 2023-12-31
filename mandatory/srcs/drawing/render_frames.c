/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:05:09 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/31 12:17:35 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// gets the color of the floor int bites and stores it in t_map
void	get_bite_floor_color(t_map *map)
{
	t_rgb	*floor;

	floor = &map->floor_colors;
	map->f_color_bites = get_rgb(floor->red, floor->green, floor->blue);
	//printf("FRED floor: %d\n", map->f_color_bites);
}

// gets the color of the ceiling int bites and stores it in t_map
void	get_bite_ceiling_color(t_map *map)
{
	t_rgb	*ceiling;

	ceiling = &map->ceiling_colors;
	map->c_color_bites = get_rgb(ceiling->red, ceiling->green, ceiling->blue);
	//printf("FRED ceiling: %d\n", map->c_color_bites);
}

// raycasting function to render the frames
void	render_frames_1(t_game *game, int *x)
{
	game->camera_x = 2 * *x / (double)SCREEN_WIDTH - 1; // ( -1 to 1 )
	game->ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
	game->ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
	game->map_x = (int)game->pos_x;
	//printf("map_x: %d\n", game->map_x);
	game->map_y = (int)game->pos_y;
	//printf("map_y: %d\n", game->map_y);
	if (game->ray_dir_x == 0)
		game->delta_dist_x = 1e20;
	else
		game->delta_dist_x = fabs(1.0 / game->ray_dir_x);
	if (game->ray_dir_y == 0)
		game->delta_dist_y = 1e20;
	else
		game->delta_dist_y = fabs(1.0 / game->ray_dir_y);
	game->hit = '0';
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x - game->map_x) * game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->pos_x) * \
			game->delta_dist_x;
	}
}
/*
This function is part of a raycasting engine, which is a technique used in
3D graphics to render a scene. The function takes two parameters: a pointer to
a t_game structure, which holds the state of the game, and a pointer to an
integer x, which represents the x-coordinate of a pixel on the screen.

The function starts by calculating the camera_x value, which represents the
x-coordinate in camera space. This is done by scaling the x value from screen
space to camera space. The result is a value between -1 and 1.

Next, the function calculates the direction of the ray for the current pixel.
This is done by adding the direction of the camera (dir_x and dir_y) to the
projection of the camera space x-coordinate (game->camera_x )onto the camera
plane (plane_x and plane_y).

The function then calculates the 'map square' in which the camera is located
(map_x and map_y). This is done by truncating the camera position
(pos_x and pos_y) to an integer.

The function then calculates the length of the ray from one x or y-side to
the next x or y-side (delta_dist_x and delta_dist_y). This is done by taking
the absolute value of 1 divided by the ray direction. If the ray direction 
is zero, the length is set to a very large number (1e30) to avoid division
by zero.

The function then initializes the hit field to '0', indicating that no wall
has been hit yet.

Finally, the function calculates the step direction for the ray (step_x) and
the initial side distance (side_dist_x). This is done differently depending
on whether the ray direction is negative or positive. If the ray direction is
negative, the step direction is -1 and the side distance is calculated based
on the difference between the camera position and the map square. If the ray
direction is positive, the step direction is 1 and the side distance is
calculated based on the difference between the next map square and the camera
position.
*/

// This function is part of the raycasting process in a 3D game engine.
// It calculates the properties of each vertical strip of the screen that
// needs to be drawn, checks if the ray has hit a wall, calculates the
// properties of the wall that was hit and draws a vertical wall on the screen
void	render_frames_2(t_game *game, int *x)
{
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->pos_y - game->map_y) * game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->pos_y) * \
			game->delta_dist_y;
	}
	if (game->map_x != 0 && game->map_y != 0)
		check_hit(game);
	calculate_walls(game);
	draw_walls(game, x);
}
/*
It takes two arguments: a pointer to a `t_game` structure and a pointer to an
integer `x`. This function is part of a 3D game engine, specifically a part of
the raycasting process that calculates the properties of each vertical strip
(or "wall") of the screen that needs to be drawn.

The function starts by checking if `game->ray_dir_y` is less than 0, which means
the ray is moving upwards on the map. If it is, the function sets `game->step_y`
to -1 and calculates `game->side_dist_y` as the distance from the current
position to the next horizontal grid line above the current position. If
`game->ray_dir_y` is not less than 0, which means the ray is moving downwards on
the map, the function sets `game->step_y` to 1 and calculates `game->side_dist_y`
as the distance from the current position to the next horizontal grid line below
the current position. The `game->delta_dist_y` value is used to scale these
distances based on the direction of the ray.

The function then checks if `game->map_x` and `game->map_y` are both non-zero.
If they are, the function calls `check_hit(game)`, which checks if the ray has
hit a wall on the map. It's a common step in the raycasting process.

The function then calls `calculate_walls(game)`, which calculates the properties
of the wall that was hit by the ray, such as the exact hit point and the distance
to the wall. It's another common step in the raycasting process.

Finally, the function calls `draw_cols(game, x)`, which draws a vertical strip
of the screen based on the properties of the wall that was hit by the ray.
*/

// Main function that compiles many 3D important functions. Draws background,
// walls, set move and rotation speed, margin and player movement.
int	render_frames_total(void *arg)
{
	t_game	*game;
	int		x;

	game = arg;
	get_bite_floor_color(game->map_ptr);
	get_bite_ceiling_color(game->map_ptr);
	background(*game->mini_ptr, game->map_ptr->c_color_bites, game->map_ptr->f_color_bites);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		render_frames_1(game, &x);
		render_frames_2(game, &x);
		x++;
	}
	fps(game);
	game->move_speed = game->frame_time * 2.0;//deslocamento(2.5)
	game->rot_speed = game->frame_time * 2.0;//rotacao(2.0)
	game->move_margin = 0.5;//margem(0.6)
	move_player(game);
	return (0);
}
/*
It takes one parameter: a pointer `arg` which is cast to a `t_game` structure
pointer, `game`, that holds the state of the game.

The function starts by calling `get_bite_floor_color` and
`get_bite_ceiling_color` functions, which presumably retrieve the floor and
ceiling colors from the game map.

Next, it calls the `background` function, which fills the background of the game
screen with the ceiling and floor colors.

The function then enters a `while` loop that iterates over the width of the
screen. For each x-coordinate, it calls `render_frames_1` and `render_frames_2`
functions. These functions perform the raycasting for each column of pixels on
the screen, making 3D rendering.

After the loop, the function calls the `fps` function, which calculates and
displays the frames per second.

The function then sets the move speed and rotation speed of the player based on
the frame time. This is a common technique in game development to ensure smooth
movement regardless of the frame rate. The move margin, used to prevent the
player from moving too close to walls, is also set.

Finally, the function calls the `move_player` function, which presumably updates
the player's position based on the player's input and the move speed.

The function then returns 0, and needs to be an int.
*/
