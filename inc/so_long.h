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
# include <X11/X.h>

# define ENDIAN_LITTLE 0
# define ENDIAN_BIG 1
# define TILE_SIZE 32
# define TEXTURE_CNT 5
# define WALL_DIR_CNT 16
# define PLAYER_DIR_CNT 4

# ifdef __linux__
#  define _KEY_A 97
#  define _KEY_D 100
#  define _KEY_S 115
#  define _KEY_W 119
#  define _KEY_LEFT 65361
#  define _KEY_RIGHT 65363
#  define _KEY_DOWN 65364
#  define _KEY_UP 65362
#  define _KEY_ESC 65307
# else
#  define _KEY_A 123
#  define _KEY_D 124
#  define _KEY_S 125
#  define _KEY_W 126
#  define _KEY_LEFT 0
#  define _KEY_RIGHT 2
#  define _KEY_DOWN 1
#  define _KEY_UP 13
#  define _KEY_ESC 53
# endif

void	kek(void);

enum e_texture
{
	character,
	end_level,
	gem,
	wall,
	water
};

typedef enum e_player_direction
{
	top,
	bot,
	right,
	left
}	t_direction;

typedef enum e_wall_direction
{
	none,
	north,
	east,
	south,
	west,
	east_south,
	north_east,
	south_west,
	north_west,
	north_south,
	east_west,
	north_east_west,
	north_east_south,
	east_south_west,
	north_south_west,
	all
}	t_walldir;

typedef t_walldir	t_walld;

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
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

typedef struct s_wall
{
	int			x;
	int			y;
	t_walldir	orientation;
}	t_wall;

typedef struct s_map
{
	t_vec2		size;
	t_vec2		player_pos;
	t_vec2		exit_pos;
	t_list		*collect_pos;
	t_list		*walls;
	t_direction	player_direction;
	t_img		*tileset[TEXTURE_CNT];
	int			total_size;
	char		data[];
}	t_map;

/*
**	wrapper structs
*/

typedef struct s_window_wrapper
{
	t_vec2	size;
	char	*title;
}	t_winwrap;

typedef struct s_xpm_wrapper
{
	char	*filename;
	int		*w_ptr;
	int		*h_ptr;
}	t_xpmwrap;

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
void	*init_image_from_xpm(void *param);
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
**	image loading
*/
void	load_main_img_to_window(void *key, void *win, t_img *main_img);
void	put_main_img_to_window(void);

/*
**	wrappers
*/

void	*mlx_new_window_wrapper(void *data);
void	*mlx_new_image_wrapper(void *data);
void	*mlx_xpm_file_to_image_wrapper(void *data);
void	mlx_destroy_window_wrapper(void *data);
void	mlx_destroy_image_wrapper(void *data);
void	exit_wrapper(int ret);

void	init_wrappers(void *key);
int		vec2_cmp(const void *a, const void *b);
t_vec2	*make_vec2(int x, int y);
int		load_textures(t_map *map);
t_wall	*make_wall(int x, int y, t_walldir orientation);
void	put_tile(t_img *img, t_vec2 dstpos, int src_x, t_img *texture);
bool	is_vertical_wall(const char *s, size_t len);
bool	is_horizontal_wall(const char *s, size_t len);
bool	check_file(const char *path);
t_list	*get_file_content(const char *path);
t_walld	process_north(t_map *map, int offset, int i, int j);
t_walld	process_east(t_map *map, int offset, int i, int j);
t_walld	process_east(t_map *map, int offset, int i, int j);
int		get_wall_direction(t_map *map, int offset, int i, int j);

#endif
