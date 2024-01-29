/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:22:50 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/25 12:31:20 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

//finds the larget line in the map.cub
void	set_larger_line(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_ptr->map_end - game->map_ptr->map_start)
	{
		if ((int)ft_strlen(game->map_ptr->world_map[i])
			> game->map_ptr->larger_line)
			game->map_ptr->larger_line = ft_strlen(game->map_ptr->world_map[i]);
		i++;
	}
}

//alocates memory to draw the recatngle little_map
void	fill_lines_little_map(t_game *game, int i, int end)
{
	int	j;
	int	len;

	len = game->map_ptr->larger_line + 20 + 1;
	while (i < end)
	{
		game->littlemap_ptr->little_map[i] = malloc(sizeof(char) * len);
		j = 0;
		while (j < len - 1)
		{
			game->littlemap_ptr->little_map[i][j] = '#';
			j++;
		}
		game->littlemap_ptr->little_map[i][j] = '\0';
		i++;
	}
}

// add spaces to the biginning and end of the littlemap
void	add_spaces(t_game *game)
{
	int		i;
	char	*to_fill;
	char	*temp1;
	char	*temp2;

	fill_lines_little_map(game, 0, 5);
	to_fill = "**********";
	i = 5;
	while (i < (game->map_ptr->map_end - game->map_ptr->map_start) + 5)
	{
		temp2 = ft_strjoin(game->map_ptr->world_map[i - 5], "\n");
		temp1 = ft_strjoin(to_fill, temp2);
		free(temp2);
		game->littlemap_ptr->little_map[i] = ft_strjoin(temp1, to_fill);
		free(temp1);
		i++;
	}
	fill_lines_little_map(game, i, game->map_ptr->map_end \
		- game->map_ptr->map_start + 10);
}

// choose the colors of the rectangle little map
unsigned int	put_color(char c)
{
	if (c != '0')
	{
		if (c == 'D')
			return (0xFF0000);
		if (c == 'U')
			return (0x00FF00);
		return (0x3B3B3B);
	}
	else
		return (0xCBCBCB);
}

// draws the rectangle of the little map and the puts color in the net
void	draw_rectangle(t_game *game, int x, int y, unsigned int color)
{
	int				x_end;
	int				y_end;
	int				start_y;
	int				start_x;

	start_x = x;
	x_end = x + (SCREEN_HEIGHT * 0.0125);
	y_end = y + (SCREEN_WIDTH * 0.009375);
	start_y = y;
	while (x < x_end)
	{
		y = start_y;
		while (y < y_end)
		{
			if (x == x_end - 1 || y == y_end - 1
				|| x == start_x || y == start_y)
				ft_pixel_put(game->mini_ptr, y, x, 0x0000FF);
			else
				ft_pixel_put(game->mini_ptr, y, x, color);
			y++;
		}
		x++;
	}
}
