/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:13:07 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/24 20:50:39 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: Find number of characters before a given character
**
** DESCRIPTION:
** 		The ft_strclen() function computes the length of the string s,
** 	but stops when there's the occurrence of the character c.
*/

#include "libft.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s && s[len] != c && s[len])
		len++;
	return (len);
}
