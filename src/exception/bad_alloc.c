#include <exception.h>

void	bad_alloc(void)
{
	write(2, "bad_alloc\n", 10);
}
