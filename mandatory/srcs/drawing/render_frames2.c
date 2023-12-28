/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:05:09 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/28 22:58:43 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// It determines the next horizontal or vertical boundary that the ray
// intersects, checks if the ray has hit a wall, and calculates the distance to
// the wall.
static void	check_hit(t_game *game)
{
	while (game->hit == '0')
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_dist_x;
			game->map_x += game->step_x;
			game->side = '0';
		}
		else
		{
			game->side_dist_y += game->delta_dist_y;
			game->map_y += game->step_y;
			game->side = '1';
		}
		if (game->map_ptr->world_map[game->map_x][game->map_y] != '0')
			game->hit = '1';
	}
	if (game->side == '0')
		game->perp_wall_dist = (game->side_dist_x - game->delta_dist_x);
	else
		game->perp_wall_dist = (game->side_dist_y - game->delta_dist_y);
}
/*
This function is part of a raycasting algorithm, which is commonly used in
3D game engines to determine what is visible to the player.

The function starts with a loop that continues as long as `game->hit` is '0'.
Inside this loop, the function checks if `game->side_dist_x` is less than
`game->side_dist_y`. If it is, the function increments `game->side_dist_x`
by `game->delta_dist_x`, increments `game->map_x` by `game->step_x`, and sets
`game->side` to '0'. Otherwise, it increments `game->side_dist_y` by
`game->delta_dist_y`, increments `game->map_y` by `game->step_y`, and sets
`game->side` to '1'. 
--> This part of the code is responsible for determining the next horizontal
or vertical boundary that the ray intersects.

The function then checks if the character at the current map position in
`game->map_ptr->world_map` is not '0'. If it's not, the function sets
`game->hit` to '1'. 
--> This part of the code is responsible for checking if the ray has hit a
wall.

After the loop, the function checks if `game->side` is '0'. If it is, the
function calculates the perpendicular distance to the wall by subtracting
`game->delta_dist_x` from `game->side_dist_x` and assigns the result to
`game->perp_wall_dist`. Otherwise, it calculates the perpendicular distance
to the wall by subtracting `game->delta_dist_y` from `game->side_dist_y` and
assigns the result to `game->perp_wall_dist`.
--> This part of the code is responsible for calculating the distance to the
wall, which is used to determine how tall the wall should be drawn.

It determines the next horizontal or vertical boundary that the ray
intersects, checks if the ray has hit a wall, and calculates the distance to
the wall.
*/

// This function calculates the properties of each vertical strip of the screen
// that needs to be drawn, including the height of the line, the start and end
// points for drawing the line, the texture coordinates, and the step size for
// moving through the texture.
static void	calculate_walls(t_game *game)
{
	game->pitch = 0;
	game->line_height = (int)(SCREEN_HEIGHT / game->perp_wall_dist);
	game->draw_start = -game->line_height / 2 + SCREEN_HEIGHT / 2 + game->pitch;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + SCREEN_HEIGHT / 2 + game->pitch;
	if (game->draw_end >= SCREEN_HEIGHT)
		game->draw_end = SCREEN_HEIGHT - 1;
	if (game->side == '0')
		game->map_ptr->wall_x = game->pos_y + \
			game->perp_wall_dist * game->ray_dir_y;
	else
		game->map_ptr->wall_x = game->pos_x + \
			game->perp_wall_dist * game->ray_dir_x;
	game->map_ptr->wall_x -= floor((game->map_ptr->wall_x));
	game->texture_x = (int)(game->map_ptr->wall_x * (double)TEX_WIDTH);
	if (game->side == '0' && game->ray_dir_x > 0)
		game->texture_x = TEX_WIDTH - game->texture_x - 1;
	if (game->side == '1' && game->ray_dir_y < 0)
		game->texture_x = TEX_WIDTH - game->texture_x - 1;
	game->map_ptr->step = 1.0 * TEX_HEIGHT / game->line_height;
	game->map_ptr->tex_pos = (game->draw_start - game->pitch - \
		(double)SCREEN_HEIGHT / 2 + (double)game->line_height / 2) * \
			game->map_ptr->step;
}
/*
This function is part of a 3D game engine, specifically a part of the rendering
process that calculates the properties of each vertical strip (or "wall") of
the screen that needs to be drawn.

The function starts by setting `game->pitch` to 0. This is be used to adjust
the vertical viewing angle, but since it's always set to 0, it doesn't have
any effect in this code.

Next, the function calculates the height of the line to be drawn on the screen,
which represents a vertical strip of a wall in the 3D world. This is done by
dividing the screen height by the perpendicular distance to the wall
(`game->perp_wall_dist`), which was calculated in a previous step of the
raycasting algorithm.

The function then calculates the start and end points for drawing the line on
the screen. The start point (`game->draw_start`) is calculated by subtracting
half the line height from the middle of the screen and adding the pitch. If
the start point is less than 0, it's set to 0 to ensure that it doesn't go off
the top of the screen. The end point (`game->draw_end`) is calculated in a
similar way, but if it's greater than or equal to the screen height, it's set
to one less than the screen height to ensure that it doesn't go off the bottom
of the screen.

The line `game->map_ptr->wall_x -= floor((game->map_ptr->wall_x));` is
subtracting the floor value of `game->map_ptr->wall_x` from
`game->map_ptr->wall_x` itself. The `floor` function rounds down the value to
the nearest whole number. This operation effectively keeps only the fractional
part of `game->map_ptr->wall_x`, which represents the exact hit point on the
wall in the map where the ray intersects.

The line `game->texture_x = (int)(game->map_ptr->wall_x * (double)TEX_WIDTH);`
is calculating the x-coordinate on the texture to be mapped on the wall. It
multiplies the fractional part of `game->map_ptr->wall_x` (which is between 0
and 1) by the texture width (`TEX_WIDTH`). This gives the exact horizontal
position on the texture that corresponds to the hit point on the wall. The
result is then cast to an integer and stored in `game->texture_x`. This value
will be used to draw the correct part of the texture on the screen.

The function then calculates the exact horizontal position of the wall that
was hit by the ray. This is done differently depending on whether the ray hit
a wall on the north/south side (`game->side` is '0') or the east/west side
(`game->side` is '1'). The fractional part of this position is then used to
determine the x-coordinate of the texture that should be used to draw the wall
(`game->texture_x`).

The function then adjusts the texture x-coordinate if necessary. If the ray
was moving to the right and hit a north/south wall, or if the ray was moving
up and hit an east/west wall, the texture x-coordinate is flipped horizontally.
This is done to ensure that the textures are drawn correctly.

Finally, the function calculates the step size for moving through the texture
vertically (`game->map_ptr->step`) and the initial texture y-coordinate
(`game->map_ptr->tex_pos`). These are used to determine which part of the
texture should be drawn for each pixel of the line on the screen.
*/

