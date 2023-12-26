/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:39:34 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/26 17:19:07 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check(int c)
{
	if (c == '1' || c == 'E' || c == 'C' || c == 'X')
		return (1);
	else
		return (0);
}

char	*ft_stringjoin(char *line, char *buf)
{
	char	*join;

	if (!line && !buf)
		return (NULL);
	join = (char *)malloc(ft_strlen(line) + ft_strlen(buf) + 2);
	if (!join)
		return (NULL);
	join[0] = '\0';
	if (line)
		ft_strlcat(join, line, ft_strlen(line) + 1);
	if (buf)
		ft_strlcat(join, buf, ft_strlen(buf) + ft_strlen(line) + 1);
	free(buf);
	return (join);
}

char	**ft_realloc(char **map, int size, int i)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (free_string((void **)map, i), NULL);
	while (j < i)
	{
		tmp[j] = map[j];
		j++;
	}
	free(map);
	return (tmp);
}

char	**get_map(int fd)
{
	char	*line;
	int		size;
	int		i;
	char	**map;

	size = 5;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (i == size - 1)
		{
			size *= 2;
			map = ft_realloc(map, size, i);
		}
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}
