#include <garbage.h>

int	gb_action_push(t_gblst **lst_ptr, void *data, t_destructor destructor)
{
	if (gblst_push(lst_ptr, data, destructor))
		return (-1);
	return (0);
}
