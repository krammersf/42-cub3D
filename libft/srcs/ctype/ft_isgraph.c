/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:44:12 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/24 20:48:00 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** SYNOPSIS: printing character test (space character exclusive)
**
** DESCRIPTION:
** 		 The isgraph() function tests for any printing character except space
**	(` ') and other locale-specific, space-like characters.
*/

int	ft_isgraph(int c)
{
	if (c > 32 && c <= 126)
		return (1);
	return (0);
}
