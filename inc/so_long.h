#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>

# define ENDIAN_LITTLE 0
# define ENDIAN_BIG 1
# define TILE_SIZE 32

void	kek(void);

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_img
{
	void	*img_ptr;
	int 	*data;
	int		bpp;
	int		size_line;
	int		endian;
	t_vec2	size;
	int		total_size;
}	t_img;

typedef struct s_mlx
{
	void	*key;
	void	*win;
	t_img	main_img;
}	t_mlx;

typedef struct s_map
{
	t_vec2	size;
	int		total_size;
	char	data[];
}	t_map;

/*
**	parsing
*/
t_map	*get_map(char *path);

/*
**	rendering
*/
void	render_map(t_map *map, t_img *img);

/*
**	utils
*/
t_img	init_image(void *mlx_key, int x, int y);
int		make_color(int r, int g, int b);

/*
**	cleaning
*/
void	clear_mlx(t_mlx *mlx);

#endif
