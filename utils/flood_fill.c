/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:48:10 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/22 22:42:51 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill_collect(char **area, t_mlx *mlx, t_point b, int **visited)
{
	if (b.y >= mlx->height || b.y < 0 || b.x >= mlx->width || b.x < 0)
		return ;
	if (visited[b.y][b.x] == 1)
		return ;
	if (area[b.y][b.x] == '1')
		return ;
	if (area[b.y][b.x] == 'C')
		area[b.y][b.x] = '0';
	visited[b.y][b.x] = 1;
	flood_fill_collect(area, mlx, (t_point){b.x + 1, b.y}, visited);
	flood_fill_collect(area, mlx, (t_point){b.x - 1, b.y}, visited);
	flood_fill_collect(area, mlx, (t_point){b.x, b.y + 1}, visited);
	flood_fill_collect(area, mlx, (t_point){b.x, b.y - 1}, visited);
}

void	flood_fill_exit(char **area, t_mlx *mlx, t_point b, int **visited)
{
	if (b.y >= mlx->height || b.y < 0 || b.x >= mlx->width || b.x < 0)
		return ;
	if (visited[b.y][b.x] == 1)
		return ;
	if (area[b.y][b.x] == '1')
		return ;
	if (area[b.y][b.x] == 'E')
		area[b.y][b.x] = '1';
	visited[b.y][b.x] = 1;
	flood_fill_exit(area, mlx, (t_point){b.x + 1, b.y}, visited);
	flood_fill_exit(area, mlx, (t_point){b.x - 1, b.y}, visited);
	flood_fill_exit(area, mlx, (t_point){b.x, b.y + 1}, visited);
	flood_fill_exit(area, mlx, (t_point){b.x, b.y - 1}, visited);
}
