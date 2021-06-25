#include <so_long.h>

static int	get_endian(void)
{
	int		x;
	char	*ptr;

	x = 1;
	ptr = (char *)&x;
	return (!*ptr * ENDIAN_BIG);
}

int	make_color(int r, int g, int b)
{
	static int	endian = -1;

	if (endian == -1)
		endian = get_endian();
	if (endian == ENDIAN_LITTLE)
		return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
	return (((r & 0xff) >> 16) + ((g & 0xff) >> 8) + (b & 0xff));
}
