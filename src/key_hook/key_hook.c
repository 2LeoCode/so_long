#include <so_long.h>

int	update_map(int keycode, t_map *map)
{
	const int	new_pos_x = map->player_pos.x
		- (keycode == _KEY_LEFT || keycode == _KEY_LEFT2)
		+ (keycode == _KEY_RIGHT || keycode == _KEY_RIGHT2);
	const int	new_pos_y = map->player_pos.y
		- (keycode == _KEY_UP || keycode == _KEY_UP2)
		+ (keycode == _KEY_DOWN || keycode == _KEY_DOWN2);
	const int	new_pos_index = new_pos_y * map->size.x + new_pos_x;
	const int	old_pos_index = map->player_pos.y * map->size.x
		+ map->player_pos.x;

	if (new_pos_x == map->size.x || new_pos_x < 0
	|| new_pos_y == map->size.y || new_pos_y < 0
	|| map->data[new_pos_index] == '1'
	|| (map->data[new_pos_index] == 'E' && *map->collect_pos->size))
		return (0);
	if (map->data[new_pos_index] == 'E')
		return (2);
	if (map->data[new_pos_index] == 'C')
		lst_pop_if(map->collect_pos, (t_vec2 []){{new_pos_x, new_pos_y}},
			vec2_cmp);
	map->player_direction = bot * (keycode == _KEY_DOWN || keycode == _KEY_DOWN2)
		+ right * (keycode == _KEY_RIGHT || keycode == _KEY_RIGHT2)
		+ left * (keycode == _KEY_LEFT || keycode == _KEY_LEFT2);
	map->data[new_pos_index] = 'P';
	map->data[old_pos_index] = '0';
	map->player_pos.x = new_pos_x;
	map->player_pos.y = new_pos_y;
	return (1);
}

void	print_map(t_map *map)
{
	for (int i = 0; i < map->size.y; i++) {
		write(1, map->data + i * map->size.x, map->size.x);
		write(1, "\n", 1);
	}
}

bool	is_valid_key(int keycode)
{
	return (keycode == _KEY_LEFT || keycode == _KEY_LEFT2 || keycode == _KEY_RIGHT
		|| keycode == _KEY_RIGHT2 || keycode == _KEY_UP || keycode == _KEY_UP2
		|| keycode == _KEY_DOWN || keycode == _KEY_DOWN2);
}

int	key_hook(int keycode, void *param)
{
	static int	mv_cnt = 0;
	int			status;

	if (keycode == _KEY_ESC)
		exit_wrapper(EXIT_SUCCESS);
	status = 0;
	if (is_valid_key(keycode))
		status = update_map(keycode, (t_map *)param);
	if (!status)
		return (1);
	mv_cnt++;
	ft_putnbr(mv_cnt);
	ft_putchar('\n');
	if (status == 2)
	{
		mv_cnt = 0;
		exit_wrapper(EXIT_SUCCESS);
	}
	render_map((t_map *)param);
	put_main_img_to_window();
	return (0);
}
