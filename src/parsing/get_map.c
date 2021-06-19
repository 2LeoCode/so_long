#include <so_long.h>

static void	*map_failure(t_map *map)
{
	free(map);
	return (NULL);
}

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

static int	get_map_size(char *path, int *x, int *y)
{
	const int	fd = open(path, O_RDONLY);
	char		*line;
	int			read_ret;
	bool		failure;
	int			len;

	failure = false;
	read_ret = get_next_line(fd, &line);
	if (read_ret == -1)
		return (-1);
	len = ft_strlen(line);
	*x = len;
	if (!is_horizontal_wall(line, len))
		failure = true;
	free(line);
	*y = 1;
	while (read_ret)
	{
		if (failure)
			return (-1);
		read_ret = get_next_line(fd, &line);
		if (read_ret == -1)
			return (-1);
		len = ft_strlen(line);
		if (len != *x || (read_ret && !is_vertical_wall(line, len))
					|| (!read_ret && *line && !is_horizontal_wall(line, len)))
			failure = true;
		(*y)++;
		free(line);
	}
	close(fd);
	return (0);
}

t_map	*get_map(char *path)
{
	int		fd;
	char	*line;
	char	*ptr;
	int		read_ret;
	t_vec2	map_size;
	t_map	*map;

	if (ft_memcmp(path + ft_strlen(path) - 4, ".ber", 4))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	read_ret = get_map_size(path, &map_size.x, &map_size.y);
	if (read_ret == -1)
		return (NULL);
	map = malloc(sizeof(t_map) + (map_size.x * map_size.y) * sizeof(char));
	if (!map)
		return (NULL);
	map->size.x = map_size.x;
	map->size.y = map_size.y;
	map->total_size = map_size.x * map_size.y;
	ft_bzero(map->data, map->total_size);
	ptr = map->data;
	read_ret = 1;
	while (read_ret)
	{
		read_ret = get_next_line(fd, &line);
		if (read_ret == -1)
			return (map_failure(map));
		ft_strcat(map->data, line);
		free(line);
	}
	return (map);
}
