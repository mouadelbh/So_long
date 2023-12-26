/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemymove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:31:10 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/26 16:56:22 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemymoveright(t_mlx *mlx, t_point r, int was[MAPDIMEN][MAPDIMEN])
{
	if (mlx->map[r.y][r.x + 1] == 'P')
	{
		restart(mlx);
		return ;
	}
	if (check(mlx->map[r.y][r.x + 1]))
		was[r.y][r.x] = 1;
	else
	{
		mlx->map[r.y][r.x] = '0';
		mlx->map[r.y][r.x + 1] = 'X';
		was[r.y][r.x] = 1;
	}
}

void	enemymoveleft(t_mlx *mlx, t_point r, int was[MAPDIMEN][MAPDIMEN])
{
	if (mlx->map[r.y][r.x - 1] == 'P')
	{
		restart(mlx);
		return ;
	}
	if (check(mlx->map[r.y][r.x - 1]))
		was[r.y][r.x] = 0;
	else
	{
		mlx->map[r.y][r.x] = '0';
		mlx->map[r.y][r.x - 1] = 'X';
		was[r.y][r.x] = 0;
	}
}
