/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:14:14 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/26 17:24:13 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	renderplayer(t_mlx mlx, t_render r)
{
	int	i;

	i = 0;
	if (mlx.key == S)
		mlx_put_image_to_window(mlx.con, mlx.win, mlx.down, r.x + 9, r.y);
	else if (mlx.key == W)
		mlx_put_image_to_window(mlx.con, mlx.win, mlx.up, r.x + 9, r.y);
	else if (mlx.key == A)
		mlx_put_image_to_window(mlx.con, mlx.win, mlx.left, r.x + 14, r.y);
	else if (mlx.key == D)
		mlx_put_image_to_window(mlx.con, mlx.win, mlx.right, r.x + 14, r.y);
}

void	renderbackground(t_mlx mlx)
{
	t_render	r;

	r.i = 0;
	r.y = 0;
	while (r.i < mlx.height)
	{
		r.j = 0;
		r.x = 0;
		while (r.j < mlx.width)
		{
			if (mlx.map[r.i][r.j] == '1')
				mlx_put_image_to_window(mlx.con, mlx.win, mlx.wall, r.x, r.y);
			else
				mlx_put_image_to_window(mlx.con, mlx.win, mlx.walk, r.x, r.y);
			r.x += 70;
			r.j++;
		}
		r.i++;
		r.y += 70;
	}
}

void	renderexit(t_mlx mlx, t_render r)
{
	if (ft_doublchr(mlx.map, 'C', &mlx))
		mlx_put_image_to_window(mlx.con, mlx.win, mlx.exitc, r.x, r.y);
	else
		mlx_put_image_to_window(mlx.con, mlx.win, mlx.exito, r.x, r.y);
}

void	renderassets(t_mlx *mlx, int *f, int prev[MAPSIZE])
{
	t_render	r;

	r.i = 0;
	r.y = 0;
	while (r.i < mlx->height)
	{
		r.j = 0;
		r.x = 0;
		while (r.j < mlx->width)
		{
			if (mlx->map[r.i][r.j] == 'E')
				renderexit(*mlx, r);
			else if (mlx->map[r.i][r.j] == 'X')
				renderenemyanim(mlx, r, f, &prev[r.i * r.j]);
			else if (mlx->map[r.i][r.j] == 'P')
				renderplayeranim(mlx, r, f);
			else if (mlx->map[r.i][r.j] == 'C')
				IMAG(mlx->con, mlx->win, mlx->coll, r.x, r.y + 14);
			r.x += 70;
			r.j++;
		}
		r.i++;
		r.y += 70;
	}
}

int	rendergame(t_mlx *mlx)
{
	static int	f;
	char		*tmp;
	static int	prev[MAPSIZE];

	if (f % 50 == 0 && f)
		changeposition(mlx);
	renderbackground(*mlx);
	renderassets(mlx, &f, prev);
	tmp = ft_stringjoin("Number of movement : ", ft_itoa(mlx->nb));
	mlx_string_put(mlx->con, mlx->win, 20, 20, 0xFFFFFF, tmp);
	free(tmp);
	f++;
	return (0);
}
