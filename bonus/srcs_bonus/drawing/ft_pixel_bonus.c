/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:30:46 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/28 19:29:50 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

// function to get the color of a pixel in a texture	
int	ft_pixel_get(t_texture *txt, int x, int y)
{
	return (*(unsigned int *)((txt->addr + (y * txt->line_length) + \
		(x * txt->bits_per_pixel / 8))));
}

// function to draw a pixel on the screen and serch for transparent pixels
void	ft_pixel_put(t_mlx *mini, int x, int y, int color)
{
	char	*dest;

	if (color == (int)0x980088)
		return ;
	dest = mini->addr + (y * mini->line_length + x * \
			(mini->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}
