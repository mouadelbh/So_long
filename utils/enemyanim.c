/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemyanim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:26:54 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/26 16:59:28 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	changeposition(t_mlx *mlx)
{
	t_point		r;
	static int	was[MAPDIMEN][MAPDIMEN];

	r.y = 0;
	while (r.y < mlx->height)
	{
		r.x = 0;
		while (r.x < mlx->width)
		{
			if (mlx->map[r.y][r.x] == 'X')
			{
				if (r.x + 1 < mlx->width - 1 && !was[r.y][r.x])
				{
					enemymoveright(mlx, r, was);
					r.x++;
				}
				else if (r.x - 1 > 0 && was[r.y][r.x])
					enemymoveleft(mlx, r, was);
			}
			r.x++;
		}
		r.y++;
	}
}

void	renderenemy(t_mlx *mlx, t_render r, int *prev)
{
	if (!*prev)
		mlx_put_image_to_window(mlx->con, mlx->win, mlx->sk, r.x, r.y);
	if (*prev == 1)
		mlx_put_image_to_window(mlx->con, mlx->win, mlx->sk1, r.x, r.y);
	if (*prev == 2)
		mlx_put_image_to_window(mlx->con, mlx->win, mlx->sk2, r.x, r.y);
	if (*prev == 3)
		mlx_put_image_to_window(mlx->con, mlx->win, mlx->sk3, r.x, r.y);
}

void	setnextframe(int *prev, int next[MAPSIZE], t_render r, int c)
{
	*prev = c;
	next[r.i * r.j] = c;
}

void	renderenemyanim(t_mlx *mlx, t_render r, int *f, int *prev)
{
	static int	next[MAPSIZE];

	if (*f % 6 == 0 && *f)
	{
		if (!next[r.i * r.j])
			setnextframe(prev, next, r, 1);
		else if (next[r.i * r.j] == 1)
			setnextframe(prev, next, r, 2);
		else if (next[r.i * r.j] == 2)
			setnextframe(prev, next, r, 3);
		else if (next[r.i * r.j] == 3)
			setnextframe(prev, next, r, 0);
	}
	renderenemy(mlx, r, prev);
}
