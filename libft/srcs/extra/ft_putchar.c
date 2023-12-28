/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:15:55 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/24 20:48:49 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdio.h>
** SYNOPSIS: output a character to stdout
**
** DESCRIPTION:
** 		The putchar() function writes the character c (converted to an
**	``unsigned char'') to the output stream of stdout.
** 		[42 PDF] Outputs the character ’c’ to stdout.
*/

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
