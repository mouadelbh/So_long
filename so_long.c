/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:15:15 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/26 16:48:28 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	restart(t_mlx *mlx)
{
	char	**tmp;

	tmp = make_area(mlx, mlx->mapsave);
	free_string((void **)mlx->map, mlx->height);
	mlx->map = tmp;
	mlx->nb = 0;
	close(mlx->fd);
	mlx_clear_window(mlx->con, mlx->win);
	mapchecker(mlx, &mlx->player);
}

int	checkfile(char *s)
{
	int		i;
	int		j;
	char	*e;

	i = ft_strlen(s);
	e = ".ber";
	while (--i)
	{
		if (s[i] == '.')
			break ;
	}
	j = 0;
	if (s[i] == '.')
	{
		while (e[j] == s[i + j] && s[i + j])
			j++;
		if (e[j] == '\0' && s[i + j] == '\0')
			return (1);
	}
	return (0);
}

void	checkend(int key, t_mlx *mlx)
{
	if (!ft_doublchr(mlx->map, 'C', mlx))
	{
		if (key == W && mlx->map[mlx->player.y - 1][mlx->player.x] == 'E')
			ft_end(mlx);
		if (key == D && mlx->map[mlx->player.y][mlx->player.x + 1] == 'E')
			ft_end(mlx);
		if (key == A && mlx->map[mlx->player.y][mlx->player.x - 1] == 'E')
			ft_end(mlx);
		if (key == S && mlx->map[mlx->player.y + 1][mlx->player.x] == 'E')
			ft_end(mlx);
	}
}

void	t_mlx_maker(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->press = 0;
	mlx->key = S;
	mlx->nb = 0;
	mlx->con = mlx_init();
	mlx->win = WINDOW(mlx->con, mlx->width * 70, mlx->height * 70, "So_long");
	mlx->wall = mlx_xpm_file_to_image(mlx->con, "assets/wall.xpm", &x, &y);
	mlx->walk = mlx_xpm_file_to_image(mlx->con, "assets/walk.xpm", &x, &y);
	mlx->exitc = mlx_xpm_file_to_image(mlx->con, "assets/exitc.xpm", &x, &y);
	mlx->exito = mlx_xpm_file_to_image(mlx->con, "assets/exito.xpm", &x, &y);
	mlx->coll = mlx_xpm_file_to_image(mlx->con, "assets/collect.xpm", &x, &y);
	mlx->right = mlx_xpm_file_to_image(mlx->con, "assets/right.xpm", &x, &y);
	mlx->right1 = mlx_xpm_file_to_image(mlx->con, "assets/right1.xpm", &x, &y);
	mlx->left = mlx_xpm_file_to_image(mlx->con, "assets/left.xpm", &x, &y);
	mlx->left1 = mlx_xpm_file_to_image(mlx->con, "assets/left1.xpm", &x, &y);
	mlx->up = mlx_xpm_file_to_image(mlx->con, "assets/up.xpm", &x, &y);
	mlx->sk = mlx_xpm_file_to_image(mlx->con, "assets/sk.xpm", &x, &y);
	mlx->sk1 = mlx_xpm_file_to_image(mlx->con, "assets/sk1.xpm", &x, &y);
	mlx->sk2 = mlx_xpm_file_to_image(mlx->con, "assets/sk2.xpm", &x, &y);
	mlx->sk3 = mlx_xpm_file_to_image(mlx->con, "assets/sk3.xpm", &x, &y);
	mlx->up1 = mlx_xpm_file_to_image(mlx->con, "assets/up1.xpm", &x, &y);
	mlx->down = mlx_xpm_file_to_image(mlx->con, "assets/down.xpm", &x, &y);
	mlx->down1 = mlx_xpm_file_to_image(mlx->con, "assets/down1.xpm", &x, &y);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac <= 1)
	{
		ft_printf("Error\nNo map selected\n");
		return (1);
	}
	if (!checkfile(av[1]))
		return (ft_printf("Error\nNot a .ber map\n"), 1);
	mlx.fd = open(av[1], 'r');
	if (mlx.fd < 0)
		exit(0);
	mlx.map = get_map(mlx.fd);
	if (mapchecker(&mlx, &mlx.player))
	{
		free_string((void **)mlx.map, mlx.height);
		return (1);
	}
	mlx.mapsave = make_area(&mlx, mlx.map);
	t_mlx_maker(&mlx);
	mlx_hook(mlx.win, 2, 0, move, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_end, &mlx);
	mlx_loop_hook(mlx.con, rendergame, &mlx);
	mlx_loop(mlx.con);
	return (0);
}
