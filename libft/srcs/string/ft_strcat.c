/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:41:44 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/24 20:53:17 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: concatenate strings (s2 into s1)
**
** DESCRIPTION:
** 		The strcat() and strncat() functions append a copy of the null-
**	terminated string s2 to the end of the null-terminated string s1, then
**	add a terminating `\0'.  The string s1 must have sufficient space to hold
**	the result.
*/

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	int	i;

	i = ft_strlen(s1);
	while (*s2 != '\0')
	{
		s1[i] = *s2;
		i++;
		s2++;
	}
	s1[i] = '\0';
	return (s1);
}
