#include <so_long.h>

static bool	is_vertical_wall(const char *s, size_t len)
{
	return (*s == '1' && s[len - 1] == '1');
}

static bool	is_horizontal_wall(const char *s, size_t len)
{
	while (--len && s[len] == '1')
		continue ;
	return (!len);
}

static bool	check_file(const char *path)
{
	const char	*ptr;
	int			fd;

	ptr = path + ft_strlen(path) - 4;
	if (ptr < path || ft_strcmp(ptr, ".ber"))
		return (false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

t_list	*get_file_content(const char *path)
{
	const int	fd = open(path, O_RDONLY);
	t_list		*lines;
	char		*cur_line;
	int			i;

	if (fd == -1 || lst_init(&lines))
		return (NULL);
	i = 1;
	while (i)
	{
		i = get_next_line(fd, &cur_line);
		if (!ft_strisspace(cur_line))
		{
			if (lst_push_back(lines, cur_line, free))
			{
				close(fd);
				return (NULL);
			}
		}
		else
			free(cur_line);
	}
	close(fd);
	return (lines);
}

int		get_map_infos(t_map *map)
{
	int			i;
	int			offset;
	int			prev_offset;
	int			next_offset;
	int			j;
	t_wall		*wall_ptr;
	t_vec2		*vec_ptr;
	t_walldir	wall_direction;

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
		prev_offset = (i - 1) * map->size.x;
		next_offset = (i + 1) * map->size.x;
		j = -1;
		while (++j < map->size.x)
		{
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
			else if (map->data[offset + j] == '1')
			{
				wall_direction = none;
				if (!i || map->data[prev_offset + j] == '1')
				{
					if (j == (map->size.x - 1) || map->data[offset + j + 1] == '1')
					{
						if (i == (map->size.y - 1) || map->data[next_offset + j] == '1')
						{
							if (!j || map->data[offset + j - 1] == '1')
								wall_direction = all;
							else
								wall_direction = north_east_south;
						}
						else if (!j || map->data[offset + j - 1] == '1')
							wall_direction = north_east_west;
						else
							wall_direction = north_east;
					}
					else if (i == (map->size.y - 1) || map->data[next_offset + j] == '1')
					{
						if (!j || map->data[offset + j - 1] == '1')
							wall_direction = north_south_west;
						else
							wall_direction = north_south;
					}
					else if (!j || map->data[offset + j - 1] == '1')
						wall_direction = north_west;
					else
						wall_direction = north;
				}
				else if (j == map->size.x - 1 || map->data[offset + j + 1] == '1')
				{
					if (i == map->size.y - 1 || map->data[next_offset + j] == '1')
					{
						if (!j || map->data[offset + j - 1] == '1')
							wall_direction = east_south_west;
						else
							wall_direction = east_south;
					}
					else if (!j || map->data[offset + j - 1] == '1')
						wall_direction = east_west;
					else
						wall_direction = east;
				}
				else if (i == map->size.y - 1 || map->data[next_offset + j] == '1')
				{
					if (!j || map->data[offset + j - 1] == '1')
						wall_direction = south_west;
					else
						wall_direction = south;
				}
				else if (!j || map->data[offset + j - 1] == '1')
					wall_direction = west;
				wall_ptr = make_wall(j, i, wall_direction);
				if (!wall_ptr || lst_push_back(map->walls, wall_ptr, free))
					return (-1);
			}
		}
	}
	return (0);
}

int	get_map(t_map **map_addr, const char *path)
{
	t_list			*file_content;
	t_list			*it;
	size_t			line_len;
	t_vec2			map_size;
	unsigned int	i;

	map_size.x = -1;
	map_size.y = 0;
	if (!check_file(path))
		return (-1);
	file_content = get_file_content(path);
	if (!file_content)
		return (-1);
	it = file_content->next;
	while (it != file_content)
	{
		line_len = ft_strlen((char *)it->data);
		if (map_size.x == -1)
		{
			if (!is_horizontal_wall((char *)it->data, line_len))
				return (-1);
			map_size.x = (int)line_len;
		}
		else if ((int)ft_strlen((char *)it->data) != map_size.x
			|| (it->next != file_content
				&& !is_vertical_wall((char *)it->data, line_len))
			|| (it->next == file_content
				&& !is_horizontal_wall((char *)it->data, line_len)))
			return (-1);
		map_size.y++;
		it = it->next;
	}
	*map_addr = malloc(sizeof(t_map) + sizeof(char) * (map_size.x * map_size.y));
	if (!*map_addr)
		return (-1);
	(*map_addr)->total_size = map_size.x * map_size.y;
	(*map_addr)->size.x = map_size.x;
	(*map_addr)->size.y = map_size.y;
	it = file_content->next;
	i = 0;
	while (it != file_content)
	{
		ft_memcpy((*map_addr)->data + i * map_size.x, it->data, map_size.x);
		it = it->next;
		i++;
	}
	gb_pop();
	gb_push(*map_addr, free);
	if (get_map_infos(*map_addr))
		return (-1);
	return (0);
}