// This function draws a vertical strip of the screen by looping through each
// pixel in the line on the screen, determining which texture to use based on
// the direction of the ray and the side of the wall that was hit, getting the
// color of the appropriate pixel from the texture, and drawing the pixel on
// the screen.
static void	draw_walls(t_game *game, int *x)
{
	int	y;
	int	tex_y;

	y = game->draw_start;
	while (y <= game->draw_end)
	{
		tex_y = (int)game->map_ptr->tex_pos & (TEX_HEIGHT - 1);
		game->map_ptr->tex_pos += game->map_ptr->step;
		if (game->side == '0' && game->ray_dir_x > 0)
			ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
				ft_pixel_get(&game->txt_ptr[south], game->texture_x, tex_y));
		else if (game->side == '0' && game->ray_dir_x < 0)
			ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
				ft_pixel_get(&game->txt_ptr[north], game->texture_x, tex_y));
		else if (game->side == '1' && game->ray_dir_y > 0)
			ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
				ft_pixel_get(&game->txt_ptr[east], game->texture_x, tex_y));
		else if (game->side == '1' && game->ray_dir_y < 0)
			ft_pixel_put(game->mini_ptr, *x, y, (unsigned int)
				ft_pixel_get(&game->txt_ptr[west], game->texture_x, tex_y));
		y++;
	}
}
/*
This function is responsible for drawing a vertical strip (or "walls") of the
screen, which represents a part of a wall in the 3D world.

The function starts by setting y to game->draw_start, which is the starting point
for drawing the line on the screen. This value was calculated in a previous step
of the rendering process.

The function then enters a loop that continues as long as y is less than or equal
to game->draw_end, which is the ending point for drawing the line on the screen.
Inside this loop, the function calculates the y-coordinate of the texture to be
used to draw the wall (tex_y). This is done by taking the bitwise AND of
game->map_ptr->tex_pos and TEX_HEIGHT - 1. The game->map_ptr->tex_pos value is
then incremented by game->map_ptr->step, which is the step size for moving
through the texture vertically.

The function then checks the direction of the ray and the side of the wall that
was hit to determine which texture to use. If the ray was moving to the right
and hit a north/south wall, the function uses the texture for the south side of
the wall. If the ray was moving to the left and hit a north/south wall, the
function uses the texture for the north side of the wall. If the ray was moving
down and hit an east/west wall, the function uses the texture for the east side
of the wall. If the ray was moving up and hit an east/west wall, the function
uses the texture for the west side of the wall.

The function then calls ft_pixel_put to draw a pixel on the screen at the
position (*x, y) with the color obtained from the appropriate texture at the
position (game->texture_x, tex_y). The ft_pixel_get function is used to get the
color of a pixel from a texture.

Finally, the function increments y to move to the next pixel in the line on
the screen.
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
