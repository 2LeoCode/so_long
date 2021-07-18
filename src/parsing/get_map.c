#include <so_long.h>

static int	check_tile(t_map *map, int offset, int i, int j)
{
	t_vec2	*vec_ptr;

	if (map->data[offset + j] == 'P')
	{
		if (map->player_pos.x != -1)
			return (-1);
		map->player_pos = (t_vec2){j, i};
	}
	else if (map->data[offset + j] == 'E')
	{
		if (map->exit_pos.x != -1)
			return (-1);
		map->exit_pos = (t_vec2){j, i};
	}
	else if (map->data[offset + j] == 'C')
	{
		vec_ptr = make_vec2(j, i);
		if (!vec_ptr || lst_push_back(map->collect_pos, vec_ptr, free))
			return (-1);
	}
	else if (map->data[offset + j] == '1'
		&& get_wall_direction(map, offset, i, j))
		return (-1);
	return (0);
}

static int	get_map_infos(t_map *map)
{
	int			i;
	int			j;
	int			offset;

	map->player_pos = (t_vec2){-1, -1};
	map->player_direction = top;
	map->exit_pos = (t_vec2){-1, -1};
	if (lst_init(&map->collect_pos) || lst_init(&map->walls))
	{
		lst_destroy(map->collect_pos);
		return (-1);
	}
	gb_push(map->collect_pos, lst_destroy);
	gb_push(map->walls, lst_destroy);
	i = -1;
	while (++i < map->size.y)
	{
		offset = i * map->size.x;
		j = -1;
		while (++j < map->size.x)
			if (check_tile(map, offset, i, j))
				return (-1);
	}
	return (0);
}

static bool	check_walls_and_get_size(t_list *file_content, t_vec2 *map_size)
{
	t_list	*it;
	size_t	line_len;

	gb_push(file_content, lst_destroy);
	it = file_content->next;
	while (it != file_content)
	{
		line_len = ft_strlen((char *)it->data);
		if (map_size->x == -1)
		{
			if (!is_horizontal_wall((char *)it->data, line_len))
				return (false);
			map_size->x = (int)line_len;
		}
		else if ((int)ft_strlen((char *)it->data) != map_size->x
			|| (it->next != file_content
				&& !is_vertical_wall((char *)it->data, line_len))
			|| (it->next == file_content
				&& !is_horizontal_wall((char *)it->data, line_len)))
			return (false);
		map_size->y++;
		it = it->next;
	}
	return (true);
}

static int	setup_map(t_map *map, t_list *file_content, t_vec2 map_size)
{
	const t_list	*it = file_content->next;
	unsigned int	i;

	map->total_size = map_size.x * map_size.y;
	map->size.x = map_size.x;
	map->size.y = map_size.y;
	i = 0;
	while (it != file_content)
	{
		ft_memcpy(map->data + i * map_size.x, it->data, map_size.x);
		it = it->next;
		i++;
	}
	gb_pop();
	if (gb_push(map, free))
		return (-1);
	return (0);
}

int	get_map(t_map **map_addr, const char *path)
{
	t_list			*file_content;
	t_vec2			map_size;

	map_size.x = -1;
	map_size.y = 0;
	if (!check_file(path))
		return (-1);
	file_content = get_file_content(path);
	if (!file_content || !check_walls_and_get_size(file_content, &map_size))
		return (-1);
	*map_addr
		= malloc(sizeof(t_map) + sizeof(char) * (map_size.x * map_size.y));
	if (!*map_addr || setup_map(*map_addr, file_content, map_size)
		|| get_map_infos(*map_addr))
		return (-1);
	return (0);
}
