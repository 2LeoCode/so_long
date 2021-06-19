#include <exception.h>

void	invalid_map(void)
{
	write(2, "invalid_map\n", 12);
}
