/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:19:01 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/26 17:18:58 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_string(void **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_end(t_mlx *mlx)
{
	free_string((void **)mlx->map, mlx->height);
	free_string((void **)mlx->mapsave, mlx->height);
	close(mlx->fd);
	mlx_destroy_window(mlx->con, mlx->win);
	exit(0);
	return (1);
}

int	ft_doublchr(char **zone, int c, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			if (zone[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**make_area(t_mlx *mlx, char **map)
{
	char	**new;
	int		i;
	int		j;

	new = malloc(sizeof(char *) * (mlx->height + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < mlx->height)
	{
		new[i] = malloc(mlx->width + 1);
		if (!new[i])
			return (free_string((void **)new, i), NULL);
		j = 0;
		while (j < mlx->width)
		{
			new[i][j] = map[i][j];
			j++;
		}
		new[i][mlx->width] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	make_tab(int **visited, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->height)
	{
		visited[i] = malloc(mlx->width * sizeof(int));
		if (!visited[i])
		{
			free_string((void **)visited, i);
			return ;
		}
		j = 0;
		while (j < mlx->width)
			visited[i][j++] = 0;
		i++;
	}
}
