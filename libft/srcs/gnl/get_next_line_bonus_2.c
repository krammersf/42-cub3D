/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:22:58 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/24 20:40:49 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strlen_at(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	have_newline(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strncpy2(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin2(char *prev, char *curr)
{
	int		i;
	int		j;
	int		size;
	char	*merge;

	i = strlen_at(prev, '\0');
	j = strlen_at(curr, '\0');
	size = i + j + 1;
	if (!prev && !curr)
		return (NULL);
	merge = (char *)malloc(sizeof(char) * size);
	if (!merge)
		return (NULL);
	if (prev)
		ft_strncpy2(merge, prev, i);
	ft_strncpy2(merge + i, curr, j);
	free (prev);
	return (merge);
}
