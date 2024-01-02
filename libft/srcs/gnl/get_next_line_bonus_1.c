/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:23:04 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/02 12:01:34 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_keep(char *buffer)
{
	int		i;
	int		j;
	int		size;
	char	*keep;

	i = strlen_at(buffer, '\0');
	j = strlen_at(buffer, '\n');
	size = i - j + 1;
	if (!buffer[j])
	{
		free (buffer);
		return (NULL);
	}
	keep = (char *)malloc(sizeof(char) * size);
	if (!keep)
		return (NULL);
	j++;
	ft_strncpy2(keep, buffer + j, size);
	free (buffer);
	return (keep);
}

char	*get_line(char *buffer)
{
	int		j;
	char	*line;

	j = strlen_at(buffer, '\n');
	if (buffer[j] == '\n')
		j++;
	line = (char *)malloc(sizeof(char) * (j + 1));
	if (!line)
		return (NULL);
	ft_strncpy2(line, buffer, j);
	return (line);
}

static void	free_keep(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		curr[BUFFER_SIZE + 1];
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	curr[0] = '\0';
	bytes = 1;
	while (!have_newline(curr) && bytes != 0)
	{
		bytes = read(fd, curr, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		curr[bytes] = '\0';
		buffer = ft_strjoin2(buffer, curr);
	}
	line = get_line(buffer);
	free_keep(&buffer);
	if (!line[0])
	{
		free (line);
		return (NULL);
	}
	return (line);
}
