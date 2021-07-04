#include <garbage.h>

int	gb_action_pop(t_gblst **lst_ptr, void *data, t_destructor destructor)
{
	(void)data;
	(void)destructor;
	gblst_pop(lst_ptr);
	return (0);
}
