/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:32:32 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/26 17:34:10 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"

# ifndef MAPSIZE
#  define MAPSIZE 100000

# endif

# ifndef MAPDIMEN
#  define MAPDIMEN 500

# endif

# define BUFFER_SIZE 10
# define W 13
# define D 2
# define A 0
# define S 1
# define ESC 53
# define WINDOW mlx_new_window
# define IMAG mlx_put_image_to_window

typedef struct s_render
{
	int	i;
	int	j;
	int	x;
	int	y;
}	t_render;

typedef struct s_path
{
	int		**visited_exit;
	int		**visited_collec;
	char	**area;
}	t_path;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_cord
{
	int	e;
	int	p;
	int	c;
}	t_cordcheck;

typedef struct s_mlx
{
	char	**map;
	char	**mapsave;
	void	*con;
	void	*win;
	void	*wall;
	void	*walk;
	void	*exito;
	void	*exitc;
	void	*coll;
	void	*right;
	void	*right1;
	void	*left;
	void	*left1;
	void	*sk;
	void	*sk1;
	void	*sk2;
	void	*sk3;
	int		previous;
	int		fd;
	void	*up;
	void	*up1;
	void	*down;
	void	*down1;
	int		key;
	int		press;
	int		width;
	int		height;
	int		nb;
	t_point	player;
}	t_mlx;

int		ft_doublchr(char **zone, int c, t_mlx *mlx);
char	**make_area(t_mlx *mlx, char **map);
void	checkend(int key, t_mlx *mlx);
int		mapchecker(t_mlx *mlx, t_point *player);
void	make_tab(int **visited, t_mlx *mlx);
char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buf);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlchr(char *buf);
size_t	ft_strlen(char *str);
size_t	ft_strchr(char	*buf, char c);
void	free_string(void **arr, int size);
char	**get_map(int fd);
int		move(int keypress, t_mlx *mlx);
void	renderplayeranim(t_mlx *mlx, t_render r, int *f);
void	renderbackground(t_mlx mlx);
int		rendergame(t_mlx *mlx);
int		check(int c);
void	flood_fill_exit(char **area, t_mlx *mlx, t_point b, int **visited);
void	flood_fill_collect(char **area, t_mlx *mlx, t_point b, int **visited);
void	renderenemyanim(t_mlx *mlx, t_render r, int *f, int *prev);
char	**ft_split(char const *s, char c);
void	changeposition(t_mlx *mlx);
void	renderplayer(t_mlx mlx, t_render r);
void	renderenemy(t_mlx *mlx, t_render r, int *prev);
void	enemymoveleft(t_mlx *mlx, t_point r, int was[MAPDIMEN][MAPDIMEN]);
void	enemymoveright(t_mlx *mlx, t_point r, int was[MAPDIMEN][MAPDIMEN]);
char	*ft_itoa(int n);
char	*ft_stringjoin(char *line, char *buf);
void	restart(t_mlx *mlx);
int		ft_end(t_mlx *mlx);
char	**ft_realloc(char **map, int size, int i);

#endif
