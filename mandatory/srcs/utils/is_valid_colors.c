/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:11:47 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/27 15:20:09 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_valid_colors(t_rgb *colors)
{
	if (colors->red < 0 || colors->green < 0 || colors->blue < 0)
		return (false);
	if (colors->red > 255 || colors->green > 255 || colors->blue > 255)
		return (false);
	return (true);
}
