/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:31:23 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/26 17:07:22 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mapsize(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
		i++;
	mlx->width = ft_strlen(mlx->map[0]);
	mlx->height = i;
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if ((i == 0 || i == mlx->height - 1) && mlx->map[i][j] != '1')
				return (ft_printf("Error\nMap must be surronded by walls\n"), 0);
			j++;
		}
		if (j != mlx->width || mlx->map[i][0] != '1' || \
		mlx->map[i][mlx->width - 1] != '1')
			return (ft_printf("Error\n"), \
			ft_printf("Map must be rectangular and surronded by walls\n"), 0);
		i++;
	}
	return (1);
}

int	countmap(t_mlx *mlx)
{
	char	*s;
	int		i;
	int		j;

	s = "01EXCP";
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (!ft_strchr(s, mlx->map[i][j]))
				return (ft_printf("Error\nUndefined char has been found\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

void	playersetup(int c, t_cordcheck *found, t_point *p, t_point s)
{
	if (c == 'P')
	{
		p->x = s.x;
		p->y = s.y;
		found->p += 1;
	}
	else if (c == 'E')
		found->e += 1;
	else if (c == 'C')
		found->c += 1;
}

int	playercord(t_mlx *mlx, t_point *player)
{
	t_cordcheck	found;
	t_point		save;
	int			i;
	int			j;

	i = 0;
	found.p = 0;
	found.e = 0;
	found.c = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			save.x = j;
			save.y = i;
			playersetup(mlx->map[i][j], &found, player, save);
			j++;
		}
		i++;
	}
	if (found.p != 1 || found.e != 1 || found.c < 1)
		return (ft_printf("Error\nCordinations are misconfigurated!!\n"), 0);
	return (1);
}

int	mapchecker(t_mlx *mlx, t_point *player)
{
	t_path	p;

	if (!mapsize(mlx) || !playercord(mlx, player) || !countmap(mlx))
		return (1);
	p.area = make_area(mlx, mlx->map);
	p.visited_exit = malloc(mlx->height * sizeof(int *));
	if (!p.visited_exit)
		return (free_string((void **)p.area, mlx->height), 1);
	p.visited_collec = malloc(mlx->height * sizeof(int *));
	if (!p.visited_collec)
		return (free_string((void **)p.area, mlx->height), \
		free_string((void **)p.visited_exit, mlx->height), 1);
	make_tab(p.visited_exit, mlx);
	make_tab(p.visited_collec, mlx);
	flood_fill_exit(p.area, mlx, *player, p.visited_exit);
	flood_fill_collect(p.area, mlx, *player, p.visited_collec);
	if (ft_doublchr(p.area, 'C', mlx) || ft_doublchr(p.area, 'E', mlx))
	{
		ft_printf("Error\ncollectibles or the exit are not reachable\n");
		return (1);
	}
	free_string((void **)p.area, mlx->height);
	free_string((void **)p.visited_collec, mlx->height);
	free_string((void **)p.visited_exit, mlx->height);
	return (0);
}
