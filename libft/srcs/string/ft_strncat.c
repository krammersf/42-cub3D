/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:44:10 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/24 20:53:43 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: concatenate strings (s2 into s1, size-bounded)
**
** DESCRIPTION:
** 		The strcat() and strncat() functions append a copy of the null-
**	terminated string s2 to the end of the null-terminated string s1, then
**	add a terminating `\0'.  The string s1 must have sufficient space to hold
**	the result.
** 		The strncat() function appends not more than n characters from s2, and
**	then adds a terminating `\0'.
*/

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && j < n)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
