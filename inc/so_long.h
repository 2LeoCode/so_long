#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line.h"
# include "garbage.h"
# include "libft.h"
# include "list.h"
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>

# define ENDIAN_LITTLE 0
# define ENDIAN_BIG 1
# define TILE_SIZE 32

# define _KEY_LEFT 123
# define _KEY_RIGHT 124
# define _KEY_DOWN 125
# define _KEY_UP 126
# define _KEY_LEFT2 0
# define _KEY_RIGHT2 2
# define _KEY_DOWN2 1
# define _KEY_UP2 13
# define _KEY_ESC 53

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
	t_img	*main_img;
}	t_mlx;

typedef struct s_map
{
	t_vec2	size;
	t_vec2	player_pos;
	t_vec2	exit_pos;
	t_list	*collect_pos;
	int		total_size;
	char	data[];
}	t_map;

/*
**	wrapper structs
*/

typedef struct s_window_wrapper
{
	t_vec2	size;
	char	*title;
}	t_winwrap;

/*
**	parsing
*/
int		get_map(t_map **map_addr, const char *path);

/*
**	rendering
*/
void	init_renderer(t_img *img);
void	render_map(t_map *map);

/*
**	utils
*/
void	*init_image(void *data);
int		make_color(int r, int g, int b);

/*
**	cleaning
*/
void	clear_mlx(t_mlx *mlx);

/*
**	hooks
*/
int		key_hook(int keycode, void *param);

/*
**	image loader
*/
void	load_main_img_to_window(void *key, void *win, t_img *main_img);
void	put_main_img_to_window(void);

/*
**	wrappers
*/

void	*mlx_new_window_wrapper(void *data);
void	*mlx_new_image_wrapper(void *data);
void	mlx_destroy_window_wrapper(void *data);
void	mlx_destroy_image_wrapper(void *data);
void	exit_wrapper(int ret);

void	init_wrappers(void *key);
int		vec2_cmp(const void *a, const void *b);
t_vec2	*make_vec2(int x, int y);
#endif
