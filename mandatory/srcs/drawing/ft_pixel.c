/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:30:46 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/31 11:34:09 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// function to get the color of a pixel in a texture	
int	ft_pixel_get(t_texture *txt, int x, int y)
{
	return (*(unsigned int *)((txt->addr + (y * txt->line_length) + \
		(x * txt->bits_per_pixel / 8))));
}
/*
This function is used to retrieve the color of a pixel at a specific position
in a texture. It takes three parameters: a pointer to a `t_texture` structure,
and the x and y coordinates of the pixel.

The function calculates the address of the pixel in the texture data. It does
this by adding the y coordinate times the line length and the x coordinate
times the bits per pixel divided by 8 to the base address of the texture data
(`txt->addr`). The bits per pixel is divided by 8 to convert it from bits to
bytes, since the address arithmetic is done in bytes. This calculation assumes
that the texture data is stored in a row-major order, where each row of pixels
is stored contiguously in memory.

After calculating the pixel address, the function retrieves the pixel color.
It does this by casting the calculated address to an `unsigned int` pointer
and then dereferencing it to read the color value. This assumes that the color
is represented as an `unsigned int`.

The function then returns the retrieved color.
*/

// function to draw a pixel on the screen
void	ft_pixel_put(t_mlx *mini, int x, int y, int color)
{
	char	*dest;

	dest = mini->addr + (y * mini->line_length + x * \
			(mini->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}
/*
This function is used to draw a pixel at a specific position on the screen with
a specific color. It takes four parameters: a pointer to a `t_mlx` structure,
the x and y coordinates of the pixel, and an integer representing the color.

The function starts by calculating the address of the pixel in the image data.
It does this by adding the y coordinate times the line length and the x
coordinate times the bits per pixel divided by 8 to the base address of the
image data (`mini->addr`). The result is a pointer to the pixel data, which is
stored in the `dest` variable.

The bits per pixel is divided by 8 to convert it from bits to bytes, since the
address arithmetic is done in bytes. This calculation assumes that the image
data is stored in a row-major order, where each row of pixels is stored
contiguously in memory.

After calculating the pixel address, the function sets the pixel color.
It does this by casting the `dest` pointer to an `unsigned int` pointer and
then dereferencing it to write the color value. This assumes that the color is
represented as an `unsigned int`.

This function assumes that the `t_mlx` structure has been properly initialized
and that the x and y coordinates are within the bounds of the image.
*/
