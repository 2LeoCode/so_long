#include <so_long.h>

static int	process_tile(t_vec2 new_pos, int new_index, t_map *map)
{
	if (new_pos.x == map->size.x || new_pos.x < 0
		|| new_pos.y == map->size.y || new_pos.y < 0
		|| map->data[new_index] == '1'
		|| (map->data[new_index] == 'E' && *map->collect_pos->size))
		return (0);
	if (map->data[new_index] == 'E')
		return (2);
	if (map->data[new_index] == 'C')
		lst_pop_if(map->collect_pos, (t_vec2 []){{new_pos.x, new_pos.y}},
			vec2_cmp);
	return (-1);
}

int	update_map(int keycode, t_map *map)
{
	const int	new_pos_x = map->player_pos.x
		- (keycode == _KEY_LEFT || keycode == _KEY_A)
		+ (keycode == _KEY_RIGHT || keycode == _KEY_D);
	const int	new_pos_y = map->player_pos.y
		- (keycode == _KEY_UP || keycode == _KEY_W)
		+ (keycode == _KEY_DOWN || keycode == _KEY_S);
	const int	new_pos_index = new_pos_y * map->size.x + new_pos_x;
	const int	old_pos_index = map->player_pos.y * map->size.x
		+ map->player_pos.x;
	const int	ret = process_tile((t_vec2){new_pos_x, new_pos_y},
		new_pos_index, map);

	map->player_direction = bot * (keycode == _KEY_DOWN || keycode == _KEY_S)
		+ right * (keycode == _KEY_RIGHT || keycode == _KEY_D)
		+ left * (keycode == _KEY_LEFT || keycode == _KEY_A);
	if (ret >= 0)
		return (ret);
	map->data[new_pos_index] = 'P';
	map->data[old_pos_index] = '0';
	map->player_pos.x = new_pos_x;
	map->player_pos.y = new_pos_y;
	return (1);
}

bool	is_valid_key(int keycode)
{
	return (keycode == _KEY_LEFT || keycode == _KEY_A || keycode == _KEY_RIGHT
		|| keycode == _KEY_D || keycode == _KEY_UP || keycode == _KEY_W
		|| keycode == _KEY_DOWN || keycode == _KEY_S);
}

int	key_hook(int keycode, void *param)
{
	static int		mv_cnt = 0;
	int				status;
	const t_vec2	prev_pos = {((t_map *)param)->player_pos.x,
		((t_map *)param)->player_pos.y};

	if (keycode == _KEY_ESC)
		exit_wrapper(EXIT_SUCCESS);
	status = 0;
	if (is_valid_key(keycode))
		status = update_map(keycode, (t_map *)param);
	mv_cnt += !!vec2_cmp(&prev_pos, &((t_map *)param)->player_pos);
	ft_putchar('\r');
	ft_putnbr(mv_cnt);
	if (status == 2)
	{
		mv_cnt = 0;
		ft_putchar('\n');
		exit_wrapper(EXIT_SUCCESS);
	}
	render_map((t_map *)param);
	put_main_img_to_window();
	return (0);
}
