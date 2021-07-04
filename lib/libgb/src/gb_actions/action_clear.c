#include <garbage.h>

int	gb_action_clear(t_gblst **lst_ptr, void *data, t_destructor destructor)
{
	(void)data;
	(void)destructor;
	gblst_clear(lst_ptr);
	return (0);
}
