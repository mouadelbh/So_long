/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:19:19 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/26 17:00:59 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_up(t_mlx *mlx, int c)
{
	if (c == 'X')
		restart(mlx);
	else if (c != 'E' && c != '1')
	{
		mlx->map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.y--;
		mlx->map[mlx->player.y][mlx->player.x] = 'P';
		mlx->press = 1;
	}
}

void	ft_move_down(t_mlx *mlx, int c)
{
	if (c == 'X')
		restart(mlx);
	else if (c != 'E' && c != '1')
	{
		mlx->map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.y++;
		mlx->map[mlx->player.y][mlx->player.x] = 'P';
		mlx->press = 1;
	}
}

void	ft_move_right(t_mlx *mlx, int c)
{
	if (c == 'X')
		restart(mlx);
	else if (c != 'E' && c != '1')
	{
		mlx->map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.x++;
		mlx->map[mlx->player.y][mlx->player.x] = 'P';
		mlx->press = 1;
	}
}

void	ft_move_left(t_mlx *mlx, int c)
{
	if (c == 'X')
		restart(mlx);
	else if (c != 'E' && c != '1')
	{
		mlx->map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.x--;
		mlx->map[mlx->player.y][mlx->player.x] = 'P';
		mlx->press = 1;
	}
}

int	move(int keypress, t_mlx *mlx)
{
	if (keypress == ESC)
		ft_end(mlx);
	checkend(keypress, mlx);
	if (mlx->press == 0)
	{
		if (keypress == W)
			ft_move_up(mlx, mlx->map[mlx->player.y - 1][mlx->player.x]);
		else if (keypress == D)
			ft_move_right(mlx, mlx->map[mlx->player.y][mlx->player.x + 1]);
		else if (keypress == A)
			ft_move_left(mlx, mlx->map[mlx->player.y][mlx->player.x - 1]);
		else if (keypress == S)
			ft_move_down(mlx, mlx->map[mlx->player.y + 1][mlx->player.x]);
		if (mlx->press == 1)
		{
			mlx->nb++;
			mlx->key = keypress;
		}
	}
	rendergame(mlx);
	return (0);
}
