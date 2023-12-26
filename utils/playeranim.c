/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playeranim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:22:12 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/26 17:19:40 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	rightanime(t_mlx *mlx, t_render r, int *f)
{
	static int	i;
	static int	next;

	if (!check(mlx->map[r.i][r.j - 1]))
	{
		r.x -= 70;
		if (*f % 1 == 0 && !next)
		{
			i += 7;
			IMAG(mlx->con, mlx->win, mlx->right1, (r.x + 14) + i, r.y);
			next = 1;
		}
		else if (*f % 1 == 0 && next)
		{
			i += 7;
			IMAG(mlx->con, mlx->win, mlx->right, (r.x + 14) + i, r.y);
			next = 0;
		}
		if (i >= 70)
		{
			mlx->press = 0;
			i = 0;
		}
	}
}

void	leftanime(t_mlx *mlx, t_render r, int *f)
{
	static int	i;
	static int	next;

	if (!check(mlx->map[r.i][r.j + 1]))
	{
		r.x += 70;
		if (*f % 1 == 0 && !next)
		{
			i -= 7;
			IMAG(mlx->con, mlx->win, mlx->left1, (r.x + 14) + i, r.y);
			next = 1;
		}
		else if (*f % 1 == 0 && next)
		{
			i -= 7;
			IMAG(mlx->con, mlx->win, mlx->left, (r.x + 14) + i, r.y);
			next = 0;
		}
		if (i <= -70)
		{
			mlx->press = 0;
			i = 0;
		}
	}
}

void	upanime(t_mlx *mlx, t_render r, int *f)
{
	static int	i;
	static int	next;

	if (!check(mlx->map[r.i + 1][r.j]))
	{
		r.y += 70;
		if (*f % 1 == 0 && !next)
		{
			i -= 7;
			IMAG(mlx->con, mlx->win, mlx->up1, r.x + 9, r.y + i);
			next = 1;
		}
		else if (*f % 1 == 0 && next)
		{
			i -= 7;
			IMAG(mlx->con, mlx->win, mlx->up, r.x + 9, r.y + i);
			next = 0;
		}
		if (i <= -70)
		{
			mlx->press = 0;
			i = 0;
		}
	}
}

void	downanime(t_mlx *mlx, t_render r, int *f)
{
	static int	i;
	static int	next;

	if (!check(mlx->map[r.i - 1][r.j]))
	{
		r.y -= 70;
		if (*f % 1 == 0 && !next)
		{
			i += 7;
			IMAG(mlx->con, mlx->win, mlx->down1, r.x + 9, r.y + i);
			next = 1;
		}
		else if (*f % 1 == 0 && next)
		{
			i += 7;
			IMAG(mlx->con, mlx->win, mlx->down, r.x + 9, r.y + i);
			next = 0;
		}
		if (i >= 70)
		{
			mlx->press = 0;
			i = 0;
		}
	}
}

void	renderplayeranim(t_mlx *mlx, t_render r, int *f)
{
	if (mlx->press)
	{
		if (mlx->key == D)
			rightanime(mlx, r, f);
		else if (mlx->key == A)
			leftanime(mlx, r, f);
		if (mlx->key == W)
			upanime(mlx, r, f);
		if (mlx->key == S)
			downanime(mlx, r, f);
	}
	else if (!mlx->press)
		renderplayer(*mlx, r);
}
