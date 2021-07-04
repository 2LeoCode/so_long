#include <garbage.h>

int	gb_push(void *data, t_destructor destructor)
{
	return (garbage(data, destructor, push));
}
