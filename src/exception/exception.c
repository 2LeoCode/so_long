#include <exception.h>

int	exception(t_exception except)
{
	write(2, "Error\nexception caught: ", 24);
	(*except)();
	return (-1);
}
