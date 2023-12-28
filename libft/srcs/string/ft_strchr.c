/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:47:49 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/24 20:53:21 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: locate character in string (first occurrence)
**
** DESCRIPTION:
** 		The strchr() function locates the first occurrence of c (converted to a
**	char) in the string pointed to by s.  The terminating null character is
**	considered to be part of the string; therefore if c is `\0', the func-
**	tions locate the terminating `\0'.
*/

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (s[i] == (unsigned char) c)
		return (s + i);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
			return (s + i);
		i++;
	}
	return (0);
}
