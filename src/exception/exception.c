#include <exception.h>
#include <garbage.h>

int	exception(t_exception except)
{
	write(2, "Error\nexception caught: ", 24);
	(*except)();
	gb_clear();
	return (-1);
}
