#include <exception.h>

void	runtime_error(void)
{
	write(2, "runtime_error\n", 14);
}
